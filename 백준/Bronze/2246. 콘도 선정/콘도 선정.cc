#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n;
int dist[10001];
int money[10001];
int result;

bool Cond1(int i) {
	int nowD = dist[i];
	int nowM = money[i];

	int c1 = 0;
	int c2 = 0;
	for (int j = 1; j <= n; j++) {
		int thatD = dist[j];
		int thatM = money[j];

		if (nowD > thatD) {
			c1++;
			if (nowM < thatM)c2++;
		}
	}
	return c1 == c2;
}

bool Cond2(int i) {
	int nowD = dist[i];
	int nowM = money[i];

	int c1 = 0;
	int c2 = 0;
	for (int j = 1; j <= n; j++) {
		int thatD = dist[j];
		int thatM = money[j];

		if (nowM > thatM) {
			c1++;
			if (nowD < thatD)c2++;
		}
	}
	return c1 == c2;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> dist[i] >> money[i];
	}

	for (int i = 1; i <= n; i++) {
		if (Cond1(i) && Cond2(i)) result++;
	}

	cout << result;
}