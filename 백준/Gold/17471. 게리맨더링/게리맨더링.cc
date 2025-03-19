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
#define LL long long
#define INTMAX 2147483647
using namespace std;

int n;
int people[11];
int party[11];
vector<int> edges[11];
int result = INTMAX;

void Cal() {
	int sumA = 0, sumB = 0;
	for (int i = 1; i <= n; i++) {
		if (party[i])sumA += people[i];
		else sumB += people[i];
	}

	result = min(result, abs(sumA - sumB));
}

bool isVal() {
	int stA = 0, stB = 0;
	for (int i = 1; i <= n; i++) {
		if (!stA && party[i])stA = i;
		if (!stB && !party[i])stB = i;
	}

	vector<int> chk(11);
	queue<int> q;
	q.push(stA);
	chk[stA] = 1;
	while (!q.empty()) {
		int nowN = q.front();
		q.pop();

		for (int i = 0; i < edges[nowN].size(); i++) {
			int toN = edges[nowN][i];
			if (party[toN] && !chk[toN]) {
				chk[toN] = 1;
				q.push(toN);
			}
		}
	}

	q.push(stB);
	chk[stB] = -1;
	while (!q.empty()) {
		int nowN = q.front();
		q.pop();

		for (int i = 0; i < edges[nowN].size(); i++) {
			int toN = edges[nowN][i];
			if (!party[toN] && !chk[toN]) {
				chk[toN] = -1;
				q.push(toN);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (party[i] && chk[i] == 1)continue;
		if (!party[i] && chk[i] == -1)continue;
		return false;
	}
	return true;
}

void Comb(int maxN, int nowN, int index) {
	if (maxN < nowN) {
		if (isVal()) {
			Cal();
		}
		return;
	}

	for (int i = index + 1; i <= n; i++) {
		party[i] = 1;
		Comb(maxN, nowN + 1, i);
		party[i] = 0;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> people[i];
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 1; j <= num; j++) {
			int a;
			cin >> a;
			edges[i].push_back(a);
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		Comb(i, 1, 0);
	}

	if (result == INTMAX)
		cout << -1;
	else
		cout << result;
}