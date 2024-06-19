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

int n;
string first[1001];
int second[1001];
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> first[i];
	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= n; j++) {
			if (first[j] == tmp) {
				second[j] = i;
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (second[i] < second[j]) { result++; break; }
		}
	}

	cout << result;
}