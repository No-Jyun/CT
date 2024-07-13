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

	string s;
	int base = 0;
	for (int i = 0; i < 3; i++) {
		cin >> s;

		if (base)base++;
		else {
			if (s[0] >= '0' && s[0] <= '9')base = stoi(s);
		}
	}
	base++;

	if (!(base % 3) && !(base % 5))cout << "FizzBuzz";
	else if (!(base % 3))cout << "Fizz";
	else if (!(base % 5))cout << "Buzz";
	else cout << base;
}