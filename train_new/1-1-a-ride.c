/*
LANG: C
PROG: ride
*/

#include <stdio.h>

int f(const char *s)
{
	int product = 1;
	for(const char *p = s; *p; ++p)
		product *= *p - 'A' + 1;
	return product % 47;
}

int main()
{
	FILE *fin  = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	char a[6+1], b[6+1];
	fscanf(fin, "%6s %6s", a, b);
	fputs(f(a) == f(b) ? "GO\n" : "STAY\n", fout);
}
