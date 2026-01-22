#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, d, r, c;
int room[51][51];

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };

int answer = 0;

int DirControl(int how = 0) {
    if (how == 1) {
        switch (d)
        {
        case 0: return 2;
        case 1: return 3;
        case 2: return 0;
        case 3: return 1;
        }
    }
    else {
        switch (d)
        {
        case 0: return 3;
        case 1: return 0;
        case 2: return 1;
        case 3: return 2;
        }
    }
}

bool Search()
{
    for (int i = 0; i < 4; i++) {
        if (!room[r + mI[i]][c + mJ[i]])
            return true;
    }
    return false;
}

bool CanBack() {
    int bD = DirControl(1);
    if (room[r + mI[bD]][c + mJ[bD]] != 1) return true;
    return false;
}

void StartSolve() 
{
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
        }
    }

    while (1) {
        if (!room[r][c]) {
            room[r][c] = 2;
            answer++;
        }

        if (Search()) {
            d = DirControl();
            if (room[r + mI[d]][c + mJ[d]] == 0) {
                r += mI[d];
                c += mJ[d];
            }
        }
        else {
            if (CanBack()) {
                // 뒤로
                int bD = DirControl(1);
                r += mI[bD];
                c += mJ[bD];
            }
            else {
                // 작동 중지
                break;
            }
        }
    }
}

int main() 
{
    StartSolve();

    cout << answer;
}