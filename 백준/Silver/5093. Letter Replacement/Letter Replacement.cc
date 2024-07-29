#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int chk[200];
string s;
char letter[6] = { '0','*','?','/','+','!' };
int letterIndex = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> s;
		if (s == "#")break;

		for (int i = 0; i < s.size(); i++) {
			int alpha = tolower(s[i]);
			if (chk[alpha]) {
				if (chk[alpha] == 9999) {
					chk[alpha] = letterIndex++;
				}
				s[i] = letter[chk[alpha]];
			}
			else chk[alpha] = 9999;

			cout << s[i];
		}
		cout << '\n';

		fill(chk, chk + 200, 0);
		letterIndex = 1;
	}
}