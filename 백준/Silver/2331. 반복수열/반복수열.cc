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

stack<string> arr;

void SumOfNum(string s, int p) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		int nowN = s[i] - '0';
		sum += pow(nowN, p);
	}

	string findN = to_string(sum);
	stack<string> tmp = arr;

	while (!tmp.empty()) {
		if (tmp.top() == findN) {
			cout << tmp.size() - 1;
			return;
		}
		tmp.pop();
	}
	arr.push(findN);
	SumOfNum(findN, p);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n;
	int p;
	cin >> n >> p;

	arr.push(n);
	SumOfNum(n, p);
}