
#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int val) {

		data = val;
		next = NULL;
	}
};
class LinkList
{
public:
	Node* head = nullptr;
	LinkList() {

		head = NULL;
	}
	Node* temp = nullptr;
	//int choice = 1;
	void insert(int val)
	{

		Node* newnode = new Node(val);


		if (head == NULL)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}

	}

//	void insertatbeginning(int val)
//	{
//
//		Node* newnode = new Node(val);
//		if (head == NULL) {
//			head = temp = newnode;
//		}
//		else {
//			newnode->next = head;
//			head = newnode;
//		}
//	}
//
//	void insertatEnd(int val) {
//		Node* newnode = new Node(val);
//
//		if (head == NULL) {
//			head = newnode;
//		}
//		else {
//			Node* temp = head;
//			while (temp->next != NULL) {
//				temp = temp->next;
//			}
//			temp->next = newnode;
//			temp = newnode;
//		}
//	}
//	void getlength() {
//		int count = 0;
//		Node* temp = head;
//		while (temp != 0) {
//			count++;
//			temp = temp->next;
//		}
//		cout << "Length of list is:" << count << endl;
//	}
//
	bool searchele(int val)
	{
		Node* temp = head; // Initialize current
		while (temp != NULL) {
			if (temp->data == val)
				return true;
			temp = temp->next;
		}
		return false;
	}
//
//	void update_data(int val, int nv) {
//
//
//		if (head == NULL) {
//			cout<<"Linked List not initialized";
//			return;
//		}
//
//		 Node *temp = head;
//		while (temp->next != NULL) {
//			if (temp->data == val) {
//				temp->data = nv;				
//			}
//			temp = temp->next;
//		}
//	}
//	void InsertAfterValue(int val, int nv) {
//
//		Node* mynode = new Node(nv);
//		Node* temp = head;
//		while (temp->data != val) {
//			temp = temp->next;
//		}
//		mynode->next = temp->next;
//		temp->next = mynode;
//
//	}
	void sortList() {
		//Node current will point to head  
	 Node* current = head, * index = NULL;
		string temp;

		if (head == NULL) {
			return;
		}
		else {
			while (current != NULL) {
				//Node index will point to node next to current  
				index = current->next;

				while (index != NULL) {
					//If current node's data is greater than index's node data, swap the data between them  
					if (current->data > index->data) {
						temp = current->data;
						current->data = index->data;
						index->data = temp;
					}
					index = index->next;
				}
				current = current->next;
			}
		}
	}

//	void deleteatBeginning() {
//		if (head == NULL) {
//			cout << "List is empty" << endl;
//		}
//		else {
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//		}
//	}
//	/*void deleteatEnd() {
//
//		Node* temp = head;
//		while (temp->next->next != NULL) {
//			temp = temp->next;
//		}
//		temp->next = NULL;
//
//	}*/
//
//	void deleteatEnd() {
//		Node* tail=nullptr;
//		Node* prenode, * temp;
//		prenode = head;
//		while (prenode->next->next != nullptr) {
//			prenode = prenode->next;
//		}
//		temp = tail;
//		tail = prenode;
//		tail->next = nullptr;
//		delete temp;
//		temp = nullptr;
//
//	}
//	void deleteval(int val) {
//		Node* pre = NULL;
//		while (temp != NULL && temp->data != val)
//		{
//			pre = temp;
//			temp = temp->next;
//		}
//
//		// If key was not present in linked list
//		if (temp == NULL)
//			return;
//
//		// Unlink the node from linked list
//		pre->next = temp->next;
//
//		// Free memory
//		delete temp;
//	
//	}
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
	cout << "Elements of link list are:" << endl;
L.insert(29);
L.insert(0);
	L.insert(70);
	L.display();
//	cout << "Link list after insertion at beginning and ending is:" << endl;
//	L.insertatbeginning(3000);
//	L.insertatEnd(70);
//	L.display();
//	L.getlength();
	L.searchele(70) ? cout << "Yes, Searched element is present in list" << endl : cout << "Ele not found" << endl;
//	cout << endl;
//	cout << "List after updation of new value is:" << endl;
//	L.update_data(30, 37);
//	L.display();
//	L.InsertAfterValue(70,90);
//	cout << "List after inserting node after a value is:" << endl;
//	L.display();
	L.sortList();
	cout << "Sorted list is:" << endl;
	L.display();
