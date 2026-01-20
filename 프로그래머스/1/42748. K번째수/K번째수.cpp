#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int it = 0; it < commands.size(); it++)
    {
        vector<int> tArray;
        int i = commands[it][0];
        int j = commands[it][1];
        int k = commands[it][2];

        for (int ii = i - 1; ii <= j - 1; ii++) 
        {
            tArray.push_back(array[ii]);
        }

        //copy(array.begin() + i - 1, array.begin() + j - 1, tArray.begin());
        sort(tArray.begin(), tArray.end());
        answer.push_back(tArray[k - 1]);
    }

    return answer;
}