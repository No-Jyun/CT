#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	if (n == 1)
	{
		cin >> n;
		cout << n;
		return 0;
	}

	priority_queue<int> posQ;
	priority_queue<int, vector<int>, greater<int>> negQ;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a > 0) posQ.emplace(a);
		else negQ.emplace(a);
	}

	int answer = 0;

	while (posQ.size() >= 2)
	{
		int f = posQ.top();	posQ.pop();
		int s = posQ.top(); posQ.pop();

		if (f * s > f + s)
		{
			answer += f * s;
		}
		else
		{
			answer += f;
			posQ.emplace(s);
		}
	}

	while (negQ.size() >= 2)
	{
		int f = negQ.top();	negQ.pop();
		int s = negQ.top(); negQ.pop();

		if (f * s > f + s)
		{
			answer += f * s;
		}
		else
		{
			answer += f;
			negQ.emplace(s);
		}
	}

	if (!posQ.empty())
		answer += posQ.top();

	if (!negQ.empty())
		answer += negQ.top();

	cout << answer;
}
