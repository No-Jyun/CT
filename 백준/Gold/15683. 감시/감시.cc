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

int n, m, cctvNum, minim = INTMAX;
vector<pair<int, int>> cctv;
int samu[9][9];
int cctvDir[6] = { 0,4,2,4,4,1 };
vector<pair<int, int>> cctvRange[8][4];

bool Range(int a, int b) {
	return a >= 1 && b >= 1 && a <= n && b <= m;
}

int Chk() {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (samu[i][j] == 0)c++;
	}
	return c;
}

void SettingDown(int index, int dir) {
	pair<int, int> stP = cctv[index];
	int nowCctv = samu[stP.first][stP.second];
	int dir1 = dir, dir2 = dir;
	switch (nowCctv)
	{
	case 1:
		for (int j = 0; j < cctvRange[index][dir - 1].size(); j++) {
			int tmpI = cctvRange[index][dir - 1][j].first;
			int tmpJ = cctvRange[index][dir - 1][j].second;
			samu[tmpI][tmpJ] -= 100;
		}
		break;
	case 2:
		if (dir == 1) {
			for (int j = 0; j < cctvRange[index][0].size(); j++) {
				int tmpI = cctvRange[index][0][j].first;
				int tmpJ = cctvRange[index][0][j].second;
				samu[tmpI][tmpJ] -= 100;
			}
			for (int j = 0; j < cctvRange[index][1].size(); j++) {
				int tmpI = cctvRange[index][1][j].first;
				int tmpJ = cctvRange[index][1][j].second;
				samu[tmpI][tmpJ] -= 100;
			}
		}
		else {
			for (int j = 0; j < cctvRange[index][2].size(); j++) {
				int tmpI = cctvRange[index][2][j].first;
				int tmpJ = cctvRange[index][2][j].second;
				samu[tmpI][tmpJ] -= 100;
			}
			for (int j = 0; j < cctvRange[index][3].size(); j++) {
				int tmpI = cctvRange[index][3][j].first;
				int tmpJ = cctvRange[index][3][j].second;
				samu[tmpI][tmpJ] -= 100;
			}
		}
		break;
	case 3:
		if (dir == 1) {
			dir1 = 0; dir2 = 3;
		}
		if (dir == 2) {
			dir1 = 1; dir2 = 2;
		}
		if (dir == 3) {
			dir1 = 2; dir2 = 0;
		}
		if (dir == 4) {
			dir1 = 3; dir2 = 1;
		}
		for (int j = 0; j < cctvRange[index][dir1].size(); j++) {
			int tmpI = cctvRange[index][dir1][j].first;
			int tmpJ = cctvRange[index][dir1][j].second;
			samu[tmpI][tmpJ] -= 100;
		}
		for (int j = 0; j < cctvRange[index][dir2].size(); j++) {
			int tmpI = cctvRange[index][dir2][j].first;
			int tmpJ = cctvRange[index][dir2][j].second;
			samu[tmpI][tmpJ] -= 100;
		}
		break;
	case 4:
		if (dir == 1) {
			dir1 = 0;
		}
		if (dir == 2) {
			dir1 = 1;
		}
		if (dir == 3) {
			dir1 = 2;
		}
		if (dir == 4) {
			dir1 = 3;
		}
		for (int d = 0; d < 4; d++) {
			if (d != dir1) {
				for (int j = 0; j < cctvRange[index][d].size(); j++) {
					int tmpI = cctvRange[index][d][j].first;
					int tmpJ = cctvRange[index][d][j].second;
					samu[tmpI][tmpJ] -= 100;
				}
			}
		}
		break;
	default:
		for (int d = 0; d < 4; d++) {
			for (int j = 0; j < cctvRange[index][d].size(); j++) {
				int tmpI = cctvRange[index][d][j].first;
				int tmpJ = cctvRange[index][d][j].second;
				samu[tmpI][tmpJ] -= 100;
			}
			break;
		}
	}
}

