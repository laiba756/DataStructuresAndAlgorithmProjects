//********************************************//
//*************Link list based Queue**********//
//********************************************//

#include<iostream>
using namespace std;
class QNode {
public:
	int data;
	QNode* next;
	QNode(int v) {
		data = v;
		next = NULL;
	}
};
class Queue {
public:
	QNode* front, * end;
	Queue() {
		front = end = NULL;
	}
	void enque(int v) {
		QNode* newnode = new QNode(v);
		if (end == NULL) {
			front = end = newnode;
			return;
		}
			end->next = newnode;
			end = newnode;
	}
	bool isEmpty() {
		if (front == NULL) {
			return true ;
		}
		return false;
	}
	void deque() {
		QNode* temp;
		if (isEmpty()) {
			cout << "Queue is empty." << endl;
			return ;
		}
		else
 {
			temp = front;
			front = front->next;
			delete temp;

		}
	}
	void display() {
		QNode* temp = front;
		if (isEmpty()) {
			cout << "Queue is empty." << endl;
		}
		else
 {
			while (temp->next != NULL) {
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
	}
	
};
int main() {
	Queue Q;
	Q.enque(30);
	Q.enque(70);
	Q.enque(64);
	Q.display();
	Q.deque();
	Q.display();
}