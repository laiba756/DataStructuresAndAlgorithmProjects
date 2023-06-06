
#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* pre;
	Node(int val) {

		data = val;
		next = NULL;
		pre = NULL;
	}
};
class LinkList
{
public:
	Node* head = nullptr;
	Node* tail = nullptr;
	int pos;
	LinkList() {

		head = tail = NULL;

	}
	Node* temp = nullptr;
	//int choice = 1;
	void insertd(int val)
	{

		Node* mynode = new Node(val);



		if (head == NULL)
		{
			head = tail = mynode;
		}
		else
		{
			tail->next = mynode;
			mynode->pre = tail;
			tail = mynode;
		}

	}


	void insertdatbeg(int val) {
		Node* newnode = new Node(val);
		if (head == NULL) {
			head = tail = newnode;
		}

		else {
			head->pre = newnode;
			newnode->next = head;
			head = newnode;
		}
	}

	void insertdatEnd(int val) {
		Node* newnode = new Node(val);

		if (head == NULL) {
			head = tail = newnode;
		}

		else {
			Node* temp = head;

			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newnode;
			newnode->pre = temp;
			tail = newnode;
		}
	}
	void deletedfrombeg() {
		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* temp = head;
			head = head->next;
			head->pre = NULL;
			delete temp;
		}
	}
	void deletedfromend() {
		if (tail == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* temp = tail;
			// tail->pre->next=NULL;
			tail = tail->pre;
			tail->next = NULL;
			delete temp;
		}
	}



	void display()
	{

		if (head == NULL) {
			cout << "List is empty" << endl;
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				cout << temp->data << "\t" << endl;
				temp = temp->next;
			}
		}
	}
};
int main() {
	LinkList L;
	cout << "Linked list after insertion of elements:" << endl;
	//L.insertd(20);
	//L.insertd(30);
	L.insertdatbeg(9);
	L.insertdatbeg(90);
	//L.insertd(40);
	//L.insertdatEnd(7);
	L.display();
	/*cout << "After deletion from beginning:" << endl;
	L.deletedfrombeg();
	L.display();
	cout << "After deletion from ending:" << endl;
	L.deletedfromend();
	L.display();*/

}


