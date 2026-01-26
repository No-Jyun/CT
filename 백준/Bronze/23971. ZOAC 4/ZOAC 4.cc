#include <cmath>
#include <iostream>
using namespace std;

int h, w, n, m;

long long StartSolve()
{
	int width = ceil((float)w / (m + 1));//4/2
	int height = ceil((float)h / (n + 1));

	return width * height;
}

int main()
{
	cin >> h >> w >> n >> m;

	cout << StartSolve();
}