//	cout << "After deletion at beginning" << endl;
//	L.deleteatBeginning();
//	L.display();
//	L.getlength();
//	cout << "After deletion at ending" << endl;
//	L.deleteatEnd();
//	L.display();
//	L.getlength();
//	L.deleteval(1000);
//	cout << "After deleting a specific value:" << endl;
//	L.display();
//}



//#include<iostream>
//using namespace std;
//class Node {
//private:
//	int data;
//	Node* next;
//public:
//	Node(int val) {
//
//		data = val;
//		next = NULL;
//	}
//	friend class LinkList;
//};
//class LinkList
//{
//private:
//	Node* head = nullptr;
//public:
//	LinkList() {
//
//		head = NULL;
//	}
//	Node* temp = nullptr;
//	//int choice = 1;
//	void getinsert()
//	{
//		
//		Node* newnode = new Node(getval());
//		
//
//		if (head == NULL)
//		{
//			head = temp = newnode;
//		}
//		else
	/*	{
			temp->next = newnode;
			temp = newnode;
		}

	}
	int getval() {
		int val;
		cout << " Enter Number = ";
		cin >> val;
		return val;
	}
	void getbeginning()
	{
		
		Node* newnode = new Node(getval());
		if (head == NULL) {
			head = temp = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}*/

	/*void getEnd() {
		
		Node* newnode = new Node(getval());

		if (head == NULL) {
			head = newnode;
		}
		else {
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newnode;
			temp = newnode;
		}
	}
	void getlength() {
		int count = 0;
		Node* temp = head;
		while (temp != 0) {
			count++;
			temp = temp->next;
		}
	//	cout <<*/ "Length of list is:" << count << endl;
	//}

	//bool searchele()
	//{
	//	int val=getval();
	//	Node* temp = head; // Initialize current
	//	while (temp != NULL) {
	//		if (temp->data == val)
	//			return true;
	//		temp = temp->next;
	//	}
	//	return false;
	//}

	//void update_data(int val, int nv) {


	//	if (head == NULL) {
	//		cout << "Linked List not initialized";
	//		return;
//		}
//
//		Node* temp = head;
//		while (temp->next != NULL) {
//			if (temp->data == val) {
//				temp->data = nv;
//			}
//			temp = temp->next;
//		}
//	}
//	void InsertAfterValue(int val, int nv) {
//
//		Node* mynode = new Node(nv);
//		Node* temp = head;
//		while (temp->data != val) {
//			temp = temp->next;
//		}
//		mynode->next = temp->next;
//		temp->next = mynode;
//
//	}
//	void sortList() {
//		//Node current will point to head  
//		Node* current = head, * index = NULL;
//		int temp;
//
//		if (head == NULL) {
//			return;
//		}
//		else {
//			while (current != NULL) {
//				//Node index will point to node next to current  
//				index = current->next;
//
//				while (index != NULL) {
//					//If current node's data is greater than index's node data, swap the data between them  
//					if (current->data > index->data) {
//						temp = current->data;
//						current->data = index->data;
//						index->data = temp;     //yeh agr yad na rahay to a=b then b=c then c=a;,
//					}
//					index = index->next;
//				}
//				current = current->next;
//			}
//		}
//	}
//
//	void deleteatBeginning() {
//		if (head == NULL) {
//			cout << "List is empty" << endl;
//		}
//		else {
//			Node* temp = head;
//			head = head->next;
//			delete temp;
//		}
//	}
//	void deleteatEnd() {
//		Node* prenode, * temp;
//		Node* tail = nullptr;
//		prenode = head;
//		while (prenode->next->next != nullptr) {
//			prenode = prenode->next;
//		}
//		temp = tail;
//		tail = prenode;
//		tail->next = nullptr;
//		delete temp;
//		temp = nullptr;	
//	}
//	void deleteval(int val) {
//		Node* pre = head;
//		while (temp != NULL && temp->data != val)
//		{
//			pre = temp;
//			temp = temp->next;
//		}
//		// If key was not present in linked list
//		if (temp == NULL)
//			return;
//		// Unlink the node from linked list
//		pre->next = temp->next;   
//		// Free memory
//		delete temp;
//	}
//	void display()
//	{
//
//		if (head == NULL) {
//			cout << "List is empty" << endl;
//		}
//		else {
//			Node* temp = head;
//			while (temp != NULL) {
//				cout << temp->data << "\t" << endl;
//				temp = temp->next;
//			}
//		}
//	}
//};
//int main() {
//	cout << "*************1000,70,30 abhi lazmi values enter krna******" << endl;
//	LinkList L;
//	cout << "Elements of link list are:" << endl;
//	L.getinsert();
//	L.getinsert();
//	L.getinsert();
//	L.display();
//	cout << "Link list after insertion at beginning and ending is:" << endl;
//	L.getbeginning();
//	L.getEnd();
//	L.display();
//	L.getlength();
//	L.searchele() ? cout << "Yes, Searched element is present in list" << endl : cout << "Ele not found" << endl;
//	cout << endl;
//	cout << "List after updation of new value is:" << endl;
//	L.update_data(30, 37);
//	L.display();
//	L.InsertAfterValue(70, 90); //filhal aik val 70 lazmi rakho
//	cout << "List after inserting node after a value is:" << endl;
//	L.display();
//	L.sortList();
//	cout << "Sorted list is:" << endl;
//	L.display();
//	cout << "After deletion at beginning" << endl;
//	L.deleteatBeginning();
//	L.display();
//	L.getlength();
//	cout << "After deletion at ending" << endl;
//	L.deleteatEnd();
//	L.display();
//	L.getlength();
//	L.deleteval(1000);  //filhal 1000, 70 and 30 lazmi rakhnay hain
//	cout << "After deleting a specific value:" << endl;
//	L.display();
//}

