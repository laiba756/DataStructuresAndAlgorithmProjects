//This program is going to read unsorted list of contacts , then will store them in link list, apply merge sort alggorithm
//to sort names of contacts then write sorted list of contacts to another file
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

//A linked list node
class Node
{
public:
	string name;
	string num;
	Node* next;

	//default constructor
	Node() {
		next = NULL;
	}

	//parametrized constructor
	Node(string na, string n) {
		name = na;
		num = n;
		next = NULL;
	}
};

//link list class
class LinkedList {
public:

	Node* head;
	//default constructor
	LinkedList() {
		head = nullptr;
	}

	//to insert contacts into link list
	void insert(Node** head_ref, string na, string n)
	{
		// allocate node
		Node* new_node = new Node();

		// put in the data
		new_node->name = na;
		new_node->num = n;
		// make next of new node as head
		new_node->next = (*head_ref);

		// move the head to point to the new node
		(*head_ref) = new_node;
	}

	// sorts the linked list by changing next pointers (not data) 
	void MergeSort(Node** headRef)
	{
		Node* head = *headRef;
		Node* a;
		Node* b;

		// base case 
		if ((head == NULL) || (head->next == NULL)) {
			return;   //no need to sort cz only one element is there
		}

		// split head into 'a' and 'b' sublists 
		FrontBackSplit(head, &a, &b);

		// recursively sort the sublists 
		MergeSort(&a);
		MergeSort(&b);

		// answer = merge the two sorted lists together 
		*headRef = SortedMerge(a, b);
	}

	//merging sorted lists
	Node* SortedMerge(Node* a, Node* b)
	{
		Node* result = NULL;

		// base cases 
		if (a == NULL)
			return (b);
		else if (b == NULL)
			return (a);

		// pick either a or b, and recur 
		if (a->name <= b->name) {
			result = a;
			result->next = SortedMerge(a->next, b);
		}
		else {
			result = b;
			result->next = SortedMerge(a, b->next);
		}
		return (result);
	}

	//function to split list into sublists
	void FrontBackSplit(Node* head,
		Node** first, Node** second)
	{
		Node* slow;     //will make u reach till mid
		Node* fast;   //from mid till end of list

		slow = head;  //head
		fast = head->next;   //2nd element say start hota hai

		while (fast != NULL) {    //reach at end of list
			fast = fast->next;   //jumping for first time  
			if (fast != NULL) {
				slow = slow->next;   //jumping for first time--such that slow jumps through one node
				fast = fast->next;   //jumping for second time--such that fast jumps through two nodes as compared to slow ptr
			}
		}

		*first = head;      //pointing to start of list
		*second = slow->next;   //points to mid but lists to be divided are still in connection with each other
		slow->next = NULL;     //solution to split two lists
	}

	//display function
	void printList(Node* node)
	{
		if (node == NULL) {
			cout << "No contacts. Empty list" << endl;
		}
		else {
			while (node != NULL)
			{
				cout << " " << node->name << " " << node->num << endl;
				node = node->next;
				cout << endl;
			}
		}
	}

};

//main function
int main()
{
	LinkedList l;    //obj of linklist

	cout << "This program is going to read unsorted list of contacts ,";
		cout<<"then will store them in link list, apply merge sort algorithm ";
		cout << "to sort names of contacts then write sorted list of contacts to another file" << endl;
		cout << "-------------" << endl << endl;
	// Opening file for reading contacts in file
	ifstream input_file("conn.docs");

	//to get contact info from file and storing it into two variables
	string name, num;

	//if no data in file or incorrect file
	if (!input_file) {
		cout << "Error reading from input file. File Directory may be incorrect" << endl;
		cout << "---------------" << endl;
	}

	else {
		while (input_file >> name >> num)     //reading unsorted contacts from file
		{
			l.insert(&l.head, name, num);     //storing contacts into link list
		}
	}
	cout << "Contacts in my Phone list are:" << endl << endl;
	l.printList(l.head);        //printing unsorted contacts
	cout << endl << endl << endl;

	// Closing the file
	input_file.close();


	l.MergeSort(&l.head);    //sorting the link list
	cout << "--------------------" << endl;
	cout << "After applying Merge Sort, Now contacts are in sorted order as following:" << endl << endl;
	l.printList(l.head);     //printing sorted contacts

	// Opening output file for writing sorted contacts
	ofstream output_file("sortcon.txt");

	while (l.head != NULL) {
		output_file << l.head->name << "\t" << l.head->num << endl;
		l.head = l.head->next; ;   //sorted contacts being written to file
	}
	// Closing the output file
	output_file.close();

	return 0;
}





