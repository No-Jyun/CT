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

string s, boom;
stack<char> stk;

void Chk() {
	for (int i = s.length() - 1; i >= 0; i--) {
		stk.push(s[i]);

		if (s[i] == boom[0]) {
			stack<char> tmp;

			for (int j = 0; j < boom.length(); j++) {
				if (stk.empty()) {
					while (!tmp.empty()) {
						stk.push(tmp.top());
						tmp.pop();
					}
					break;
				}
				else {
					if (boom[j] == stk.top()) {
						tmp.push(stk.top());
						stk.pop();
					}
					else {
						while (!tmp.empty()) {
							stk.push(tmp.top());
							tmp.pop();
						}
						break;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> boom;

	Chk();
	if (stk.empty())cout << "FRULA";
	else {
		while (!stk.empty()) {
			cout << stk.top();
			stk.pop();
		}
	}
}