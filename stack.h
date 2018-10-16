#ifndef __STACK_H__
#define __STACK_H__

//for NULL
#include <stddef.h>

template <typename T>
class ArrayStack {
public:
	ArrayStack(int cap) : capacity(cap), count(0) {
		arr = new T[cap];
	}
	~ArrayStack() {
		delete[] arr;
		arr = NULL;
	}

	bool Push(const T& val) {
		if (arr == NULL) { return false; }
		if (count >= capacity) {
			return false;
		}
		arr[count++] = val;
		return true;
	}

	bool Pop(T *pVal) {
		if (arr == NULL) { return false; }
		if (count <= 0) {
			return false;
		}
		*pVal = arr[--count];	
		return true;
	}

	bool IsEmpty() const {
		return count == 0;
	}

	bool IsFull() const {
		return count == capacity;
	}

	bool Peek(T *pVal) const {
		if (arr == NULL) { return false; }
		if (count <= 0) {
			return false;
		}
		*pVal = arr[count-1];	
		return true;
	}

private:
    T *arr;
    int capacity;
    int count;
};


template <typename T>
class LinkListStack {
public:

	struct ListNode {
		T data;
		ListNode *next;
		ListNode(const T& t) : data(t), next(NULL) {}
	};

	LinkListStack() { 
		T tmp;
		top = new ListNode(tmp);
	}
	~LinkListStack() {
		delete top;
		top = NULL;
	}

	void Push(const T& val) {
		ListNode *newNode = new ListNode(val);
		newNode->next = top->next;
		top->next = newNode;
	}

	bool Pop(T *pVal) {
		ListNode *node = top->next;
		if (node == NULL) { return false; }

		*pVal = node->data;	
		top->next = node->next;
		delete node;
		node = NULL;
		return true;
	}

	bool IsEmpty() const {
		return top->next == NULL;
	}

	bool Peek(T *pVal) const {
		ListNode *node = top->next;
		if (node == NULL) { return false; }

		*pVal = node->data;	
		return true;
	}

private:
    ListNode *top;
};


#endif //__STACK_H__
