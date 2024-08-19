#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <tuple>
#include <math.h>
using namespace std;

int n;
int order[401];
pair<int, int> pos[401];
vector<int> favorite[401];
int table[21][21];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

void SetPos(int index) {
	int nowOrder = order[index];

	priority_queue<vector<int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!table[i][j]) {
				int d = 0;
				int favP = 0, nonP = 0;
				while (d < 4) {
					int tmpI = i + mI[d];
					int tmpJ = j + mJ[d];

					if (Range(tmpI, tmpJ)) {
						if (table[tmpI][tmpJ]) {
							for (int k = 0; k < 4; k++) {
								if (table[tmpI][tmpJ] == favorite[nowOrder][k])favP++;
							}
						}
						else nonP++;
					}
					d++;
				}
				q.push({ favP,nonP,-i,-j });
			}
		}
	}
	table[-(q.top()[2])][-(q.top()[3])] = nowOrder;
}

int CheckSatis() {
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int d = 0;
			int favP = 0;
			while (d < 4) {
				int tmpI = i + mI[d];
				int tmpJ = j + mJ[d];

				if (Range(tmpI, tmpJ)) {
					for (int k = 0; k < 4; k++) {
						if (table[tmpI][tmpJ] == favorite[table[i][j]][k])favP++;
					}
				}
				d++;
			}

			if (favP)sum += pow(10, favP - 1);
		}
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n * n; i++) {
		cin >> order[i];

		for (int j = 1; j <= 4; j++) {
			int a;
			cin >> a;
			favorite[order[i]].push_back(a);
		}
	}

	for (int i = 1; i <= n * n; i++) {
		SetPos(i);
	}

	cout << CheckSatis();
}