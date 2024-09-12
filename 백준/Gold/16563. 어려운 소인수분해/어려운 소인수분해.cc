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
int target[1000001];
bool chk[1000001];
vector<int> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)cin >> target[i];

	for (int i = 2; i <= sqrt(5000000); i++) {
		if (!chk[i]) {
			p.push_back(i);
			for (int j = 2; i * j <= sqrt(5000000); j++) {
				chk[i * j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < p.size(); j++) {
			while (target[i] % p[j] == 0) {
				cout << p[j] << ' ';
				target[i] /= p[j];
			}
			
			if (target[i] == 1)break;
		}
        if(target[i] != 1) cout << target[i];
		cout << '\n';
	}
}