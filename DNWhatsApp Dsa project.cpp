#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class WNode {   //numbers database
public:
	string data;  //number
	WNode* next;
	WNode(string d)
	{
		data = d;
		next = NULL;
	}
};
class Num {
public:
	WNode* front, * rear;
	Num() {
		front = rear = NULL;
	}
	~Num() {
		delete front, rear;
	}

	//insertnum
	void insertyournum(string x)
	{
		WNode* temp = new WNode(x);

		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;   //TEMP INSERT KRANA HAI NA
		rear = temp;

	}
	void insert(WNode** head_ref, string d)
	{
		// allocate node
		WNode* new_node = new WNode(d);

		// make next of new node as head
		new_node->next = (*head_ref);

		// move the head to point to the new node
		(*head_ref) = new_node;
	}
	bool searchele(string n)
	{
		WNode* temp = front; // Initialize current
		while (temp != NULL) {
			if (temp->data == n) {
				cout << "---------------------" << endl;
				cout << "You account is already registered. You are now logged in." << endl;
				cout << "You may proceed your further activities." << endl;
				cout << "---------------------" << endl;
				return true;
			}
			temp = temp->next;
		}
		cout << "Account with entered number is not yet registered." << endl;
		return false;
	}
};
//Node Class For User1 
class LNode {
public:
	string data;  //msg
	LNode* next;
	LNode(string d)
	{
		data = d;
		next = NULL;
	}
};
//User1
class User1 {
public:
	LNode* front, * rear;
	User1() {
		front = rear = NULL;
	}
	~User1() {
		delete front, rear;
	}
	string getmsg() {
		string x;
		cout << " Type your message:";
		cin >> x;
		return x;
	}
	//send1
	void send1()
	{
		LNode* temp = new LNode(getmsg());


		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;   //TEMP INSERT KRANA HAI NA
		rear = temp;
	}
	bool isEmpty() {
		if (front == NULL) {
			cout << "No message yet" << endl;
			return true;
		}
		return false;
	}
	//del msg
	void deQueue1()    //to be deleted
	{
		string val;
		if (isEmpty()) {
			//return;
			cout << " ";
		}
		LNode* temp = front;
		val = temp->data;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete (temp);
		//return val;
	}

	//display user1's msgs
	void display1()
	{
		if (isEmpty()) {
			return;
		}
		else {
			LNode* temp = front;
			cout << "User 1: \n Message:" << endl;
			while (temp != NULL) {
				cout << temp->data << "\t" << endl;
				temp = temp->next;
			}
		}
	}
};


//Node contact class
class LNodecon {
public:
	string name;  //name
	string num;    //number
	LNodecon* next;
	LNodecon(string n, string nu)
	{
		name = n;
		num = nu;
		next = NULL;
	}
};
//contact class
class Contact {
public:
	LNodecon* front, * rear;
	Contact() {
		front = rear = NULL;
	}
	~Contact() {
		delete front, rear;
	}
	string getname() {
		string c;
		cout << " Add contact name:";
		cin >> c;
		return c;
	}
	string getnum() {
		string x;
		cout << " Add contact num:";
		cin >> x;
		return x;
	}
	//insertcon
	void insertcon()
	{
		LNodecon* temp = new LNodecon(getname(), getnum());


		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;   //TEMP INSERT KRANA HAI NA
		rear = temp;
	}
	bool isEmptycon() {
		if (front == NULL) {
			cout << "No contact yet" << endl;
			return true;
		}
		return false;
	}

	//deletecon
	void deQueuecon()    //to be deleted
	{
		string val;
		if (isEmptycon()) {
			//return;
			cout << " ";
		}
		LNodecon* temp = front;
		val = temp->name;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete (temp);

	}

	//display contact
	void displaycon()
	{
		if (isEmptycon()) {
			return;
		}
		else {
			LNodecon* temp = front;
			cout << "Contact List:" << endl;
			while (temp != NULL) {
				cout << " " << temp->name << "\t" << temp->num << endl;
				temp = temp->next;
			}
		}
	}
};
//Node class for user 2
class LNode2 {
public:
	string data;  //msg
	LNode2* next;
	LNode2(string d)
	{
		data = d;
		next = NULL;
	}
};
//user 2 class
class User2 {
public:
	LNode2* front, * rear;
	User2() {
		front = rear = NULL;
	}
	~User2() {
		delete front, rear;
	}
	string getmsg() {
		string x;
		cout << " Type your message:";
		cin >> x;
		return x;
	}
	//send2
	void send2()
	{
		LNode2* temp = new LNode2(getmsg());


		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;   //TEMP INSERT KRANA HAI NA
		rear = temp;
	}
	bool isEmpty2() {
		if (front == NULL) {
			cout << "No message yet" << endl;
			return true;
		}
		return false;
	}
	void deQueue2()    //to be deleted
	{
		string val;
		if (isEmpty2()) {
			//return;
			cout << " ";
		}
		LNode2* temp = front;
		val = temp->data;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete (temp);
		//return val;
	}

