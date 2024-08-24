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
pair<int, string> word[51];
int sum;

bool Chk(int iA, int iB) {
	string a = word[iA].second;
	string b = word[iB].second;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i])return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		word[i] = { s.length(),s };
	}
	sort(word, word + n + 1);

	for (int i = 1; i <= n; i++) {
		bool isHead = false;

		for (int j = i + 1; j <= n; j++) {
			if (Chk(i, j)) {
				isHead = true;
				break;
			}
		}
		
		if (!isHead)sum++;
	}

	cout << sum;
}