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
#define INTMAX 2147483647
using namespace std;

int n, m;
priority_queue<pair<int, pair<int, int>>> edges;
int originCost, maxCost;

struct MyUnion
{
	int head;
	vector<int> body;

	MyUnion() {}
}unionArr[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> m >> n;
		if (!m)break;

		originCost = 0, maxCost = 0;
		int a, b, c;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> c;
			edges.push({ -c,{a,b} });
			originCost += c;
		}

		for (int i = 0; i < m; i++) {
			unionArr[i].head = i;
			unionArr[i].body.clear();
		}

		while (!edges.empty()) {
			int nowCost = -edges.top().first;
			int parentA = unionArr[edges.top().second.first].head;
			int parentB = unionArr[edges.top().second.second].head;
			edges.pop();

			if (parentA != parentB) {
				maxCost += nowCost;

				if (unionArr[parentA].body.size() < unionArr[parentB].body.size()) {
					for (int i = 0; i < unionArr[parentA].body.size(); i++) {
						unionArr[unionArr[parentA].body[i]].head = parentB;
						unionArr[parentB].body.push_back(unionArr[parentA].body[i]);
					}
					unionArr[parentA].body.clear();
					unionArr[parentA].head = parentB;
					unionArr[parentB].body.push_back(parentA);
				}
				else {
					for (int i = 0; i < unionArr[parentB].body.size(); i++) {
						unionArr[unionArr[parentB].body[i]].head = parentA;
						unionArr[parentA].body.push_back(unionArr[parentB].body[i]);
					}
					unionArr[parentB].body.clear();
					unionArr[parentB].head = parentA;
					unionArr[parentA].body.push_back(parentB);
				}
			}
		}
		cout << originCost - maxCost << '\n';
	}
}