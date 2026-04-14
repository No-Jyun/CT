#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using LL = long long;
using P = pair<LL, LL>;

int n;

struct Onion
{
	int num = 0;
	int parent = 0;
};

LL GetParent(LL a, Onion* onionArr)
{
	if (onionArr[a].parent == onionArr[a].num)
	{
		return onionArr[a].parent;
	}

	onionArr[a].parent = GetParent(onionArr[a].parent, onionArr);
	return onionArr[a].parent;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	vector<P> x(n);
	vector<P> y(n);
	vector<P> z(n);
	Onion* onionArray = new Onion[n];

	vector<pair<LL, P>> shortestEdges;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i].first >> y[i].first >> z[i].first;
		x[i].second = i; y[i].second = i; z[i].second = i;

		onionArray[i].num = i;
		onionArray[i].parent = i;
	}
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 1; i < n; i++)
	{
		LL length = abs(x[i].first - x[i - 1].first);
		shortestEdges.emplace_back(pair<LL, P>(length, { x[i].second, x[i - 1].second }));

		length = abs(y[i].first - y[i - 1].first);
		shortestEdges.emplace_back(pair<LL, P>(length, { y[i].second, y[i - 1].second }));

		length = abs(z[i].first - z[i - 1].first);
		shortestEdges.emplace_back(pair<LL, P>(length, { z[i].second, z[i - 1].second }));
	}

	sort(shortestEdges.begin(), shortestEdges.end());
	LL answer = 0;

	for (int i = 0; i < shortestEdges.size(); i++)
	{
		LL curLen = shortestEdges[i].first;
		LL a = shortestEdges[i].second.first;
		LL b = shortestEdges[i].second.second;

		// 부모로 치환
		LL parentA = GetParent(a, onionArray);
		LL parentB = GetParent(b, onionArray);

		// 두개의 유니온이 결합되어 있는지 확인
		// 결합이 되어 있다면 패스
		if (parentA == parentB)
		{
			continue;
		}
		// 결합이 안되어 있다면 결합
		else
		{
			answer += curLen;
			onionArray[parentA].parent = parentB;
		}		
	}

	cout << answer;
}