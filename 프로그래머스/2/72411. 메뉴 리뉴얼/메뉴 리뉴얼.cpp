#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include <iostream>

using namespace std;

int maxYoriSize = 0;

int yoriCount[26];
bool isOn[26];
vector<int> comb;

int maxN = 0;
vector<vector<int>> maxNYori;

void Cal(int maxIndex)
{
	int sumOfCount = 0;

	int t = yoriCount[comb[0]];
	for (int i = 0; i < maxIndex; i++)
	{
		t &= yoriCount[comb[i]];
	}

	if (t == 0) return;

	if ((t > 0) && ((t & (t - 1)) == 0)) return;

	do
	{
		if (t % 2 == 1) sumOfCount++;
		t = t >> 1;
	} while (t);

	if (sumOfCount > maxN)
	{
		maxN = sumOfCount;
		vector<vector<int>>().swap(maxNYori);
		maxNYori.emplace_back(comb);
	}
	else if (sumOfCount == maxN)
	{
		maxNYori.emplace_back(comb);
	}

	return;
}

void Choose(int curIndex, int nextIndex, int targetNum)
{
	if (curIndex == targetNum)
	{
		// 계산
		Cal(targetNum);
		return;
	}

	for (int i = nextIndex; i < maxYoriSize; i++)
	{
		if(isOn[i])
		{
			comb[curIndex] = i;
			Choose(curIndex + 1, i + 1, targetNum);
		}
	}
}

vector<string> solution(vector<string> orders, vector<int> course)
{
	vector<string> answer;

	for (int i = 0; i < orders.size(); i++)
	{
		for (int j = 0; j < orders[i].size(); j++)
		{
			int index = orders[i][j] - 'A';
			yoriCount[index] |= 1 << i;
			isOn[index] = true;
			maxYoriSize = max(maxYoriSize, index + 1);
		}
	}

	for (int i = 0; i < course.size(); i++)
	{
		int targetNum = course[i];
		comb.assign(targetNum, -1);
		maxN = 0;
		vector<vector<int>>().swap(maxNYori);

		for (int j = 0; j < maxYoriSize; j++)
		{
			if(isOn[j])
			{
				comb[0] = j;
				Choose(1, j + 1, targetNum);
			}
		}

		for (int j = 0; j < maxNYori.size(); j++)
		{
			string ans;
			for (int k = 0; k < maxNYori[j].size(); k++)
			{
				ans.push_back((char)maxNYori[j][k] + 'A');
			}
			answer.emplace_back(ans);
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}

/*
  1 2 3 4 5 6
A 1 1 0 1 0 1	6
B 1 0 0 0 1 0	1
C 1 1 1 1 1 1	15
D 0 0 1 1 0 0	1
E 0 0 1 1 0 0	1
F 1 0 0 0 1 1	3
G 1 0 0 0 1 1	3
H 0 1 0 0 0 0	0
I 0 0 0 0 0 0	0
J 0 0 0 0 0 0	0


A B C D E F G H I J
1 1 1 0 0 1 1 0
1 0 1 0 0 0 0 0
0 0 1 1 1 0 0 0
1 0 1 1 1 0 0 0
0 1 1 0 0 1 1 0
1 0 1 1 1 0 0 1

4 2 6 3 3 2 2 1


A B C D E . . . X Y Z
1 1 1 1 1       0 0 0
1 1 0 0 0       0 0 0
0 0 1 1 0       0 0 0
1 0 0 1 1       0 0 0
0 0 0 0 0       1 1 1
0 0 0 0 0       1 1 1
1 0 1 1 0       0 0 0 

*/