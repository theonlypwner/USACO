#include <iostream>
#include <fstream>

using namespace std;

// because lookup is faster than computing
short square_table[] = {
	0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100,
	121, 144, 169, 196, 225, 256, 289, 324, 361, 400,
	441, 484, 529, 576, 625, 676, 729, 784, 841, 900,
	961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600,
	1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304, 2401, 2500,
	2601, 2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600,
	3721, 3844, 3969, 4096, 4225, 4356, 4489, 4624, 4761, 4900,
	5041, 5184, 5329, 5476, 5625, 5776, 5929, 6084, 6241, 6400,
	6561, 6724, 6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100,
	8281, 8464, 8649, 8836, 9025, 9216, 9409, 9604, 9801, 10000
};

int main() {
	ofstream fout ("skidesign.out");
	ifstream fin ("skidesign.in");
	// Read input
	short N; // [1, 1000]
	fin >> N;
	short hills_at_elevation[101] = {0}; 
	short min = 100, max = 0;
	for(short i = 0; i < N; ++i){
		short H; // [0, 100]
		fin >> H;
		// Add hill to counter
		++hills_at_elevation[H];
		// Check min/max
		if(H < min)
			min = H;
		if(H > max)
			max = H;
	}
	// Calculate output
	if(max <= 17 + min) // max - min <= 17
		fout << 0 << endl; // Special case: no adjustment is needed
	else{
		int best_price = 3444500; // 500 * (100 - 0 - 17) ^ 2 -- only half of 1000 will be adjusted by 83
		short low = min, high = min + 17, low_max = max - 17;
		for(short low = min; low <= low_max; ++low, ++high){ // up to O(N) but no more than 83
			int price = 0;
			// Add cost below this part
			for(char i = low - 1; i >= 0; --i) // up to O(N^2) but no more than 83
				if(hills_at_elevation[i])
					price += hills_at_elevation[i] * square_table[low - i];
			// Add cost above this part
			for(char i = high + 1; i <= 100; ++i) // up to O(N^2) but no more than 83
				if(hills_at_elevation[i])
					price += hills_at_elevation[i] * square_table[i - high];
			// Check if it is the best price
			if(price < best_price)
				best_price = price;
		}
		// O(N^2) but no more than 83 * (83 + 83) = 13778
		fout << best_price << endl;
	}
	return 0;
}