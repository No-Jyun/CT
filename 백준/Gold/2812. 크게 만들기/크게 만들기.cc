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

int n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k >> s;
	string result(n - k, '0');
	result[0] = s[0];

	int nowIndex = 0;
	int c = 0;
	for (int i = 1; i < n; i++) {
		if (c >= k) {
			result[++nowIndex] = s[i];
		}
		else {
			while (nowIndex != -1 && result[nowIndex] < s[i] && c < k) {
				nowIndex--;
				c++;
			}
			result[++nowIndex] = s[i];
		}
	}

	cout << result;
}