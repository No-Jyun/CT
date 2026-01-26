#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer = 0;
vector<int> v;

int StartSolve()
{
	answer = 0;

	int line[21] = {};
	for (int i = 1; i <= 20; i++)cin >> line[i];

	v.clear();
	v.push_back(line[1]);
	for (int i = 2; i <= 20; i++)
	{
		int nowH = line[i];

		v.push_back(nowH);
		int size = v.size();

		sort(v.begin(), v.end());
		// 몇번째로 들어갔는지 확인

		for (int j = 0; j < size; j++)
		{
			if(v[j] == nowH)
			{
				answer += size - (j + 1);
				break;
			}
		}
	}

	return answer;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << n << " " << StartSolve() << "\n";
	}
}