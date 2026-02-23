#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	int n = 0;
	int index = 0;
	while (index < str.size())
	{
		n++;
		string strN = to_string(n);

		for (int i = 0; i < strN.size() && index < str.size(); i++)
		{
			if (strN[i] == str[index])
				index++;
		}
	}

	cout << n;
}
// 0 1