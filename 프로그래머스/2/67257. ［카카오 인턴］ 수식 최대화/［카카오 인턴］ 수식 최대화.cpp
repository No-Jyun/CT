#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Exep
{
	char oper = '+';
	long long num = 0;

	Exep(char oper, long long num)
		: oper(oper), num(num)
	{
	}
};

int operOrder[6][3] = {
	{1,2,3},
	{1,3,2},
	{2,1,3},
	{2,3,1},
	{3,1,2},
	{3,2,1}
};

long long Calculate(long long numA, long long numB, char oper)
{
	if (oper == '+')
		return numA + numB;
	else if (oper == '-')
		return numA - numB;
	else
		return numA * numB;
}

int GetOrder(char operC, int ix)
{
	if (operC == '+')
		return operC = operOrder[ix][0];
	else if (operC == '-')
		return operC = operOrder[ix][1];
	else
		return operC = operOrder[ix][2];
}

long long solution(string expression) {
	long long answer = 0;

	string parse;
	char exOper = '+';
	vector<Exep> calExpression;

	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
		{
			calExpression.emplace_back(Exep(exOper, stoll(parse)));
			exOper = expression[i];
			parse.clear();
		}
		else
		{
			parse.push_back(expression[i]);
		}
	}
	calExpression.emplace_back(Exep(exOper, stoll(parse)));

	for (int j = 0; j < 6; j++)
	{
		vector<Exep> inCalExpression = calExpression;

		for (int i = 1; i < inCalExpression.size();)
		{
			int operOrder = GetOrder(inCalExpression[i].oper, j);

			if (operOrder != 3)
			{
				i++;
				continue;
			}

			long long num1 = inCalExpression[i - 1].num;
			long long num2 = inCalExpression[i].num;
			long long num = Calculate(num1, num2, inCalExpression[i].oper);

			Exep inExep(inCalExpression[i - 1].oper, num);

			inCalExpression.erase(inCalExpression.begin() + i);
			inCalExpression[i - 1] = inExep;
		}

		for (int i = 1; i < inCalExpression.size();)
		{
			int operOrder = GetOrder(inCalExpression[i].oper, j);

			if (operOrder != 2)
			{
				i++;
				continue;
			}

			long long num1 = inCalExpression[i - 1].num;
			long long num2 = inCalExpression[i].num;
			long long num = Calculate(num1, num2, inCalExpression[i].oper);

			Exep inExep(inCalExpression[i - 1].oper, num);

			inCalExpression.erase(inCalExpression.begin() + i);
			inCalExpression[i - 1] = inExep;
		}

		for (int i = 1; i < inCalExpression.size();)
		{
			int operOrder = GetOrder(inCalExpression[i].oper, j);

			if (operOrder != 1)
			{
				i++;
				continue;
			}

			long long num1 = inCalExpression[i - 1].num;
			long long num2 = inCalExpression[i].num;
			long long num = Calculate(num1, num2, inCalExpression[i].oper);

			Exep inExep(inCalExpression[i - 1].oper, num);

			inCalExpression.erase(inCalExpression.begin() + i);
			inCalExpression[i - 1] = inExep;
		}

		answer = max(answer, abs(inCalExpression[0].num));
	}

	return answer;
}