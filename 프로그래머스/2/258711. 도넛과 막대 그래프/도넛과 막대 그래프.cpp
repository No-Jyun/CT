#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
using namespace std;

int addedV, maxV;
vector<int> v[1000001];
bool chk[1000001];

int DFS(int index) {
    stack<int> stk;
    stk.push(index);
    chk[index] = 1;

    while (!stk.empty()) {
        int nowV = stk.top();
        stk.pop();

        int edgeN = v[nowV].size();
        if (edgeN == 2)return 2;
        if (edgeN == 0)return 0;

        for (int i = 0; i < edgeN; i++) {
            if (!chk[v[nowV][i]]) {
                chk[v[nowV][i]] = 1;
                stk.push(v[nowV][i]);
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    answer = { 0,0,0,0 };

    for (int i = 0; i < edges.size(); i++) {
        int va = edges[i][0];
        int vb = edges[i][1];
        v[va].push_back(vb);
        chk[vb] = 1;
        maxV = max(maxV, max(va, vb));
    }

    for (int i = 1; i <= maxV; i++) {
        if (!chk[i] && v[i].size() >= 2) {
            addedV = i;
            break;
        }
    }
    answer[0] = addedV;

    fill(chk, chk + maxV + 1, 0);
    for (int i = 0; i < v[addedV].size(); i++) {
        switch (DFS(v[addedV][i]))
        {
        case 0:
            answer[2]++;
            break;
        case 1:
            answer[1]++;
            break;
        default:
            answer[3]++;
            break;
        }
    }
    return answer;
}