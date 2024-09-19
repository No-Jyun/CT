#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
using namespace std;

void Balance(priority_queue<int, vector<int>, greater<int>>& G, priority_queue<int, vector<int>, less<int>>& L, int& a, int index) {
	int nowMid;
	if ((index-1) % 2 == 0)nowMid = L.top();
	else {
		if ((index - 1) / 2 + 1 == L.size())nowMid = L.top();
		else nowMid = G.top();
	}

	if (a >= nowMid)G.emplace(a);
	else L.emplace(a);

	if (G.size() - L.size() == 2) {
		L.emplace(G.top()); 
		G.pop();
	}
	else if (G.size() - L.size() == -2) {
		G.emplace(L.top());
		L.pop();
	}

	if (index % 2 == 0)nowMid = L.top(); 
	else {
		if (index / 2 + 1 == L.size())nowMid = L.top(); 
		else nowMid = G.top(); 
	}
	cout << nowMid << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> qG;	// 1 2 3 4 5
	priority_queue<int, vector<int>, less<int>> qL;

	int a;
	cin >> a;
	qL.emplace(a);
	cout << a << '\n';

	int index = 1;
	while (index++ < n) {
		int a;
		cin >> a;

		Balance(qG, qL, a, index);
	}
}