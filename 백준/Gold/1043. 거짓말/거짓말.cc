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

void DFSP(int);
void DFSM(int);
int n, m;
int k, result;;
vector<int> partyEdge[51];
vector<int> partyPeople[51];
bool knownParty[51];
int know[51];

void DFSP(int partyI) {
	knownParty[partyI] = 1;

	for (int i = 0; i < partyPeople[partyI].size(); i++) {
		if (!know[partyPeople[partyI][i]]) {
			DFSM(partyPeople[partyI][i]);
		}
	}
}

void DFSM(int memI) {
	know[memI] = 2;

	for (int i = 0; i < partyEdge[memI].size(); i++) {
		if (!knownParty[partyEdge[memI][i]]) {
			DFSP(partyEdge[memI][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		know[a] = 1;
	}

	for (int i = 1; i <= m; i++) {
		int l;
		cin >> l;
		for (int j = 1; j <= l; j++) {
			int mem;
			cin >> mem;
			partyPeople[i].push_back(mem);
			partyEdge[mem].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (know[i] == 1)DFSM(i);
	}

	for (int i = 1; i <= m; i++) {
		if (!knownParty[i])result++;
	}
	cout << result;
}