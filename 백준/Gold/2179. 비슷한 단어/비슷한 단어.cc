#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int n;
unordered_map<string, vector<int>> m;
vector<string> origin;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		origin.emplace_back(str);

		for (int j = 1; j <= str.size(); j++)
		{
			//cout << str.substr(0, j) << ' ';
			m[str.substr(0, j)].emplace_back(i);
		}
		//cout << "\n";
	}

	int maxS = 0;
	int first = 0;
	int second = 0;
	for (auto it : m)
	{
		int curPreStrSize = it.first.size();
		int curStrNum = it.second.size();

		if (curStrNum <= 1)
			continue;

		if (maxS < curPreStrSize)
		{
			maxS = curPreStrSize;
			first = it.second[0];
			second = it.second[1];
		}
		else if (maxS == curPreStrSize)
		{
			int semiF = it.second[0];
			int semiS = it.second[1];

			if (semiF < first)
			{
				first = semiF;
				second = semiS;
			}
		}
	}
	
	cout << origin[first] << "\n" << origin[second];
}
