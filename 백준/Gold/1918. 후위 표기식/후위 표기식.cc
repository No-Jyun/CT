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

string s, result;
int preOrder[300];
stack<char> stk;

void ManageStk(char nowP) {
	if (stk.empty() || nowP == '(') {
		stk.push(nowP);
		return;
	}

	if (nowP == ')') {
		while (stk.top() != '(') {
			result.push_back(stk.top());
			stk.pop();
		}
		stk.pop();
		return;
	}

	int nowPP = preOrder[nowP];
	while (!stk.empty() && preOrder[stk.top()] >= nowPP) {
		if (stk.top() == '(')break;
		result.push_back(stk.top());
		stk.pop();
	}
	stk.push(nowP);
}

void CheckS() {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90)result.push_back(s[i]);
		else ManageStk(s[i]);
	}

	while (!stk.empty()) {
		result.push_back(stk.top());
		stk.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	preOrder['('] = 9, preOrder[')'] = 10;
	preOrder['*'] = 8, preOrder['/'] = 8;
	preOrder['+'] = 7, preOrder['-'] = 7;

	cin >> s;

	CheckS();

	cout << result;
}