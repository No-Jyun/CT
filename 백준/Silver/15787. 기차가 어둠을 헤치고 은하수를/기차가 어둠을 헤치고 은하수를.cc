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

int overseat = pow(2, 21);
int train[100001];
bool chk[100001];
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int order;
		cin >> order;

		int tN, sN;
		if (order == 1) {
			cin >> tN >> sN;
			int seatHere = pow(2, sN);
			
			if ((train[tN] / seatHere) % 2 == 0)train[tN] += seatHere;
		}
		else if (order == 2) {
			cin >> tN >> sN;
			int seatHere = pow(2, sN);

			if ((train[tN] / seatHere) % 2 == 1)train[tN] -= seatHere;
		}
		else if (order == 3) {
			cin >> tN;
			train[tN] *= 2;
			train[tN] %= overseat;
		}
		else {
			cin >> tN;
			train[tN] /= 2;
			if (train[tN] % 2 == 1)train[tN]--;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			result++;
			for (int j = i + 1; j <= n; j++) {
				if (train[i] == train[j])chk[j] = 1;
			}
		}
	}
	cout << result;
}