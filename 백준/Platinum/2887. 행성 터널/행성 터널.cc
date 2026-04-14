#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using P = pair<int, int>;

int n;
P posX[100000];
P posY[100000];
P posZ[100000];

struct Onion
{
	int num = 0;
	int parent = 0;
}onionArray[100000];

int GetParent(int a, Onion* onionArr)
{
	if (onionArr[a].parent == onionArr[a].num)
	{
		return onionArr[a].parent;
	}

	onionArr[a].parent = GetParent(onionArr[a].parent, onionArr);
	return onionArr[a].parent;
}
// 같은 유니온에 포함된 친구들의 부모를 갱신함
// ex
// 1 -> 2 -> 3 -> 4 이런식으로 연결되어있고,
// 1(num), 2(parent) / 2, 3 / 3, 4 라고 했을때 
// GetParent(1, onionArr)을 호출하면
// 1 != 2 이므로 onionArr[1].parent (현재 2) 자리에 GetParent(2, onionArr) 호출
// 2 != 3 이므로 onionArr[2].parent (현재 3) 자리에 GetParent(3, onionArr) 호출
// 3 != 4 이므로 onionArr[3].parent (현재 4) 자리에 GetParent(4, onionArr) 호출
// 4 == 4 이므로 return onionArr[4].parent (즉, 4) 반환
// onionArr[3].parent 에 4 대입 후 4 반환
// onionArr[2].parent 에 4 대입 후 4 반환
// onionArr[1].parent 에 4 대입 후 4 반환
//

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	vector<pair<int, P>> shortestEdges;

	for (int i = 0; i < n; i++)
	{
		cin >> posX[i].first >> posY[i].first >> posZ[i].first;
		posX[i].second = i; posY[i].second = i; posZ[i].second = i;

		onionArray[i].num = i;
		onionArray[i].parent = i;
	}
	
	std::sort(posX, posX + n);
	std::sort(posY, posY + n);
	std::sort(posZ, posZ + n);

	for (int i = 1; i < n; i++)
	{
		int length = abs(posX[i].first - posX[i - 1].first);
		shortestEdges.emplace_back(pair<int, P>(length, { posX[i].second, posX[i - 1].second }));

		length = abs(posY[i].first - posY[i - 1].first);
		shortestEdges.emplace_back(pair<int, P>(length, { posY[i].second, posY[i - 1].second }));

		length = abs(posZ[i].first - posZ[i - 1].first);
		shortestEdges.emplace_back(pair<int, P>(length, { posZ[i].second, posZ[i - 1].second }));
	}

	std::sort(shortestEdges.begin(), shortestEdges.end());
	int answer = 0;
	int maxEdge = n - 1;
	int curEdge = 0;

	for (int i = 0; i < shortestEdges.size(); i++)
	{
		int curLen = shortestEdges[i].first;
		int a = shortestEdges[i].second.first;
		int b = shortestEdges[i].second.second;

		// 부모로 치환
		int parentA = GetParent(a, onionArray);
		int parentB = GetParent(b, onionArray);

		// 두개의 유니온이 결합되어 있는지 확인
		// 결합이 되어 있다면 패스
		if (parentA == parentB)
		{
			continue;
		}
		// 결합이 안되어 있다면 결합
		else
		{
			curEdge++;
			answer += curLen;
			onionArray[parentA].parent = parentB;
		}

		if (curEdge >= maxEdge) break;
	}

	cout << answer;
}