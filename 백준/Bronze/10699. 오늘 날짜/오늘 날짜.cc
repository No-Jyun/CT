#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <ctime>
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

	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	cout << t->tm_year + 1900 << '-';
	int mm = t->tm_mon + 1;
	int dd = t->tm_mday;

	if (mm < 10) {
		cout << '0' << mm << '-';
	}
	else cout << mm << '-';
	if (dd < 10) {
		cout << '0' << dd;
	}
	else cout << dd;
}