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
using namespace std;

void Start(vector<int>& v) {
	int nowI = 0, endN = v.size();
	vector<char> result;
	stack<int> stk;
	int i = 1;
	while (nowI != endN) {
		if (stk.empty()) { stk.push(i++); result.push_back('+'); }
		else {
			if (stk.top() == v[nowI]) {
				stk.pop();
				nowI++;
				result.push_back('-');
			}
			else if (stk.top() > v[nowI]) { cout << "NO"; return; }
			else { stk.push(i++); result.push_back('+'); }
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a); 
	}
	Start(v);
}