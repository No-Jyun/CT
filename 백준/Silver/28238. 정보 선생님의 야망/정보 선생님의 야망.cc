#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n;
int arr[1000001][5];
pair<int, int> maxDay = { 0,0 };
int maxim = 0;
int day[5] = { 1,1,0,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			int tmp = 0;
			for (int k = 1; k <= n; k++) {
				if (arr[k][i] && arr[k][j])tmp++;
			}

			if (maxim < tmp) {
				maxim = tmp;
				maxDay = { i,j };
			}
		}
	}

	if (maxim)fill(day, day + 5, 0);
	day[maxDay.first] = 1;
	day[maxDay.second] = 1;
	cout << maxim << '\n';
	for (int i = 0; i < 5; i++) {
		cout << day[i] << ' ';
	}
}