#include <iostream>
#include <vector>

using namespace std;

int arr[50][50];
int spinSeq[6];
bool selectedSpin[6];
int n, m, k;
int answer = 999999999;

struct Spin {
	int r = 0;
	int c = 0;
	int s = 0;

	Spin() {}
	Spin(int r, int c, int s)
		: r(r), c(c), s(s)
	{
	}
}spinArr[6];

// spin 연산
void SpinOperate()
{
	int arrCopy[50][50];
	for (int i = 0; i < n; i++)
	{
		for(int j =0;j<m;j++)
		{
			arrCopy[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		Spin curSpin = spinArr[spinSeq[i]];

		while (curSpin.s >= 1)
		{
			int stR = curSpin.r - curSpin.s;
			int endR = curSpin.r + curSpin.s;
			int stC = curSpin.c - curSpin.s;
			int endC = curSpin.c + curSpin.s;
			
			int exVal = arrCopy[stR][stC];
			for (int c = stC + 1; c <= endC; c++)
			{
				swap(exVal, arrCopy[stR][c]);
			}
			for (int r = stR + 1; r <= endR; r++)
			{
				swap(exVal, arrCopy[r][endC]);
			}
			for (int c = endC - 1; c >= stC; c--)
			{
				swap(exVal, arrCopy[endR][c]);
			}
			for (int r = endR - 1; r >= stR; r--)
			{
				swap(exVal, arrCopy[r][stC]);
			}

			curSpin.s--;
		}
	}

	// 배열 크기 구하기
	int minV = 999999999;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += arrCopy[i][j];
		}
		minV = minV > sum ? sum : minV;
	}
	answer = answer > minV ? minV : answer;
}

// spin 순서 선택
void SelectSeq(int curIndex)
{
	if (curIndex >= k)
	{
		SpinOperate();
		return;
	}

	for (int i = 0; i < k; i++)
	{
		if (selectedSpin[i]) continue;

		selectedSpin[i] = true;
		spinSeq[curIndex] = i;
		SelectSeq(curIndex + 1);
		selectedSpin[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int r, c, s;
		cin >> r >> c >> s;
		spinArr[i] = Spin(r - 1, c - 1, s);
	}

	for (int i = 0; i < k; i++)
	{
		selectedSpin[i] = true;
		spinSeq[0] = i;
		SelectSeq(1);
		selectedSpin[i] = false;
	}

	cout << answer;
}