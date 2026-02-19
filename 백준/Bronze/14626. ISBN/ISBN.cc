#include <iostream>

using namespace std;

int check[14];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		check[i + 1] = str[i] - '0';

		if (str[i] == '*') check[i + 1] = -1;
	}
	
	if (check[13] == -1)
	{
		int sum = 0;
		for (int i = 1; i <= 12; i++)
		{
			int mulN = i % 2 == 0 ? 3 : 1;
			sum += check[i] * mulN;
		}
		sum %= 10;

		cout << 10 - sum;
		return 0;
	}
	else
	{
		int sum = 0;
		int findMul = 0;
		for (int i = 1; i <= 12; i++)
		{
			int mulN = i % 2 == 0 ? 3 : 1;

			if (check[i] == -1)
			{
				findMul = mulN;
				continue;
			}

			sum += check[i] * mulN;
		}

		sum += check[13];

		for (int i = 0; i <= 9; i++)
		{
			int tmp = sum;
			tmp += i * findMul;

			tmp %= 10;

			if (tmp == 0)
			{
				cout << i;
				return 0;
			}
		}
	}
}
