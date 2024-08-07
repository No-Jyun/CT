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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;
	
	if (n % 7 == 0 || (n - 2) % 7 == 0)cout << "CY";
	else cout << "SK";
}