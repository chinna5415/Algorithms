#include <bits/stdc++.h>
using namespace std;

int max(int x, int y) {
	return (x > y) ? x : y;
}

void zero_one_knapsack(vector<int>& price, vector<int>& wt, int W, int n) {
	int result[n+1][W+1];

	for (int i = 0; i <=n ; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 or j == 0)
				result[i][j] = 0;
			else if (wt[i-1] <= j)
				result[i][j] = max(price[i-1]+result[i-1][j - wt[i-1]], result[i-1][j]);
			else
				result[i][j] = result[i-1][j];
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) 
			cout << result[i][j] << "  ";
		cout << endl;
	}

	cout << "\n profit : " << result[n][W];
}

int main() {
	vector<int> price{1, 2, 5, 6}, weights{2, 3, 4, 5};
	int W = 8, n = 4;

	zero_one_knapsack(price, weights, W, n);
	return 0;
}
