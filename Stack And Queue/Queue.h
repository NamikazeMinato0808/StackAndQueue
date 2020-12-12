#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include "LinkedList.h"

template <class T>
struct queue {
	node<T>* head;
	node<T>* tail;
	queue() { head = NULL; tail = NULL; }
	bool mPushBack(T data);
	bool mPopHead(T& data);
	bool mIsEmpty();
	bool mGet(T& data);
};

template <class T>
bool queue<T>::mPushBack(T data) {
	return fAddTail(head, tail, data);
}

template <class T>
bool queue<T>::mPopHead(T& data) {
	return fDeleteHead(head, tail, data);
}

template <class T>
bool queue<T>::mIsEmpty() {
	return head == NULL;
}

template <class T>
bool queue<T>::mGet(T& data) {
	if (mIsEmpty()) return false;
	data = head->data;
	return true;
}

#endif