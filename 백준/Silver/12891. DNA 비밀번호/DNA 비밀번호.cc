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

int s, p;
string dna;
int n[5];
int result;

bool Check(int* arr) {
	for (int i = 1; i <= 4; i++) {
		if (n[i] > arr[i])return false;
	}
	return true;
}

int Word(int i) {
	if (dna[i] == 'A')return 1;
	if (dna[i] == 'C')return 2;
	if (dna[i] == 'G')return 3;
	if (dna[i] == 'T')return 4;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> p;
	cin >> dna;
	for (int i = 1; i <= 4; i++)cin >> n[i];

	int tn[5] = { 0, };
	int index = 0;
	for (int i = 0; i < p; i++) {
		index = Word(i);
		tn[index]++;
	}
	if (Check(tn))result++;

	for (int i = 1; i <= s - p; i++) {
		tn[Word(i - 1)]--;
		tn[Word(i + p - 1)]++;
		if (Check(tn))result++;
	}
	cout << result;
}