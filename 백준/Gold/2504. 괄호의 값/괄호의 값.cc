#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

string s;
int result;
bool trig = false;

int Cal(int& index) {
	stack<char> stk;

	int tmp = 1;
	for (; index < s.size(); index++) {
		if (s[index] == '(' || s[index] == '[') {
			if (stk.empty()) stk.push(s[index]);

			else {
				if (tmp != 1) tmp += Cal(index);
				else tmp *= Cal(index);
			}
		}

		else {
			if (stk.empty()) {
				trig = true;
				return -1;
			}

			if (s[index] == ')' && stk.top() == '(') {
				return tmp * 2;
			}

			if (s[index] == ']' && stk.top() == '[') {
				return tmp * 3;
			}

			trig = true;
			return -1;
		}
	} 
	trig = true;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		result += Cal(i);
	}

	if (trig) cout << 0;
	else cout << result;
}