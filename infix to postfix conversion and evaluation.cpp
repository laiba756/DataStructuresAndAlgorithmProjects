//*************************************************************//
//******************Infix to Postfix***************************//
//*************************************************************//
#include <iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
void infixToPostfix(string s)
{
	//using built-in stack
	stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.empty()
				&& prec(s[i]) <= prec(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

float scanNum(char ch) {
	int value;
	value = ch;
	return float(value - '0');   //return float from character
}

int isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1;    //character is an operator
	return -1;   //not an operator
}

int isOperand(char ch) {
	if (ch >= '0' && ch <= '9')
		return 1;    //character is an operand
	return -1;   //not an operand
}

float operation(int a, int b, char op) {
	//Perform operation
	if (op == '+')
		return b + a;
	else if (op == '-')
		return b - a;
	else if (op == '*')
		return b * a;
	else if (op == '/')
		return b / a;
	else if (op == '^')
		return pow(b, a);    //find b^a
	else
		return INT_MIN;    //return negative infinity
}

float postfixEval(string postfix) {
	int a, b;
	stack<float> stk;
	string::iterator it;

	for (it = postfix.begin(); it != postfix.end(); it++) {
		//read elements and perform postfix evaluation
		if (isOperator(*it) != -1) {
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();
			stk.push(operation(a, b, *it));
		}
		else if (isOperand(*it) > 0) {
			stk.push(scanNum(*it));
		}
	}
	return stk.top();
}


int main()
{
	cout << "Example without brackets" << endl;
	cout << "Postfix Expression is:" << endl;
	string exp = ("4+8*3+9");
	infixToPostfix(exp);
	string post = "483*+9+";
	cout << "   *****************   " << endl;
	cout << "After evaluation, we have got this answer:" << postfixEval(post) << endl;
	cout << "******************************" << endl;
	cout << "Example with brackets" << endl;
	cout << "Postfix Expression is:" << endl;
	string exp1 = ("(4+8)*(3+9)");
	infixToPostfix(exp1);
	string post1 = "48+39+*";
	cout << "   *****************   " << endl;
	cout << "After evaluation, we have got this answer:" << postfixEval(post1) << endl;
}
