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
#define LL long long
#define INTMAX 2147483647
using namespace std;

int maxN, maxM;
int arr[10][31];
int answers[11];
int comb[5];
int sum;

void Cal() {
    bool isOkay = true;
    for (int i = 0; i < maxM && isOkay; i++) {
        int countN = 0;

        for (int j = 0; j < 5; j++) {
            if (arr[i][comb[j]])countN++;
        }

        if (countN != answers[i])isOkay = false;
    }
    if (isOkay)sum++;
}

void D(int nowIndex, int arrIndex) {
    if (nowIndex == 5) {
        Cal();
        return;
    }

    for (int i = arrIndex + 1; i <= maxN; i++) {
        comb[nowIndex] = i;
        D(nowIndex + 1, i);
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < 5; j++)arr[i][q[i][j]] = 1;
        answers[i] = ans[i];
    }

    maxN = n;
    maxM = ans.size();
    D(0, 0);

    return sum;
}