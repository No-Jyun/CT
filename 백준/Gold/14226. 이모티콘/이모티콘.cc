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

int s;
int chk[1001][1001];

bool Range(int a) {
	return a >= 0 && a <= 1000;
}

int BFS() {
	queue<vector<int>> q;
	chk[1][0] = 1;
	q.push({ 1,0,0 });		// 현재 갯수, 복사 수, 시간

	while (!q.empty()) {
		int nowN = q.front()[0];
		int nowC = q.front()[1];
		int nowT = q.front()[2];
		q.pop();

		if (nowN == s)return nowT;

		int tmpN = nowN + nowC;
		if (Range(tmpN) && !chk[tmpN][nowC]) {
			chk[tmpN][nowC] = 1;
			q.push({ tmpN,nowC,nowT + 1 });
		}

		if (!chk[nowN][nowN]) {
			chk[nowN][nowN] = 1;
			q.push({ nowN,nowN,nowT + 1 });
		}

		if (Range(nowN - 1) && !chk[nowN - 1][nowC]) {
			chk[nowN - 1][nowC] = 1;
			q.push({ nowN - 1,nowC,nowT + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	cout << BFS();
}