	//msgs of user 2
	void display2()
	{
		if (isEmpty2()) {
			return;
		}
		else {
			LNode2* temp = front;
			cout << "User2: \n Message:" << endl;
			while (temp != NULL) {
				cout << temp->data << "\t" << endl;
				temp = temp->next;
			}
		}
	}
};
//node class for about
class ANode {
public:
	string data;  //about
	ANode* next;
	ANode(string d)
	{
		data = d;
		next = NULL;
	}
};
//about
class about {
public:
	ANode* front, * rear;
	about() {
		front = rear = NULL;
	}
	~about() {
		delete front, rear;
	}
	string getabout() {
		string x;
		cout << " Let your contacts bit about yourself:";
		cin >> x;
		return x;
	}
	//addabout
	void addabout()
	{
		ANode* temp = new ANode(getabout());


		if (rear == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;   //TEMP INSERT KRANA HAI NA
		rear = temp;
	}
	bool isEmpty() {
		if (front == NULL) {
			cout << "No about yet" << endl;
			return true;
		}
		return false;
	}
	//del about
	void deQueueabout()    //to be deleted
	{
		string val;
		if (isEmpty()) {
			//return;
			cout << " ";
		}
		ANode* temp = front;
		val = temp->data;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		delete (temp);
		//return val;
	}

	//display about
	void displayabout()
	{
		if (isEmpty()) {
			return;
		}
		else {
			ANode* temp = front;
			cout << "About:" << endl;
			while (temp != NULL) {
			cout << temp->data << "\t" << endl;
			temp = temp->next;
	}
		}
	}
};
int main()
{

	Num n;
	ifstream input_file("DNWhatsAppDB.txt");
	//to get contact info from file and storing it into variables
	string  num;
	//if no data in file or incorrect file
	if (!input_file) {
		cout << "Error reading from input file. File Directory may be incorrect" << endl;
		cout << "---------------" << endl;
	}

	else {
		while (input_file >> num)     //reading contacts from file
		{
			n.insert(&n.front, num);     //storing contacts into link list
		}
	}

	//to get number from user
	string x;
	cout << " Enter your Registered Number consisting of 11 digits:";
	cin >> x;

	if (n.searchele(x)) {
		User1 q;
		User2 q2;
		Contact q3;
		about a;
		int ch;
		while (1)
		{
			cout << "---------------------------------------------------" << endl;
			cout << "\n\t --------- DN WHATSAPP --------  \n";
			cout << "Press 1 to add new contact: \n";
			cout << "Press 2 to delete contact: \n";
			cout << "Press 3 to display contacts in Phonelist: \n";
			cout << "  ---------------- " << endl;
			cout << "Press 4 to send message by user 1: \n";
			cout << "Press 5 to delete message by user 1: \n";
			cout << "Press 6 to display message on sender 1 screen: \n";
			cout << "Press 7 to display message by sender 1 on sender 2 screen: \n";
			cout << "  ---------------- " << endl;
			cout << "Press 8 to send message by user 2: \n";
			cout << "Press 9 to delete message by user 2: \n";
			cout << "Press 10 to display message on sender 2 screen: \n";
			cout << "Press 11 to display message by sender 1 on sender 2 screen: \n";
			cout << "  ---------------- " << endl;
			cout << "Press 12 to add about: \n";
			cout << "Press 13 to delete about: \n";
			cout << "Press 14 to display about: \n";
			cout << "  ---------------- " << endl;
			cout << "Press 15 to Exit: \n";
			cout << "  ---------------- " << endl;
			cout << " Enter choice: \n";
			cin >> ch;
			cout << "  ---------------- " << endl;
			switch (ch)
			{
			case 1:
				q3.insertcon();
				break;
			case 2:
				q3.deQueuecon();
				q3.displaycon();
				break;
			case 3:
				q3.displaycon();
				break;
			case 4: //send1
				q.send1();
				break;
			case 5:  //del1
				q.deQueue1();
				q.display1();
				break;
			case 6:  //disscreen1
				q.display1();
				break;
			case 7:  //received by 1 from 2
				q2.display2();
				break;
			case 8: //send2
				q2.send2();
				break;
			case 9:  //del2
				q2.deQueue2();
				q2.display2();
				break;
			case 10:  //disscreen2
				q2.display2();
				break;
			case 11:  //received by 2 to 1
				q.display1();
				break;
			case 12:
				a.addabout();
				break;
			case 13:
				a.deQueueabout();
				a.displayabout();
				break;
			case 14:
				a.displayabout();
				break;
			case 15:
				return 0;

			default:
				cout << "Invalid choice:\n";
			}
		}
		return 0;
	}
	else {
		cout << " " << endl;
	}
}