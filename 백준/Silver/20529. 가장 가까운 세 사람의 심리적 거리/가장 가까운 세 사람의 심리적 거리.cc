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
int chk[16];
int indexArr[3];
int result = 2000000000;
bool flag;

void Input(string s, int index) {
	int tmp = 0;
	for (int i = 0; i < 4; i++) {
		if (s[i] == 'E' || s[i] == 'S' ||
			s[i] == 'T' || s[i] == 'J')tmp += pow(2, i);
	}
	chk[tmp]++;

	if (chk[tmp] == 3)flag = true;
}

void Cal() {
	int tmp = 0;

	int tmpResult = indexArr[0] ^ indexArr[1];
	int score = 0;
	while (tmpResult) {
		score += tmpResult % 2;
		tmpResult /= 2;
	}
	tmp += score;

	tmpResult = indexArr[0] ^ indexArr[2];
	score = 0;
	while (tmpResult) {
		score += tmpResult % 2;
		tmpResult /= 2;
	}
	tmp += score;

	tmpResult = indexArr[2] ^ indexArr[1];
	score = 0;
	while (tmpResult) {
		score += tmpResult % 2;
		tmpResult /= 2;
	}
	tmp += score;
	result = min(result, tmp);
}

void Start(int index, int indexI) {
	if (indexI == 3) Cal();
	else {
		for (int i = index; i < 16; i++) {
			if (chk[i]) {
				chk[i]--;
				indexArr[indexI] = i;
				Start(i, indexI + 1);
				chk[i]++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			Input(s, i);
		}

		if (flag) result = 0;
		else {
			Start(0, 0);
		}

		cout << result << '\n';
		result = 2000000000;
		fill(chk, chk + 16, 0);
		flag = false;
	}
}