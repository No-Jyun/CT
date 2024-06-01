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

vector<string> expression;

void Cal() {
	while (1) {
		bool brP = false;

		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == "+") {
				int sum = stoi(expression[i - 1]) + stoi(expression[i + 1]);

				vector<string> tmp;
				for (int j = 0; j <= i - 2; j++)tmp.push_back(expression[j]);
				tmp.push_back(to_string(sum));
				for (int j = i + 2; j < expression.size(); j++)tmp.push_back(expression[j]);

				brP = true;
				expression = tmp;
				break;
			}
		}
		if (!brP)break;
	}

	while (expression.size() != 1) {
		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == "-") {
				int sum = stoi(expression[i - 1]) - stoi(expression[i + 1]);

				vector<string> tmp;
				for (int j = 0; j <= i - 2; j++)tmp.push_back(expression[j]);
				tmp.push_back(to_string(sum));
				for (int j = i + 2; j < expression.size(); j++)tmp.push_back(expression[j]);

				expression = tmp;
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, tmp;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')tmp.push_back(s[i]);
		else {
			expression.push_back(tmp);
			tmp = s[i];
			expression.push_back(tmp);
			tmp.clear();
		}
	}
	expression.push_back(tmp);

	Cal();

	cout << stoi(expression[0]);
}