//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next;
//	Node* prev;
//
//	Node() {
//		data = 0;
//		next = NULL;
//		prev = NULL;
//	}
//};
//
//class linkList {
//private:
//	Node* head = NULL;
//public:
//	void getHead() {
//		int val;
//		cout << " Enter number to add at head = ";
//		cin >> val;
//		Node* node = new Node;
//		node->data = val;
//		if (head == NULL) {
//			node->next = NULL;
//			node->prev = NULL;
//			head = node;
//		}
	//	else
	//	{
	//		node->next = head;
	//		node->prev = NULL;
	//		head->prev = node;
	//		head = node;
	//	}
	//}

	//void getTail() {
	//	int val;
	//	cout << " Enter Number to add at tail = ";
	//	cin >> val;
	//	Node* node = new Node;
	//	Node* runner = head;
	//	node->data = val;

	//	if (head == NULL) {
	//		node->next = NULL;
	//		node->prev = NULL;
	//		head = node;
	//	}
	//	else
	//	{
	//		while (runner->next != NULL) {
	//			runner = runner->next;
	//		}
	//		runner->next = node;
	//		node->prev = runner;
	//		node->next = NULL;
	//	}
	//}

	/*void display() {
		Node* runner = head;
		Node* tail = NULL;
		while (runner != NULL)
		{
			tail = runner;
			cout << runner->data << " -> ";
			runner = runner->next;
		}
		cout << " NULL \n";

		while (tail != NULL)
		{
			cout << tail->data << " -> ";
			tail = tail->prev;
		}
		cout << " NULL \n";
	}

	void del() {
		bool flag = false;
		int del;
		cout << " Enter number to del = ";
		cin >> del;*/

		//Node* runner = head;
		//Node* temp = head;

		//while (temp != NULL)
		//{
		//	if (temp->data == del) {
		//		flag = true;
		//		break;
		//	}
		//	temp = temp->next;
		//}
		//if (flag) {
		//	if (runner->data == del) {
		//		head = runner->next;
		//		head->prev = NULL;
		//	}
		//	while (runner->next->data != del)
		//	{
	//			runner = runner->next;
	//		}
	//		Node* delVal = runner->next;
	//		runner->next = runner->next->next;
	//		runner->next->prev = runner;
	//		delete delVal;
	//	}
	//	else
	//	{
	//		cout << " NUMBER ! EXIST \n";
	//	}

	//}

	//int menu() {
	/*	int choice = 0;
		cout << " 1. Enter 1 to get head \n";
		cout << " 2. Enter 2 to get tail \n";
		cout << " 3. Enter 3 to delete node \n";
		cout << " 4. Enter 4 to display \n";
		cout << " Enter -1 to STOP!\n";

		cout << " ================================= \n";
		cout << " ================================= \n";
		cout << " Enter Your Choice = ";
		cin >> choice;

		return choice;
	}


};

int main() {
	linkList obj;
	int choice = 0;
	do*/
	/*{
		cout << endl << endl;
		choice = obj.menu();

		if (choice == 1) {
			obj.getHead();
		}
		else if (choice == 2) {
			obj.getTail();
		}
		else if (choice == 3) {
			obj.del();
		}
		else if (choice == 4) {
			obj.display();
		}
		else
		{
			cout << " INVALID CHOICE!\n";
		}*/


	/*} while (choice != -1);

	return 0;
}*/






