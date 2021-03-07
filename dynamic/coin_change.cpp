#include <bits/stdc++.h>
using namespace std;

/*
 	 coins = {1, 2, 3},  amount = 4;
	
		0	1	2	3	4
	0	0	0	0	0	0
	1	1	1	1	1	1
	2	1	1	2	2	3
	3	1	1	2	3	4

	return result[i][j]

	exclude -> x = t[i-1][j]
	include -> y = t[i][j - coins[i-1]]

	result -> x+y
*/

int coin_change(vector<int>& coins, int amt) {
	int result[coins.size()+1][amt+1], i, j;

	for (i = 0; i <= coins.size(); i++) {
		for (j = 0; j <= amt; j++) {
			if (i == 0)
				result[i][j] = 0;

			else if (j == 0)
				result[i][j] = 1;

			else if (coins[i-1] > j)
				result[i][j] = result[i-1][j];

			else
				result[i][j] = result[i-1][j] + result[i][j-coins[i-1]]; 
		}
	}

	return result[coins.size()][amt];
}


int main() {
	vector<int> coins{1, 2, 3};
	int amount = 4;

	cout << coin_change(coins,amount);
	
	return 0;
}
