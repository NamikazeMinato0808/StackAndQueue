#pragma once
#ifndef _STACK_H
#define _STACK_H

#include "LinkedList.h"

template <class T>
struct stack {
	node<T>* head;
	node<T>* tail;
	stack() { head = NULL; tail = NULL; }
	bool mPushBack(T data);
	bool mPopBack(T& data);
	bool mIsEmpty();
	bool mGet(T& data);
};

template<class T>
bool stack<T>::mPushBack(T data) {
	return fAddTail(head, tail, data);
}

template <class T>
bool stack<T>::mPopBack(T& data) {
	return fDeleteTail(head, tail, data);
}

template <class T>
bool stack<T>::mIsEmpty() {
	return head == NULL;
}

template <class T>
bool stack<T>::mGet(T& data) {
	if (mIsEmpty()) return false;
	data = tail->data;
	return true;
}


#endif