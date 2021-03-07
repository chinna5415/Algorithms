#include <bits/stdc++.h>
using namespace std;

/*
 
		^	c	h	i	n	n	a 
	^	0	0	0	0	0	0	0
	m	0	0	0	0	0	0	0
	a	0	0	0	0	0	0	1
	n	0	0	0	0	1	1	1
	i	0	0	0	1	1	1	1

	if 2 chars equal => 1 + diagonal (1 + result[t-1][j-1])
	not equal => max of { result[i][j-1], result[i-1][j]}

 */

int max(int x, int y) {
	return (x > y) ? x : y;
}

void lcs(string x, string y, int m, int n) {
	int result[m+1][n+1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				result[i][j] = 0;
	
			else if (x[i-1] == y[j-1])
				result[i][j] = 1 + result[i-1][j-1];
			
			else
				result[i][j] = max(result[i][j-1], result[i-1][j]);
		}
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) 
			cout << result[i][j] << "  ";
		cout << endl;
	}

	cout << "\n" <<  result[m][n];
}

int main() {
	string s1 = "mani";
	string s2 = "chinna";

	lcs(s1, s2, s1.size(), s2.size());
	return 0;
}
