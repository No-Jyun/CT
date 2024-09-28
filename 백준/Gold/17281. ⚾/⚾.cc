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

int n;
ULL result;
int bat[10][51];
int order[10];
bool chk[10];

void Cal() {
	int e_ning = 1;
	int nowIndex = 1;
	ULL nowResult = 0;

	while (e_ning <= n) {
		bool ru[4] = { 0, };
		int outCount = 0;

		while (outCount < 3) {
			int nowBat = bat[order[nowIndex]][e_ning];

			switch (nowBat)
			{
			case 1:
				if (ru[3])nowResult++;
				ru[3] = ru[2]; ru[2] = ru[1];
				ru[1] = 1;
				break;
			case 2:
				if (ru[3])nowResult++;
				if (ru[2])nowResult++;
				ru[3] = ru[1]; ru[2] = 1;
				ru[1] = 0;
				break;
			case 3:
				nowResult += count(ru, ru + 4, 1);
				ru[3] = 1; ru[2] = 0;
				ru[1] = 0;
				break;
			case 4:
				nowResult += count(ru, ru + 4, 1) + 1;
				ru[3] = 0; ru[2] = 0;
				ru[1] = 0;
				break;
			default:
				outCount++;
				break;
			}
			nowIndex++;
			if (nowIndex == 10)nowIndex = 1;
		}
		e_ning++;
	}
	result = max(result, nowResult);
}

void DicideOrder(int index) {
	if (index == 4) return DicideOrder(5);
	if (index == 10)return Cal();

	for (int i = 2; i <= 9; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			order[index] = i;
			DicideOrder(index + 1);
			chk[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++)cin >> bat[j][i];
	}
	order[4] = 1;
	chk[1] = 1;

	DicideOrder(1);
	cout << result;
}