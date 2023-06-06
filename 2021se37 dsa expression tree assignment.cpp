// C++ implementation of the approach
#include <iostream>
#include<string>
#include<stack>
using namespace std;

// Tree Structure
typedef struct node
{
	char data; int value;
	struct node* left, * right;
} *nptr;

// Function to create new node
nptr newNode(char c)
{
	nptr n = new node;
	n->data = c;
	n->left = n->right = nullptr;
	return n;
}

// Function to build Expression Tree
nptr build(string& s)
{

	// Stack to hold nodes
	stack<nptr> stN;

	// Stack to hold chars
	stack<char> stC;
	nptr t, t1, t2;

	// Prioritising the operators
	int p[123] = { 0 };
	p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
		p[')'] = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') {

			// Push '(' in char stack
			stC.push(s[i]);
		}

		// Push the operands in node stack
		else if (isalpha(s[i]))
		{
			t = newNode(s[i]);
			stN.push(t);
		}
		else if (p[s[i]] > 0)
		{
			// If an operator with lower or
			// same associativity appears
			while (
				!stC.empty() && stC.top() != '('
				&& ((s[i] != '^' && p[stC.top()] >= p[s[i]])
					|| (s[i] == '^'
						&& p[stC.top()] > p[s[i]])))
			{

				// Get and remove the top element
				// from the character stack
				t = newNode(stC.top());
				stC.pop();

				// Get and remove the top element
				// from the node stack
				t1 = stN.top();
				stN.pop();

				// Get and remove the currently top
				// element from the node stack
				t2 = stN.top();
				stN.pop();

				// Update the tree
				t->left = t2;
				t->right = t1;

				// Push the node to the node stack
				stN.push(t);
			}

			// Push s[i] to char stack
			stC.push(s[i]);
		}
		else if (s[i] == ')') {
			while (!stC.empty() && stC.top() != '(')
			{
				t = newNode(stC.top());
				stC.pop();
				t1 = stN.top();
				stN.pop();
				t2 = stN.top();
				stN.pop();
				t->left = t2;
				t->right = t1;
				stN.push(t);
			}
			stC.pop();
		}
	}
	t = stN.top();
	return t;
}

// Function to print the post order
// traversal of the tree
void inorder(nptr root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data;
		inorder(root->right);

	}
}
void set_inorder(nptr root)
{
	if (root)
	{
		set_inorder(root->left);
		if (root->data != '(' && root->data != ')' && root->data != '+' && root->data != '*' && root->data != '-' && root->data != '/')
		{

			cout << "Enter value of " << root->data << endl;
			cin >> root->value;
			cout << endl;
		}
		set_inorder(root->right);
	}
}
void displayinorder(nptr root)
{
	if (root)
	{

		displayinorder(root->left);

		if (root->data != '(' && root->data != ')' && root->data != '+' && root->data != '*' && root->data != '-' && root->data != '/')
		{

			cout << root->data << " " << root->value << endl;

		}
		displayinorder(root->right);
	}

}

int eval(nptr root)
{
	// empty tree
	if (!root)
		return 0;

	// leaf node i.e, an integer
	if (root->left == NULL && root->right == NULL)
		return root->value;

	// Evaluate left subtree
	int l_val = eval(root->left);

	// Evaluate right subtree
	int r_val = eval(root->right);

	// Check which operator to apply
	if (root->data == '+')
		return l_val + r_val;

	if (root->data == '-')
		return l_val - r_val;

	if (root->data == '*')
		return l_val * r_val;

	if (r_val == 0) {
		cout << "Can't take 0 for division" << endl;
		set_inorder(root->right);
		int r_val = eval(root->right);
		return l_val / r_val;
	}
	return l_val / r_val;
}

// Driver code
int main()
{
	string s = "(a+b*c/d)";
	s = "(" + s;
	s += ")";
	nptr root = build(s);

	// Function call
	inorder(root);
	cout << endl;
	set_inorder(root);
	cout << "Values you have entered are:" << endl;
	displayinorder(root);
	cout << endl;

	cout << eval(root);
	return 0;
}