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
using namespace std;

int heap[100001];
int heapSize;

void PushHeap(int x) {
	heap[++heapSize] = x;

	int comp = heapSize / 2;
	int now = heapSize;
	while (comp >= 1) {
		if (abs(heap[comp]) > abs(heap[now])) {
			swap(heap[comp], heap[now]);
			now = comp;
			comp /= 2;
		}
		else if ((abs(heap[comp]) == abs(heap[now])) && (heap[comp] > heap[now])) {
			swap(heap[comp], heap[now]);
			now = comp;
			comp /= 2;
		}
		else break;
	}
}

void PopHeap() {
	if (!heapSize) {
		cout << 0 << '\n';
		return;
	}

	cout << heap[1] << '\n';
	heap[1] = heap[heapSize--];

	int now = 1;
	int comp = 2;

	while (comp <= heapSize) {
		if ((comp != heapSize) && ((abs(heap[comp]) > abs(heap[comp + 1]))
			|| ((abs(heap[comp]) == abs(heap[comp + 1])) && (heap[comp] > heap[comp + 1])))) comp++;
		
		if (abs(heap[now]) > abs(heap[comp])) {
			swap(heap[now], heap[comp]);
			now = comp;
			comp *= 2;
		}
		else if ((abs(heap[now]) == abs(heap[comp])) && (heap[now] > heap[comp])) {
			swap(heap[now], heap[comp]);
			now = comp;
			comp *= 2;
		}
		else break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;

		if (x)PushHeap(x);
		else PopHeap();
	}
}