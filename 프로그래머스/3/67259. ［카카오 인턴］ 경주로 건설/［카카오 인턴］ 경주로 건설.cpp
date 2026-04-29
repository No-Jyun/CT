#include <string>
#include <vector>

using namespace std;

int n;

int mI[4] = { -1,0,1,0 };
int mJ[4] = { 0,1,0,-1 };
int cost[25][25];

void DFS(int i, int j, int exDir, vector<vector<int>>& board)
{
    for (int d = 0; d < 4; d++)
    {
        int gotoI = i + mI[d];
        int gotoJ = j + mJ[d];

        if (gotoI >= 0 && gotoI < n && gotoJ >= 0 && gotoJ < n && !board[gotoI][gotoJ])
        {
            int newCost = cost[i][j];
            if (d == exDir)
                newCost += 100;
            else
                newCost += 600;

            if (cost[gotoI][gotoJ] >= newCost)
            {
                cost[gotoI][gotoJ] = newCost;
                DFS(gotoI, gotoJ, d, board);
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = (int)board.size();
    for (int i = 0; i < n; i++)
    {
        fill(cost[i], cost[i] + n, 999999999);
    }
    cost[0][0] = 0;

    if (!board[0][1])
    {
        cost[0][1] = 100;
        DFS(0, 1, 1, board);
    }

    if (!board[1][0])
    {
        cost[1][0] = 100;
        DFS(1, 0, 2, board);
    }

    return cost[n - 1][n - 1];
}