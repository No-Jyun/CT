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

int n;
ULL result;
int charChk[26];
string arr[11];
priority_queue<pair<int, int>> q;

void Cal() {
	for (int index = 1; index <= n; index++) {
		int times = arr[index].length() - 1;

		for (int i = 0; i < arr[index].length(); i++) {
			result += charChk[arr[index][i] - 'A'] * pow(10, times--);
		}
	}
}

void DecChar() {
	for (int i = 1; i <= n; i++) {
		int score = 1;
		for (int j = arr[i].length() - 1; j >= 0; j--) {
			charChk[arr[i][j] - 'A'] += score;
			score *= 10;
			score++;
		}
	}

	int nO = 9;
	for (int i = 0; i < 26; i++) {
		q.push({ charChk[i],i });
		charChk[i] = 0;
	}
	while (nO > 0 && !q.empty()) {
		charChk[q.top().second] = nO--;
		q.pop();
	}

	return Cal();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	DecChar();
	cout << result;
}