#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
#define ULL unsigned long long
using namespace std;

int dp[1001];

int DP(int a) {
	if (!dp[a]) {
		int tmp = a / 2;
		int sum = 0;

		for (int i = 1; i <= tmp; i++) {
			sum += DP(i);
		}
		dp[a] = sum + 1;
	}
	return dp[a];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int n;
	dp[1] = 1;
	dp[2] = 2;

	while (t--) {
		cin >> n;
		cout << DP(n) << '\n';
	}
}
/*
4
1 2
+1+1 = 4

7
1 2 3
+2 + 1 = 6

20
1 2 3 4 5 6 7 8 9 10
+ 10 = 20

1	1
2	2
3	3/2=1  1값 + 1	2
4	4/2=2	1값 + 2값 + 1= 4
5	5/2=2	[1]+[2]+1=4
6	6/3=3	[1]+[2]+[3] +1=6


		if (!dp[n]) {
			int sum = 0;
			for (int i = 1; i <= tmp; i++) {
				sum += dp[i];
			}
			dp[n] = sum + 1;
		}

*/