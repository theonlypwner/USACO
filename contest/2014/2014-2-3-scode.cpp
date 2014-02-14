#include <iostream>
#include <fstream>

#define loopi(x) loop_start(i,x,0)
#define loopj(x) loop_start(j,x,0)
#define loop_start(i,x,s) for(int i = (s); i < (x); ++i)
#define loop_rev(a,x,stop) for(int a = (x); a >= (stop); --a)

using namespace std;

inline bool is_repeated(const char *str1, const char *str2, size_t len)
{
	// There are no NULL characters to worry about
	return !strncmp(str1, str2, len);
	/*
	// old code:
	while(len--)
		if(*str1++ != *str2++)
			return false;
	return true;
	*/
}

/*
(s = F_L) may become:

Drop L: F_ + s or s + F_
Drop F: _L + s or s + _L

F_F_L
F_LF_
_LF_L
F_L_L

But F_ or _L cannot be distinguished, so
A_A_L
A_LA_
A_FA_
FA_A_

F and L cannot be distinguished either, so
A_A_B
BA_A_
A_BA_ (x2)
*/
int sources(char *start, size_t sz)
{
	/*
	1. Any string of length L will be encrypted to length (2L-1),
	   which is always (even-1), which is odd.
	2. A string of length two is in minimal form.
	*/
	if((sz & 1) == 0 || sz <= 2)
		return 0;
	int ret = 0;
	const int sublen = (sz - 1) >> 1; // length of A_
	// A_A_B
	if(is_repeated(start, start + sublen, sublen))
		// A_B plus anything formed by that
		ret += 1 + sources(start + sublen, sublen + 1);
	// BA_A_
	if(is_repeated(start + 1, start + 1 + sublen, sublen))
		// BA_ and A_B should be equivalent
		ret += 1 + sources(start, sublen + 1);
	// A_BA_ (x2)
	if(is_repeated(start, start + 1 + sublen, sublen))
		// 2 * (A_B + anything formed by that)
		ret += (1 + sources(start, sublen + 1)) << 1;
	return ret;
}

int main()
{
	ofstream fout ("scode.out");
	ifstream fin ("scode.in");
	// Read input
	static char str[100+1];
	fin >> str;
	// Calculate output
	int ret = sources(str, strlen(str));
	fout << ret << endl;
	return 0;
}
