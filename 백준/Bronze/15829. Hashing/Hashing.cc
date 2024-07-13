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

int r = 31;
int M = 1234567891;
ULL H;

ULL Div(int c) {
	if (c == 0 )return 1;
	if (c == 1)return r;

	ULL t = Div(c / 2);
	if (c % 2)return (((t * t) % M) * r) % M;
	else return (t * t) % M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l;
	cin >> l;
	string s;
	cin >> s;

	for (int i = 0; i < l; i++) {
		ULL n = s[i] - 'a' + 1;
		H += (n * Div(i)) % M;
		H %= M;
	}
	cout << H;
}