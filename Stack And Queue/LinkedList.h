#pragma once
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
struct node {
	T data;
	node* next;
};

template <class T>
node<T>* fMakeNode(T data) {
	node<T>* res = new node<T>;
	if (res == NULL) return NULL;
	res->data = data;
	res->next = NULL;
	return res;
}

template <class T>
bool fAddHead(node<T>*& head, node<T>*&tail, T data) {
	node<T>* cur = fMakeNode(data);
	if (cur == NULL) return false;
	cur->next = head;
	head = cur;
	if (cur->next == NULL) tail = cur;
	return true;
}

template <class T>
bool fAddTail(node<T>*& head, node<T>*& tail, T data) {
	node<T>* cur = fMakeNode(data);
	if (cur == NULL) return false;
	if (head == tail && tail == NULL) {
		head = tail = cur;
		return true;
	}
	tail->next = cur;
	tail = cur;
	return true;
}

template <class T>
bool fDeleteHead(node<T>*& head, node<T>*& tail, T &data) {
	if (head == NULL) return false;
	node<T>* oldHead = head;
	head = head->next;
	data = oldHead->data;
	delete oldHead;
	if (head == NULL) tail = NULL;
	return true;
}

template <class T>
bool fDeleteTail(node<T>*& head, node<T>*& tail, T& data) {
	if (tail == NULL) return false;
	if (head == tail) {
		data = head->data;
		delete head;
		head = tail = NULL;
		return true;
	}
	node<T>* cur = head;
	while (cur->next != tail) cur = cur->next;
	node<T>* oldTail = tail;
	tail = cur;
	tail->next = NULL;
	data = oldTail->data;
	delete oldTail;
	return true;
}

#endif