#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

char jari[6][6];
set<int> uniqueSet; 
int answer;
vector<pair<int, int>> stP;

struct Data
{
	int i = 0, j = 0;
	int mask = 0;
	int yCount = 0;
	vector<pair<int, int>> trail;
	bool chk[6][6] = { false, };
};

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool IsMovable(int a, int b)
{
	return 1 <= a && a <= 5 && 1 <= b && b <= 5;
}

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= 5; j++)
		{
			jari[i][j] = str[j - 1];
			if (str[j - 1] == 'S') stP.emplace_back(make_pair(i, j));
		}
	}

	for(int ix = 0; ix < stP.size(); ix++)
	{
		pair<int, int> st = stP[ix];
		Data stD;
		stD.i = st.first;
		stD.j = st.second;
		stD.trail.push_back({ st });
		stD.chk[stD.i][stD.j] = true;
		
		stD.mask = (1 << ((stD.i - 1) * 5) + stD.j);
		uniqueSet.insert(stD.mask);

		queue<Data> q;
		q.push(stD);

		while (!q.empty())
		{
			Data data = q.front();
			q.pop();

			if (data.yCount >= 4) continue;

			if (data.trail.size() == 7)
			{
				answer++;
				continue;
			}

			for (int i = 0; i < data.trail.size(); ++i)
			{
				int nowI = data.trail[i].first;
				int nowJ = data.trail[i].second;

				for (int d = 0; d < 4; d++)
				{
					int gotoI = nowI + mI[d];
					int gotoJ = nowJ + mJ[d];

					if (!IsMovable(gotoI, gotoJ) || data.chk[gotoI][gotoJ]) continue;
					
					Data pushD = data;
					pushD.i = gotoI;
					pushD.j = gotoJ;
					pushD.trail.push_back({ gotoI,gotoJ });
					pushD.chk[gotoI][gotoJ] = true;
					pushD.mask = data.mask | ((1 << ((gotoI - 1) * 5) + gotoJ));

					if (jari[gotoI][gotoJ] == 'Y')
					{
						pushD.yCount++;
					}

					if (uniqueSet.count(pushD.mask)) continue;

					uniqueSet.insert(pushD.mask);

					q.emplace(pushD);
				}
			}
		}
	}

	cout << answer;
}