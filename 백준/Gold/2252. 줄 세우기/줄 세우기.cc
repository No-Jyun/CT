// Linked List 구현
// 각 요소를 가리킬 포인터를 저장할 벡터 필요
#include <iostream>
#include <cstring>

using namespace std;

struct Node
{
	Node(int num)
		: num(num)
	{
	}

	int num = 0;
	Node* next = nullptr;
	Node* previous = nullptr;
};

int n, m;
Node* numPosition[32001];

int main()
{
	cin >> n >> m;
	memset(numPosition, 0, sizeof(numPosition));

	Node* first = nullptr;
	Node* last = nullptr;

	for (int i = 0; i < m; i++)
	{
		int small = 0, tall = 0;
		cin >> small >> tall;

		if (first == nullptr)
		{
			numPosition[small] = new Node(small);
			numPosition[tall] = new Node(tall);
			
			numPosition[small]->next = numPosition[tall];
			numPosition[tall]->previous = numPosition[small];
			
			first = numPosition[small];
			last = numPosition[tall];
			continue;
		}

		if (numPosition[small] == nullptr && numPosition[tall] == nullptr)
		{
			numPosition[small] = new Node(small);
			numPosition[tall] = new Node(tall);

			numPosition[small]->next = numPosition[tall];
			numPosition[tall]->previous = numPosition[small];

			numPosition[small]->previous = last;
			last->next = numPosition[small];

			last = numPosition[tall];
		}
		else if (numPosition[small] == nullptr)
		{
			numPosition[small] = new Node(small);

			int firstNum = first->num;

			numPosition[firstNum]->previous = numPosition[small];
			numPosition[small]->next = numPosition[firstNum];

			first = numPosition[small];
		}
		else if (numPosition[tall] == nullptr)
		{
			numPosition[tall] = new Node(tall);

			int lastNum = last->num;

			numPosition[lastNum]->next = numPosition[tall];
			numPosition[tall]->previous = numPosition[lastNum];

			last = numPosition[tall];
		}
		else
		{
			if (numPosition[small] == first || numPosition[tall] == last)
				continue;

			if (numPosition[tall] == first)
			{
				numPosition[small]->previous->next = numPosition[small]->next;
				numPosition[small]->next->previous = numPosition[small]->previous;

				numPosition[tall]->previous = numPosition[small];

				numPosition[small]->previous = nullptr;
				numPosition[small]->next = numPosition[tall];

				first = numPosition[small];
			}
			else if (numPosition[small] == last)
			{
				numPosition[tall]->previous->next = numPosition[tall]->next;
				numPosition[tall]->next->previous = numPosition[tall]->previous;

				numPosition[small]->next = numPosition[tall];

				numPosition[tall]->next = nullptr;
				numPosition[tall]->previous = numPosition[small];

				last = numPosition[tall];
			}
			else
			{
				numPosition[small]->previous->next = numPosition[small]->next;
				numPosition[small]->next->previous = numPosition[small]->previous;

				numPosition[tall]->previous->next = numPosition[small];
				numPosition[small]->previous = numPosition[tall]->previous;

				numPosition[tall]->previous = numPosition[small];
				numPosition[small]->next = numPosition[tall];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!numPosition[i])
		{
			numPosition[i] = new Node(i);

			int lastNum = last->num;

			numPosition[lastNum]->next = numPosition[i];
			numPosition[i]->previous = numPosition[lastNum];

			last = numPosition[i];
		}
	}

	Node* current = first;
	while (first)
	{
		cout << first->num << ' ';
		first = first->next;
	}

	for (int i = 1; i <= n; i++)
	{
		if (numPosition[i])
			delete numPosition[i];
	}
}

// 4 2 3 1 5 6
// 4 5 2 3 1 6