void SettingUp(int index, int dir) {
	pair<int, int> stP = cctv[index];
	int nowCctv = samu[stP.first][stP.second];
	int dir1 = dir, dir2 = dir;
	switch (nowCctv)
	{
	case 1:
		for (int j = 0; j < cctvRange[index][dir - 1].size(); j++) {
			int tmpI = cctvRange[index][dir - 1][j].first;
			int tmpJ = cctvRange[index][dir - 1][j].second;
			samu[tmpI][tmpJ] += 100;
		}
		break;
	case 2:
		if (dir == 1) {
			for (int j = 0; j < cctvRange[index][0].size(); j++) {
				int tmpI = cctvRange[index][0][j].first;
				int tmpJ = cctvRange[index][0][j].second;
				samu[tmpI][tmpJ] += 100;
			}
			for (int j = 0; j < cctvRange[index][1].size(); j++) {
				int tmpI = cctvRange[index][1][j].first;
				int tmpJ = cctvRange[index][1][j].second;
				samu[tmpI][tmpJ] += 100;
			}
		}
		else {
			for (int j = 0; j < cctvRange[index][2].size(); j++) {
				int tmpI = cctvRange[index][2][j].first;
				int tmpJ = cctvRange[index][2][j].second;
				samu[tmpI][tmpJ] += 100;
			}
			for (int j = 0; j < cctvRange[index][3].size(); j++) {
				int tmpI = cctvRange[index][3][j].first;
				int tmpJ = cctvRange[index][3][j].second;
				samu[tmpI][tmpJ] += 100;
			}
		}
		break;
	case 3:
		if (dir == 1) {
			dir1 = 0; dir2 = 3;
		}
		if (dir == 2) {
			dir1 = 1; dir2 = 2;
		}
		if (dir == 3) {
			dir1 = 2; dir2 = 0;
		}
		if (dir == 4) {
			dir1 = 3; dir2 = 1;
		}
		for (int j = 0; j < cctvRange[index][dir1].size(); j++) {
			int tmpI = cctvRange[index][dir1][j].first;
			int tmpJ = cctvRange[index][dir1][j].second;
			samu[tmpI][tmpJ] += 100;
		}
		for (int j = 0; j < cctvRange[index][dir2].size(); j++) {
			int tmpI = cctvRange[index][dir2][j].first;
			int tmpJ = cctvRange[index][dir2][j].second;
			samu[tmpI][tmpJ] += 100;
		}
		break;
	case 4:
		if (dir == 1) {
			dir1 = 0;
		}
		if (dir == 2) {
			dir1 = 1;
		}
		if (dir == 3) {
			dir1 = 2;
		}
		if (dir == 4) {
			dir1 = 3;
		}
		for (int d = 0; d < 4; d++) {
			if (d != dir1) {
				for (int j = 0; j < cctvRange[index][d].size(); j++) {
					int tmpI = cctvRange[index][d][j].first;
					int tmpJ = cctvRange[index][d][j].second;
					samu[tmpI][tmpJ] += 100;
				}
			}
		}
		break;
	default:
		for (int d = 0; d < 4; d++) {
			for (int j = 0; j < cctvRange[index][d].size(); j++) {
				int tmpI = cctvRange[index][d][j].first;
				int tmpJ = cctvRange[index][d][j].second;
				samu[tmpI][tmpJ] += 100;
			}
		}
		break;
	}
}

void Brute(int index) {
	if (index == cctvNum) {
		minim = min(minim, Chk());
		return;
	}

	for (int i = index; i < cctvNum; i++) {
		int tmpI = cctv[i].first;
		int tmpJ = cctv[i].second;
		for (int j = 1; j <= cctvDir[samu[tmpI][tmpJ]]; j++) {
			SettingUp(i, j);
			Brute(i + 1);
			SettingDown(i, j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> samu[i][j];
			if (samu[i][j] >= 1 && samu[i][j] <= 5)cctv.push_back({ i,j });
		}
	}
	cctvNum = cctv.size();

	for (int i = 0; i < cctvNum; i++) {
		bool dirBlocked[4] = { 0,0,0,0 };
		for (int d = 0; d < 4; d++) {
			for (int j = 1; j <= 8; j++) {
				int tmpI = cctv[i].first;
				int tmpJ = cctv[i].second;
				switch (d)
				{
				case 0:
					tmpI -= j;
					break;
				case 1:
					tmpI += j;
					break;
				case 2:
					tmpJ -= j;
					break;
				default:
					tmpJ += j;
					break;
				}
				if (Range(tmpI, tmpJ) && !dirBlocked[d]) {
					if (samu[tmpI][tmpJ] == 6)dirBlocked[d] = true;
					else if (samu[tmpI][tmpJ] == 0)cctvRange[i][d].push_back({ tmpI,tmpJ });
				}
			}
		}
	}

	Brute(0);
	cout << minim;
}