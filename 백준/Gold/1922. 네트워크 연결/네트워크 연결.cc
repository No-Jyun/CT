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

struct Node {
	int parent = -1;
	vector<int> tail;
	Node(){}
};

int n, m, result;
priority_queue<pair<int, pair<int, int>>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		q.push({ -c,{a,b} });
	}

	Node* arr = new Node[n + 1];
	for (int i = 1; i <= n; i++)arr[i].parent = i;
	
	while (!q.empty()) {
		int cost = -q.top().first;
		int parentA = arr[q.top().second.first].parent;
		int parentB = arr[q.top().second.second].parent;
		q.pop();

		if (parentA != parentB) {
			result += cost;

			if (arr[parentA].tail.size() > arr[parentB].tail.size()) {
				for (int i = 0; i < arr[parentB].tail.size(); i++) {
					arr[arr[parentB].tail[i]].parent = parentA;
					arr[parentA].tail.push_back(arr[parentB].tail[i]);
				}
				arr[parentB].tail.clear();
				arr[parentB].parent = parentA;
				arr[parentA].tail.push_back(parentB);
			}
			else {
				for (int i = 0; i < arr[parentA].tail.size(); i++) {
					arr[arr[parentA].tail[i]].parent = parentB;
					arr[parentB].tail.push_back(arr[parentA].tail[i]);
				}
				arr[parentA].tail.clear();
				arr[parentA].parent = parentB;
				arr[parentB].tail.push_back(parentA);
			}
		}
	}
	cout << result;
}