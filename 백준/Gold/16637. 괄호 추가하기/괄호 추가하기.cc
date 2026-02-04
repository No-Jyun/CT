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

int n, operNum;
string str;
int v[10];
LL maxN = -999999999999;

bool IsNum(char c)
{
	return '0' <= c && c <= '9';
}

LL CalTwo(LL t1, LL t2, char op)
{
	switch (op)
	{
	case '+':
		return t1 + t2;
	case '-':
		return t1 - t2;
	case '*':
		return t1 * t2;
	}
}

void Cal()
{
	int vIndex = 0;
	deque<LL> num;
	deque<char> oper;

	for (int i = 0; i < n; i++)
	{
		char c = str[i];
		if (IsNum(c))
		{
			num.emplace_back(c - '0');
		}
		else
		{
			if (i == v[vIndex])
			{
				// 가장 뒤의 수 빼고
				LL t1 = num.back();
				num.pop_back();
				// str의 다음 수도 빼고
				int t2 = str[++i] - '0';
				// 현재 연산자와 계산
				t1 = CalTwo(t1, t2, c);
				// num의 가장 끝에 넣기
				num.emplace_back(t1);

				vIndex++;
			}
			else
			{
				oper.emplace_back(c);
			}
		}
	}

	LL base = num.front();
	num.pop_front();
	while (!oper.empty())
	{
		LL t = num.front();
		num.pop_front();
		char c = oper.front();
		oper.pop_front();

		base = CalTwo(base, t, c);
	}

	if (base > maxN) maxN = base;
}

void Choose(int chooseNum, int index)
{
	if (chooseNum == index)
	{
		Cal();
		return;
	}

	int nowIndex = index == 0 ? 0 : v[index - 1] + 1;

	for (; nowIndex < str.size(); nowIndex++)
	{
		if (IsNum(str[nowIndex]))
			continue;

		if (index == 0)
		{
			v[index] = nowIndex;
			Choose(chooseNum, index + 1);
		}
		else
		{
			int exI = v[index - 1];
			if (nowIndex - exI == 2)
				continue;

			v[index] = nowIndex;
			Choose(chooseNum, index + 1);
		}
	}
}

LL StartSolve()
{
	cin >> str;

	for (int i = 0; i < n; i++)
	{
		if (!IsNum(str[i])) operNum++;
	}

	operNum = operNum % 2 == 1 ? (operNum / 2) + 1 : (operNum / 2);

	for (int i = 0; i <= operNum; i++)
	{
		fill(v, v + 10, -1);
		Choose(i, 0);
	}

	return maxN;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cout << StartSolve();
}