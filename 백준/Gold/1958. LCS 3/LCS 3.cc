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
#define INTMAX 2147483647
using namespace std;

string a, b, c;
int mlen;
int arr[101][101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			for (int k = 1; k <= c.length(); k++) {
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) {
					arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
				}
				else arr[i][j][k] = max(arr[i - 1][j][k],
					max(arr[i][j - 1][k], arr[i][j][k - 1]));

				mlen = max(mlen, arr[i][j][k]);
			}
		}
	}

	cout << mlen;
}