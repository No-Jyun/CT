#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int h, w;
int arr[501][501];
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;
	for (int i = 1; i <= w; i++) {
		int a;
		cin >> a;
		for (int j = h; j > h - a; j--)arr[j][i] = 1;
	}

	for (int i = 1; i <= h; i++) {
		bool trig = false;
		int tmp = 0;
		for (int j = 1; j <= w; j++) {
			if (!trig) {
				if (arr[i][j])trig = true;
			}
			else {
				if (!arr[i][j])tmp++;
				else {
					result += tmp;
					tmp = 0;
					trig = true;
				}
			}
		}
	}
	cout << result;
}