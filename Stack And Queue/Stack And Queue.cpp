#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Reverse Polish Notation.h"

void fPrintLinkedList(node<int>* head) {
	cout << "Linked list: ";
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void fTest() {
	node<int>* head = NULL;
	node<int>* tail = NULL;
	bool b;
	while (1) {
		int choice;
		cin >> choice;
		if (choice == 1) {
			int data;
			cin >> data;
			fPrintLinkedList(head);
			b = fAddHead(head, tail, data);
			if (b) cout << "Success \n";
			else cout << "Failed\n";
			fPrintLinkedList(head);
		}
		else if (choice == 2) {
			int data;
			cin >> data;
			fPrintLinkedList(head);
			b = fAddTail(head, tail, data);
			if (b) cout << "Success \n";
			else cout << "Failed\n";
			fPrintLinkedList(head);
		}
		else if (choice == 3) {
			int data;
			fPrintLinkedList(head);
			b = fDeleteHead(head, tail, data);
			if (b) cout << "Success \nData: " << data << endl;
			else cout << "Failed\n";
			fPrintLinkedList(head);
		}
		else if (choice == 4) {
			int data;
			fPrintLinkedList(head);
			b = fDeleteTail(head, tail, data);
			if (b) cout << "Success \nData: " << data << endl;
			else cout << "Failed\n";
			fPrintLinkedList(head);
		}
		else break;
	}
}

void fTestStack() {
	stack<int>s;
	int data;
	bool b;
	while (1) {
		int choice;
		cin >> choice;
		if (choice == 1) {

			cin >> data;
			b = s.mPushBack(data);
			if (b) cout << "Success\n";
			else cout << "Failed\n";
		}
		else if (choice == 2) {
			b = s.mPopBack(data);
			if (b) cout << "Data: " << data << endl;
			else cout << "Empty stack\n";
		}
		else break;
	}
}

void fTestQueue() {
	queue<int>q;
	int data;
	bool b;
	while (1) {
		int choice;
		cin >> choice;
		if (choice == 1) {

			cin >> data;
			b = q.mPushBack(data);
			if (b) cout << "Success\n";
			else cout << "Failed\n";
		}
		else if (choice == 2) {
			b = q.mPopHead(data);
			if (b) cout << "Data: " << data << endl;
			else cout << "Empty queue\n";
		}
		else break;
	}
}

void fTestRPN() {
	string a;
	cin >> a;
	int res;
	bool b=fRPN(a, res);
	if (!b) {
		cout << "Vui long kiem tra lai bieu thuc\n";
	}
	else {
		cout << "Gia tri bieu thuc: " << res << endl;
	}
}

int main() {
	
	fTestRPN();
}