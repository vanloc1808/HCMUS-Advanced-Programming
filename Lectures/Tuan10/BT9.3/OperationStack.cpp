#include "OperationStack.h"

using namespace std;

int priority(char operation) {
	if (operation == '*' || operation == '/') {
		return 2;
	}
	if (operation == '+' || operation == '-') {
		return 1;
	}
	return 0; //brackets
}

int operations(int a, int b, char operation) {
	if (operation == '+') {
		return a + b;
	}
	else if (operation == '-') {
		return a - b;
	}
	else if (operation == '*') {
		return a * b;
	}
	else if (operation == '/') {
		return a / b;
	}
}

bool isDigit(char c) {
	return (c >= '0') && (c <= '9');
}

int countValue(string expression) {
	stackLL values; 
	stackCharLL operators;
	init(values);
	initCharStack(operators);
	int len = expression.length();
	for (int i = 0; i < len; i++) {
		if (expression[i] == ' ') {
			continue;
		}
		if (expression[i] == '(') {
			pushCharStack(operators, expression[i]);
		}
		else if (isDigit(expression[i])) {
			int tempValue = 0;
			while (i < len && isDigit(expression[i])) {
				tempValue = tempValue * 10 + (expression[i] - '0');
				i++;
			}
			pushStack(values, tempValue);
			i--; //because at this time i points to the element next to the digit
		}
		else if (expression[i] == ')') {
			while (!isCharStackEmpty(operators) && operators.top->data != '(') {
				int rhs = 0;
				popStack(values, rhs);
				int lhs = 0;
				popStack(values, lhs);
				char operation;
				popCharStack(operators, operation);
				int res = operations(lhs, rhs, operation);
				pushStack(values, res);
			}
			if (!isCharStackEmpty(operators)) {
				char temp;
				popCharStack(operators, temp);
			}
		}
		else {
			//+, -, *, /
			while (!isCharStackEmpty(operators) && priority(operators.top->data) >= priority(expression[i])) { 
				//when the priority of the operator on top of the stack >= priority of expression[i]
				int rhs = 0;
				popStack(values, rhs);
				int lhs = 0;
				popStack(values, lhs);
				char operation;
				popCharStack(operators, operation);
				int res = operations(lhs, rhs, operation);
				pushStack(values, res);
			}
			pushCharStack(operators, expression[i]);
		}
	}
	while (!isCharStackEmpty(operators)) {
		//process the remaining
		int rhs = 0;
		popStack(values, rhs);
		int lhs = 0;
		popStack(values, lhs);
		char operation;
		popCharStack(operators, operation);
		int res = operations(lhs, rhs, operation);
		pushStack(values, res);
	}
	return values.top->data;
}
