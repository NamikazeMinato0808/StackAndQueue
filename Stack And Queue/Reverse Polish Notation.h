#pragma once
#ifndef _REVERSEPOLISHNOTATION_H
#define _REVERSEPOLISHNOTATION_H

#include "Stack.h"
#include "Queue.h"

#include <string>

struct object {
	int type; //0: toan hang ;  1: ngoac mo ; 2: ngoac dong ; 3: + - ; 4: * /
	int data; //0: ( ;  1: ) ; 2: + ; 3: - ; 4: * ; 5: / 
};

void fPrintAllQueue(queue<object>q) {
	while (!q.mIsEmpty()) {
		object data;
		bool b = q.mPopHead(data);
		cout << "{ " << data.type << " , " << data.data << " }\n";
	}
}

bool fRPN(string a, int &res) {
	stack<object>s;
	queue<object>q;
	int i = 0;
	int n = a.size();
	bool b;
	object tmp;
	while (i < n) {
		if (a[i] == '(') {
			s.mPushBack({ 1,0 });
			i++;
		}
		else if (a[i] == ')') {
			b = s.mPopBack(tmp);
			if (!b) return false;
			if (tmp.type != 1) {
				q.mPushBack(tmp);
			}
			else {
				i++;
			}
		}
		else if (a[i] >= '0' && a[i] <= '9') {
			int data = 0;
			while (a[i] >= '0' && a[i] <= '9') {
				data = data * 10 + a[i] - '0';
				i++;
			}
			q.mPushBack({ 0, data });
		}
		else {
			if (a[i] == '+') {
				tmp = { 3, 2 };
			}
			else if (a[i] == '-') {
				tmp = { 3,3 };
			}
			else if (a[i] == '*') {
				tmp = { 4,4 };
			}
			else tmp = { 4,5 };
			object tmp2;
			while (1) {
				b = s.mPopBack(tmp2);
				if (!b) {
					s.mPushBack(tmp);
					break;
				}
				else if (tmp2.type < tmp.type) {
					s.mPushBack(tmp2);
					s.mPushBack(tmp);
					break;
				}
				else {
					q.mPushBack(tmp2);
				}
			}
			i++;
		}
	}
	while (!s.mIsEmpty()) {
		b = s.mPopBack(tmp);
		if (tmp.type == 1) return false;
		b = q.mPushBack(tmp);
	}
	while (q.mPopHead(tmp)) {
		if (tmp.type == 0) s.mPushBack(tmp);
		else {
			object data1;
			object data2;
			b = s.mPopBack(data1);
			if (!b) return false;
			b = s.mPopBack(data2);
			if (!b) return false;
			object data3;
			data3.type = 0;
			if (tmp.data == 2) {
				data3.data = data2.data + data1.data;
			}
			else if (tmp.data == 3) {
				data3.data = data2.data - data1.data;
			}
			else if (tmp.data == 4) {
				data3.data = data2.data * data1.data;
			}
			else {
				data3.data = data2.data / data1.data;
			}
			s.mPushBack(data3);
		}
	}
	object tmp2;
	b = s.mPopBack(tmp);
	if (!b) return false;
	b = s.mPopBack(tmp2);
	if (b) return false;
	res = tmp.data;
	return true;
}

#endif