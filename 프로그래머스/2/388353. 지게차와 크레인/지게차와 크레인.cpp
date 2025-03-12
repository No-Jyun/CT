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

int n, m;
char store[55][55];
int chk[55][55];
int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

bool Range(int a, int b) {
    return a >= 0 && a <= n + 1 && b >= 0 && b <= m + 1;
}

void B(char target) {
    fill(chk[0], chk[n + 3], 0);
    queue<pair<int, int>> q, rem;
    q.push({ 0,0 });
    chk[0][0] = 1;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int tmpI = i + mI[d];
            int tmpJ = j + mJ[d];

            if (Range(tmpI, tmpJ) && !chk[tmpI][tmpJ]) {
                chk[tmpI][tmpJ] = 1;
                if (store[tmpI][tmpJ] == '0')q.push({ tmpI,tmpJ });
                else if (store[tmpI][tmpJ] == target)rem.push({ tmpI,tmpJ });
            }
        }
    }

    while (!rem.empty()) {
        int i = rem.front().first;
        int j = rem.front().second;
        rem.pop();

        store[i][j] = '0';
    }
}

void C(char target) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (store[i][j] == target) store[i][j] = '0';
        }
    }
}

int Ans() {
    int c = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (store[i][j] != '0')c++;
        }
    }
    return c;
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    fill(store[0], store[n + 3], '0');

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)store[i + 1][j + 1] = storage[i][j];
    }

    for (int i = 0; i < requests.size(); i++) {
        if (requests[i].size() == 1)B(requests[i][0]);
        else C(requests[i][0]);
    }

    return Ans();
}