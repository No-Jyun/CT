#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, head, lA, rA, lL, rL, weist;
pair<int, int> heartPos;
int body[1002][1002];
vector<pair<int, int>> v;

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

void FindHeart()
{
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		bool isH = true;
		
		for (int d = 0; d < 4; d++)
		{
			int toX = x + mI[d];
			int toY = y + mJ[d];

			if (body[toX][toY] == 0) isH = false;
		}

		if (isH)
		{
			heartPos = { x,y };
			return;
		}
	}
}

void CountParts()
{
	for (int i = 0; i < v.size(); i++)
	{
		int nowI = v[i].first;
		int nowJ = v[i].second;

		if (heartPos == make_pair(nowI, nowJ)) continue;

		if (nowI < heartPos.first)
		{
			head++;
		}
		if (nowI == heartPos.first)
		{
			if (nowJ < heartPos.second) lA++;
			else rA++;
		}
		if (nowI > heartPos.first)
		{
			if (nowJ == heartPos.second) weist++;
			if (nowJ < heartPos.second) lL++;
			if (nowJ > heartPos.second) rL++;
		}
	}
}

void StartSolve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++)
		{
			if (s[j - 1] == '*') 
			{
				v.push_back({ i,j });
				body[i][j] = 1;
			}
		}
	}

	FindHeart();
	CountParts();

	cout << heartPos.first << ' ' << heartPos.second << "\n";
	cout << lA << ' ' << rA << ' ' << weist << ' ' << lL << ' ' << rL;
}

int main()
{
	StartSolve();
}