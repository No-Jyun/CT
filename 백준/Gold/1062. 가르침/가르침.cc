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
string arr[51];
bool tmpC[51][26];
int alpha[26];
int result;

void Cal() {
	int t = 0;
	for (int i = 1; i <= n; i++) {
		bool isOk = true;
		for (int j = 0; j < 26 && isOk; j++) {
			if (tmpC[i][j] && !alpha[j])isOk = false;
		}
		if (isOk)t++;
	}
	result = max(result, t);
}

void Choose(int remain, int index) {
	if (!remain) {
		Cal();
		return;
	}

	for (int i = index + 1; i < 26; i++) {
		if (!alpha[i]) {
			alpha[i] = 1;
			Choose(remain - 1, i);
			alpha[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	
	if (k < 5) {
		cout << 0;
		return 0;
	}
	k -= 5;
	alpha[0] = 1;
	alpha[(int)'n' - (int)'a'] = 1;
	alpha[(int)'t' - (int)'a'] = 1;
	alpha[(int)'i' - (int)'a'] = 1;
	alpha[(int)'c' - (int)'a'] = 1;

	for (int i = 1; i <= n; i++) {
		string ns = arr[i];
		for (int j = 0; j < ns.length(); j++)tmpC[i][ns[j] - 'a'] = 1;
	}

	Choose(k, 0);

	cout << result;
}