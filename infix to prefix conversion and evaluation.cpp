//*************************************************************//
//******************Infix to Prefix***************************//
//*************************************************************//

#include <iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

bool isOperator(char c)
{
	return (!isalpha(c) && !isdigit(c));
}

int prec(char C)
{
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	return 0;
}

string infixToPostfix(string s)
{
	s = '(' + s + ')';

	stack<char> st;
	string result;

	for (int i = 0; i < s.size(); i++) {

		// If scanned character is operand, add it to string.
		if (isalpha(s[i]) || isdigit(s[i]))
			result += s[i];

		// If the scanned character is an ‘(‘, push it to the stack.
		else if (s[i] == '(')
			st.push('(');

		// If the scanned character is an
		// ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (s[i] == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}

			// Remove '(' from the stack
			st.pop();
		}

		// Operator found
		else
		{
			if (isOperator(st.top()))
			{
				if (s[i] == '^')
				{
					while (prec(s[i]) <= prec(st.top()))
					{
						result += st.top();
						st.pop();
					}

				}
				else
				{
					while (prec(s[i]) < prec(st.top()))
					{
						result += st.top();
						st.pop();
					}

				}

				// Push current Operator on stack
				st.push(s[i]);
			}
		}
	}
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	return result;
}

string infixToPrefix(string s)
{
	/* Reverse String
	* Replace ( with ) and vice versa
	* Get Postfix
	* Reverse Postfix * */

	// Reverse infix
	reverse(s.begin(), s.end());

	// Replace ( with ) and vice versa
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '(') {
			s[i] = ')';
		}
		else if (s[i] == ')') {
			s[i] = '(';
		}
	}

	string prefix = infixToPostfix(s);

	// Reverse postfix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}
bool isOperand(char c)
{
	// If the character is a digit then it must be an operand
	return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
	stack<double> Stack;

	for (int j = exprsn.size() - 1; j >= 0; j--) {

		// Push operand to Stack
		// To convert exprsn[j] to digit subtract
		// '0' from exprsn[j].
		if (isOperand(exprsn[j]))
			Stack.push(exprsn[j] - '0');

		else {

			// Operator encountered
			// Pop two elements from Stack
			double o1 = Stack.top();
			Stack.pop();
			double o2 = Stack.top();
			Stack.pop();

			// Use switch case to operate on o1
			// and o2 and perform o1 O o2.
			switch (exprsn[j]) {
			case '+':
				Stack.push(o1 + o2);
				break;
			case '-':
				Stack.push(o1 - o2);
				break;
			case '*':
				Stack.push(o1 * o2);
				break;
			case '/':
				Stack.push(o1 / o2);
				break;
			}
		}
	}

	return Stack.top();
}
int main()
{
	cout << "Example without brackets" << endl;
	cout << "Prefix Expression is:" << endl;
	string exp = ("4+7*9+2");
	cout << infixToPrefix(exp) << endl;
	cout << "   *****************   " << endl;
	cout << "After evaluation, we have got this answer:" << endl;
	string exprsn = "++4*792";
	cout << evaluatePrefix(exprsn) << endl;
	//ANOTHER EXAMPLE
	cout << "******************************" << endl;
	cout << "Example without brackets" << endl;
	cout << "Prefix Expression is:" << endl;
	string exp1 = ("(3+6)*(2+9)");
	cout << infixToPrefix(exp1) << endl;
	cout << "   ***************   " << endl;
	cout << "After evaluation, we have got this answer:" << endl;
	string exprsn1 = "*+36+29";
	cout << evaluatePrefix(exprsn1) << endl;


	return 0;
}

