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

int maincharNum[129];	// 65 ~ 90 까지가 A ~ Z
int subcharNum[129];
int result;
string input[101];

bool Check(string s) {
	for (int i = 0; i < s.length(); i++) subcharNum[s[i]]++;

	int chk[3] = { 0, };
	int chkI = 0;
	for (int i = 65; i <= 90; i++) {
		subcharNum[i] -= maincharNum[i];

		if (subcharNum[i] >= 2 || subcharNum[i] <= -2)return false;
		if (subcharNum[i])chk[chkI++] = subcharNum[i];
		if (chkI == 3)return false;
	}
	
	chkI = 0;
	for (auto tmp : chk)chkI += tmp;

	return chkI >= -1 && chkI <= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)cin >> input[i];

	for (int i = 0; i < input[1].length(); i++) maincharNum[input[1][i]]++;;
	for (int i = 2; i <= t; i++) {
		if (Check(input[i]))result++;
		fill(subcharNum, subcharNum + 129, 0);
	}
	cout << result;
}