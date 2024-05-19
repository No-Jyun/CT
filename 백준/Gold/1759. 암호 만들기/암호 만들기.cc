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
using namespace std;

int l, c;
vector<int> arr;
int result[16];

bool Chk() {
	int cons = 0, vowel = 0;
	for (int i = 1; i <= l; i++) {
		char y = result[i];

		if (y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u')vowel++;
		else cons++;
	}
	if ((vowel >= 1) && (cons >= 2))return true;
	else return false;
}

void Print() {
	if (Chk()) {
		for (int i = 1; i <= l; i++) {
			cout << (char)result[i];
		}
		cout << '\n';
	}
}

void Start(int nowI, int resultI) {
	if (resultI > l) { Print(); return; }
	if (nowI > c) return;

	for (int i = nowI; i <= c; i++) {
		result[resultI] = arr[i];
		Start(i + 1, resultI + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;

	arr.push_back(0);
	for (int i = 1; i <= c; i++) {
		char a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	Start(1, 1);
}