#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct horse {
	int r = 0;
	int c = 0;
	int order = 0;
	int dir = 0;
}people[10];

int n, k;
int room[14][14];
string onBoard[14][14];

vector<pair<int, int>> movedCorOnTurn;

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

int answer = 0;

int DirControl(int d) {
	switch (d)
	{
	case 0: return 2;
	case 1: return 3;
	case 2: return 0;
	case 3: return 1;
	}
}

void MovePeopleOnWhite(int nowK, int toI, int toJ)
{
	movedCorOnTurn.push_back({ toI,toJ });

	int orI = people[nowK].r;
	int orJ = people[nowK].c;
	int orO = people[nowK].order;
	string orS = onBoard[orI][orJ];
	string onMyUpper = orS.substr(orO);
	if (orS.size() == onMyUpper.size())
	{
		onBoard[orI][orJ] = "";
	}
	else 
	{
		orS = orS.substr(0, orS.size() - onMyUpper.size());
		onBoard[orI][orJ] = orS;
	}
	
	string toBoard = onBoard[toI][toJ];
	int toOLen = toBoard.size();
	onBoard[toI][toJ] = toBoard + onMyUpper;

	for (int i = 0; i < onMyUpper.size(); i++)
	{
		int movedPI = onMyUpper[i] - '0';
		int movedOrder = i + toOLen;
		people[movedPI].r = toI;
		people[movedPI].c = toJ;
		people[movedPI].order = movedOrder;
	}
	//cout << "Turn : " << answer << " / num : " << nowK << "\n";
	//cout << "before r,c : " << orI << " " << orJ << " / orString : " << orS << "\n";
	//cout << "after r,c : " << toI << " " << toJ << " / movedString : " << onBoard[toI][toJ] << "\n\n";
}

void MovePeopleOnRed(int nowK, int toI, int toJ)
{
	movedCorOnTurn.push_back({ toI,toJ });

	int orI = people[nowK].r;
	int orJ = people[nowK].c;
	int orO = people[nowK].order;
	string orS = onBoard[orI][orJ];
	string onMyUpper = onBoard[orI][orJ].substr(orO);
	if (orS.size() == onMyUpper.size())
	{
		onBoard[orI][orJ] = "";
	}
	else
	{
		orS = orS.substr(0, orS.size() - onMyUpper.size());
		onBoard[orI][orJ] = orS;
	}

	reverse(onMyUpper.begin(), onMyUpper.end());
	string toBoard = onBoard[toI][toJ];
	int toOLen = toBoard.size();
	onBoard[toI][toJ] = toBoard + onMyUpper;

	for (int i = 0; i < onMyUpper.size(); i++)
	{
		int movedPI = onMyUpper[i] - '0';
		int movedOrder = i + toOLen;
		people[movedPI].r = toI;
		people[movedPI].c = toJ;
		people[movedPI].order = movedOrder;
	}
	//cout << "Turn : " << answer << " / num : " << nowK << "\n";
	//cout << "before r,c : " << orI << " " << orJ << " / orString : " << orS << "\n";
	//cout << "after r,c : " << toI << " " << toJ << " / movedString : " << onBoard[toI][toJ] << "\n\n";
}

void MovePeopleOnBlue(int nowK)
{
	people[nowK].dir = DirControl(people[nowK].dir);

	int toI = people[nowK].r + mI[people[nowK].dir];
	int toJ = people[nowK].c + mJ[people[nowK].dir];

	switch (room[toI][toJ])
	{
	case 0:
		MovePeopleOnWhite(nowK, toI, toJ);
		break;
	case 1:
		MovePeopleOnRed(nowK, toI, toJ);
		break;
	case 2:
		movedCorOnTurn.push_back({ people[nowK].r, people[nowK].c });
		break;
	}
}

void StartTurn()
{
	while (answer < 1000)
	{
		answer++;
		movedCorOnTurn.clear();

		for (int i = 0; i < k; i++)
		{
			int toI = people[i].r + mI[people[i].dir];
			int toJ = people[i].c + mJ[people[i].dir];

			switch (room[toI][toJ])
			{
			case 0:
				MovePeopleOnWhite(i, toI, toJ);
				break;
			case 1:
				MovePeopleOnRed(i, toI, toJ);
				break;
			case 2:
				MovePeopleOnBlue(i);
				break;
			}

			// 종료조건 탐색 (말이 4개 이상 쌓였는지)
			for (auto cor : movedCorOnTurn)
			{
				if (onBoard[cor.first][cor.second].size() >= 4)
					return;
			}
		}
	}
}

void InSetting()
{
	cin >> n >> k;
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (i == 0 || j == 0 || i >= n + 1 || j >= n + 1)
			{
				room[i][j] = 2;
			}
			else
			{
				cin >> room[i][j];
			}

			onBoard[i][j] = "";
		}
	}

	for (int i = 0; i < k; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		people[i].r = a;
		people[i].c = b;
		onBoard[a][b] = to_string(i);

		if (c == 1)people[i].dir = 1;
		if (c == 2)people[i].dir = 3;
		if (c == 3)people[i].dir = 0;
		if (c == 4)people[i].dir = 2;
	}
}

void StartSolve()
{
	InSetting();
	StartTurn();
}

int main()
{
	StartSolve();

	if (answer >= 1000) cout << -1;
	else cout << answer;
}