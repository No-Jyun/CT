#include <string>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> GetPos(int numPos, bool isLefthanded)
{
    if(numPos == -1)
    {
        if(isLefthanded)
        {
            return {3, 0};
        }
        else
        {
            return {3, 2};   
        }            
    }
    
    if(numPos == 0)
        return {3, 1};
    else if(numPos == 1)
        return {0, 0};
    else if(numPos == 2)
        return {0, 1};
    else if(numPos == 3)
        return {0, 2};
    else if(numPos == 4)
        return {1, 0};
    else if(numPos == 5)
        return {1, 1};
    else if(numPos == 6)
        return {1, 2};
    else if(numPos == 7)
        return {2, 0};
    else if(numPos == 8)
        return {2, 1};
    else if(numPos == 9)
        return {2, 2};
}

bool LeftHandClicked(int targetPos, int curLPos, int curRPos, bool isLefthanded)
{
    pair<int, int> targetP = GetPos(targetPos, isLefthanded);
    pair<int, int> curLP = GetPos(curLPos, isLefthanded);
    pair<int, int> curRP = GetPos(curRPos, isLefthanded);
    
    int lengLT = abs(targetP.first - curLP.first) + abs(targetP.second - curLP.second);
    int lengRT = abs(targetP.first - curRP.first) + abs(targetP.second - curRP.second);
    
    if(lengLT == lengRT)
    {
        if(isLefthanded)
            return true;
        else
            return false;
    }
    if(lengLT > lengRT)
        return false;
    
    return true;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    bool isL = hand[0] == 'l';
    int lastLNum = -1;
    int lastRNum = -1;
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer.push_back('L');
            lastLNum = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer.push_back('R');
            lastRNum = numbers[i];
        }
        else
        {
            if(LeftHandClicked(numbers[i], lastLNum, lastRNum, isL))
            {
                answer.push_back('L');
                lastLNum = numbers[i];
            }
            else
            {
                answer.push_back('R');
                lastRNum = numbers[i];
            }
        }
    }
        
    return answer;
}