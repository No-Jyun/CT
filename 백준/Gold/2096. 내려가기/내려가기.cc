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
using namespace std;

int n;
int arr[2][2][3];

bool Range(int b) {
	return b >= 0 && b <= 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;

			if (i == 0) {
				arr[0][0][j] = a;
				arr[1][0][j] = a;
			}
			else {
				arr[1][1][j] = arr[1][0][j] + a;

				int d = -1;
				while (d < 2) {
					int tmpJ = j + d;

					if (Range(tmpJ)) {
						arr[0][1][j] = max(arr[0][0][tmpJ] + a, arr[0][1][j]);
						arr[1][1][j] = min(arr[1][0][tmpJ] + a, arr[1][1][j]);
					}

					d++;
				}
			}
		}

		if (i != 0) {
			for (int j = 0; j < 3; j++) {
				arr[0][0][j] = arr[0][1][j];
				arr[1][0][j] = arr[1][1][j];
			}
		}
	}

	cout << max(max(arr[0][0][0], arr[0][0][1]), arr[0][0][2]) << ' '
		<< min(min(arr[1][0][0], arr[1][0][1]), arr[1][0][2]);
}