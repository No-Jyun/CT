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

int n, l, r;
int nation[51][51];
int chk[51][51];
pair<int, int> chkedNation[3000];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= n;
}

bool MoveNation() {
	fill(chk[0], chk[51], 0);
	int chkIndex = 1;
	vector<vector<int>> unionList;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!chk[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				chk[i][j] = 1;
				vector<int> tmp;

				while (!q.empty()) {
					int nowI = q.front().first;
					int nowJ = q.front().second;
					int d = 0;
					q.pop();

					tmp.push_back(chkIndex);
					chkedNation[chkIndex++] = { nowI,nowJ };

					while (d < 4) {
						int tmpI = nowI + mI[d];
						int tmpJ = nowJ + mJ[d];

						if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ]) {
							int num = abs(nation[nowI][nowJ] - nation[tmpI][tmpJ]);
							if (num >= l && num <= r) {
								q.push({ tmpI,tmpJ });
								chk[tmpI][tmpJ] = 1;
							}
						}
						d++;
					}
				}
				if (tmp.size() > 1)unionList.push_back(tmp);
			}
		}
	}

	if (unionList.empty())return false;
	
	for (int i = 0; i < unionList.size(); i++) {
		int sum = 0;
		for (int j = 0; j < unionList[i].size(); j++) sum += nation[chkedNation[unionList[i][j]].first][chkedNation[unionList[i][j]].second];
		sum /= unionList[i].size();
		for (int j = 0; j < unionList[i].size(); j++) nation[chkedNation[unionList[i][j]].first][chkedNation[unionList[i][j]].second] = sum;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)cin >> nation[i][j];
	}

	int t = 0;
	while (MoveNation()) {
		t++;
	}

	cout << t;
}