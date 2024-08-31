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

ULL a, b, sum;

void Go(ULL f, ULL s, int times) {
	ULL firstN, secondN, oddN, evenN;

	if (f == s) {
		if (f % 2) sum += (ULL)pow(2, times);
		else Go(f / 2, s / 2, times + 1);
		return;
	}

	if (f % 2)firstN = f + 1;
	else firstN = f;
	if (s % 2)secondN = s - 1;
	else secondN = s;

	evenN = (secondN / 2) - (firstN / 2) + 1;
	oddN = s - f + 1 - evenN;

	sum += (ULL)pow(2, times) * oddN;

	Go(firstN / 2, secondN / 2, times + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	Go(a, b, 0);
	cout << sum;
}