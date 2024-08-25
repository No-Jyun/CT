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
using namespace std;

int v, e;
vector<pair<int, pair<int, int>>> edges;
int sum;

struct onion {
	int parentIndex;
	vector<int> memberIndex;
	onion() { parentIndex = -1; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	onion members[10001];

	for (int i = 1; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		members[a].parentIndex = a;
		members[b].parentIndex = b;
		edges.push_back({ c,{a,b} });
	}

	sort(edges.begin(), edges.end());
	for (int i = 0; i < e; i++) {
		int nowC = edges[i].first;
		int parentA = members[edges[i].second.first].parentIndex;
		int parentB = members[edges[i].second.second].parentIndex;

		if (parentA != parentB) {
			sum += nowC;

			if (members[parentA].memberIndex.size() < members[parentB].memberIndex.size()) {
				for (int j = 0; j < members[parentA].memberIndex.size(); j++) {
					int childV = members[parentA].memberIndex[j];
					members[childV].parentIndex = parentB;
					members[parentB].memberIndex.push_back(childV);
				}
				members[parentA].parentIndex = parentB;
				members[parentB].memberIndex.push_back(parentA);
				members[parentA].memberIndex.clear();
			}
			else {
				for (int j = 0; j < members[parentB].memberIndex.size(); j++) {
					int childV = members[parentB].memberIndex[j];
					members[childV].parentIndex = parentA;
					members[parentA].memberIndex.push_back(childV);
				}
				members[parentB].parentIndex = parentA;
				members[parentA].memberIndex.push_back(parentB);
				members[parentB].memberIndex.clear();
			}
		}
	}

	cout << sum;
}