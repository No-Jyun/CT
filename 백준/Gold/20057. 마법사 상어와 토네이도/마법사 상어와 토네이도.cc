#include <iostream>
#include <queue>

using namespace std;

int n, answer;
int sand[500][500];

struct Data
{
	// i, j, dir : 현재 좌표 및 방향
	// targetMovedC : 현재 방향을 유지한채 이동해야하는 칸 수
	// dirMovedC : 현재 방향을 유지한채 이동한 칸 수
	// IncreaseC : 이동해야하는 칸 수를 증가시키기 위한 Count
	int i, j, dir, targetMovedC, dirMovedC, increaseC;
};

struct SandState 
{
	int i, j;
	float ratio;
};

struct SandDir
{
	SandState state[10];
}sandDir[4];

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

SandDir GetStateRotated(int dir)
{
	// 위 방향
	SandDir base;
	base.state[0].i = 0;
	base.state[0].j = -1;
	base.state[0].ratio = 0.01f;

	base.state[1].i = 0;
	base.state[1].j = 1;
	base.state[1].ratio = 0.01f;

	base.state[2].i = -1;
	base.state[2].j = -1;
	base.state[2].ratio = 0.07f;

	base.state[3].i = -1;
	base.state[3].j = 1;
	base.state[3].ratio = 0.07f;

	base.state[4].i = -1;
	base.state[4].j = -2;
	base.state[4].ratio = 0.02f;

	base.state[5].i = -1;
	base.state[5].j = 2;
	base.state[5].ratio = 0.02f;

	base.state[6].i = -2;
	base.state[6].j = -1;
	base.state[6].ratio = 0.1f;

	base.state[7].i = -2;
	base.state[7].j = 1;
	base.state[7].ratio = 0.1f;

	base.state[8].i = -3;
	base.state[8].j = 0;
	base.state[8].ratio = 0.05f;

	base.state[9].i = -2;
	base.state[9].j = 0;
	base.state[9].ratio = 1.0f;

	bool isSwap = false;
	int flipI = 1;
	int flipJ = 1;

	// 0번 위 방향
	// (-2, 1)
	// 1번 왼쪽 방향
	// (1, 2)
	// 2번 아래 방향
	// (2, -1)
	// 3번 오른쪽 방향
	// (-1, -2)
	switch (dir)
	{
	case 0:
		return base;
	case 1:
		flipI = -1;
		isSwap = true;
		break;
	case 2:
		flipI = -1;
		flipJ = -1;
		break;
	case 3:
		flipJ = -1;
		isSwap = true;
		break;
	}

	SandDir out;
	for (int i = 0; i < 10; i++)
	{
		out.state[i].i = base.state[i].i * flipI;
		out.state[i].j = base.state[i].j * flipJ;
		if (isSwap)
			swap(out.state[i].i, out.state[i].j);

		out.state[i].ratio = base.state[i].ratio;
	}
	return out;
}

void SetSandDir()
{
	for (int i = 0; i < 4; i++)
		sandDir[i] = GetStateRotated(i);	
}

bool IsMoveable(int a, int b)
{
	return 1 <= a && a <= n && 1 <= b && b <= n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> sand[i][j];

	SetSandDir();

	int stI = n / 2 + 1;

	Data stD;
	queue<Data> q;
	q.push({ stI,stI,3,1,0,0 });

	while (!q.empty())
	{
		Data data = q.front();
		q.pop();

		int nowI = data.i;
		int nowJ = data.j;
		int nowD = data.dir;

		if (nowI == 1 && nowJ == 1) break;

		int gotoI = nowI + mI[nowD];
		int gotoJ = nowJ + mJ[nowD];
		int gotoSand = sand[gotoI][gotoJ];

		for (int i = 0; i < 10; i++)
		{
			int sandI = nowI + sandDir[nowD].state[i].i;
			int sandJ = nowJ + sandDir[nowD].state[i].j;
			int sandAmount = (int)(gotoSand * sandDir[nowD].state[i].ratio);

			if (i == 9)
			{
				sandAmount = sand[gotoI][gotoJ];
				sand[gotoI][gotoJ] = 0;
			}
			else
			{
				sand[gotoI][gotoJ] -= sandAmount;
			}

			if (IsMoveable(sandI, sandJ))
			{
				sand[sandI][sandJ] += sandAmount;
			}
			else
			{
				answer += sandAmount;
			}
		}

		// i, j, dir : 현재 좌표 및 방향
		// targetMovedC : 현재 방향을 유지한채 이동해야하는 칸 수
		// dirMovedC : 현재 방향을 유지한채 이동한 칸 수
		// IncreaseC : 이동해야하는 칸 수를 증가시키기 위한 Count

		int nextD = nowD;
		int nextDMC = data.dirMovedC + 1;
		int nextTMC = data.targetMovedC;
		int nextIC = data.increaseC;

		// 현재 방향을 유지한채 목표 칸 수만큼 가면
		if (nextDMC == nextTMC)
		{
			// 방향 변경
			nextD = nextD - 1 == -1 ? 3 : nowD - 1;
			// 간 칸 수 초기화
			nextDMC = 0;

			// 꺾은 횟수 증가
			nextIC++;

			if (nextIC == 2)
			{
				nextIC = 0;
				nextTMC++;
			}
		}

		q.push({ gotoI,gotoJ,nextD,nextTMC,nextDMC,nextIC });
	}

	cout << answer;
}