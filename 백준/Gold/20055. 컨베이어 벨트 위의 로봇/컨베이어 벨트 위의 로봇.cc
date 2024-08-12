#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <tuple>
#include <math.h>
using namespace std;

int n, k, maxN;
deque<int> arr;
deque<bool> robotArr;
int stage;
int zeroBelt;

void RotateBelt() {
	arr[0] = arr.back();
	arr.pop_back();
	arr.push_front(0);

	robotArr[0] = robotArr.back();
	robotArr.pop_back();
	robotArr.push_front(0);

	if (robotArr[n])robotArr[n] = 0;
}

void MoveRobot() {
	for (int i = maxN; i >= 1; i--) {
		if (robotArr[i]) {
			int nextI = i + 1;
			if (i == maxN) {
				nextI = 1;
			}
			
			if (!robotArr[nextI] && arr[nextI]) {
				robotArr[i] = 0;
				robotArr[nextI] = 1;
				arr[nextI]--;
				if (!arr[nextI])zeroBelt++;
			}
		}
	}

	if (robotArr[n]) robotArr[n] = 0;
}

void PutRobot() {
	if (arr[1]) {
		arr[1]--;
		if (!arr[1])zeroBelt++;
		
		robotArr[1] = 1;
	}
}

bool EndCondition() {
	return zeroBelt < k;
}

void StageOn() {
	do
	{
		stage++;
		RotateBelt();
		MoveRobot();
		PutRobot();
	} while (EndCondition());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	maxN = 2 * n;
	arr.push_back(0);
	robotArr.push_back(0);

	for (int i = 1; i <= 2 * n; i++) {
		cin >> arr[0];
		arr.push_back(arr[0]);
		robotArr.push_back(0);
	}

	StageOn();
	cout << stage;
}