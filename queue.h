#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>

//普通数组队列，指针持续向右移动，到到达数组尾部时，进行数据迁移， 依次移动到数组头部
template <typename T>
class ArrayQueue
{
public:
	ArrayQueue() = delete;
	ArrayQueue(const ArrayQueue& other) = delete;
	ArrayQueue(int cap) {
		arr = new T[cap];
		capacity = cap;
		head = tail = 0;
	}
	~ArrayQueue() {
		delete[] arr;
		arr = nullptr;
	}

	bool EnQueue(const T& val) {
		if (tail == capacity) {
			//需要进行数据迁移, 且有迁移空间
			if (head > 0) {
				for (int i = head; i < tail; ++i) {
					arr[i-head] = arr[i];
				}
				tail -= head;
				head = 0;
				std::cout << "move when full: head " << head << ", tail " << tail << std::endl;
			} else {
				return false;
			}
		}

		//入队
		arr[tail++] = val;
		std::cout << "enqueue: tail " << tail << std::endl;
		return true;
	}

	bool DeQueue(T *pVal) {
		//empty queue
		if (head == tail) { return false; }

		//出队
		*pVal = arr[head];
		++head;
		std::cout << "dequeue: head " << head << std::endl;
		return true;
	}

private:
	T *arr;
	int capacity;
	int head;
	int tail;
};


template <typename T>
class LinkListQueue
{
public:
	struct ListNode {
		T data;
		ListNode *next;
		ListNode(const T& t) : data(t), next(nullptr) {}
	};

	LinkListQueue() {
		T tmp;
		dummy = new ListNode(tmp);
		tail  = dummy;
	}
	~LinkListQueue() {
		delete dummy;
		dummy = nullptr;
	}

	void EnQueue(const T& val) {
		tail->next = new ListNode(val);
		tail = tail->next;
	}

	bool DeQueue(T *pVal) {
		if (dummy->next == nullptr) { return false; }
		
		ListNode *head = dummy->next;
		*pVal = head->data;
		dummy->next = head->next;
		delete head;
		head = nullptr;
		if (dummy->next == nullptr) {
			tail = dummy;	
		}
		return true;
	}

private:
	ListNode *dummy;
	ListNode *tail;
};


//环形队列
template <typename T>
class CircularQueue
{
public:
	
	CircularQueue() = delete;
	CircularQueue(const CircularQueue& other) = delete;
	CircularQueue(int capacity) : _capacity(capacity), _head(0), _tail(0) {
		_arr = new T[capacity];
	}
	~CircularQueue() {
		delete[] _arr;
		_arr = nullptr;
	}

	bool EnQueue(const T& val) {
		// 满了，留一个元素用来区分满和空
		if ((_tail + 1) % _capacity == _head) { return false; }

		//入队
		_arr[_tail] = val;
		_tail = (_tail + 1) % _capacity;
		std::cout << "enqueue: tail " << _tail << std::endl;
		return true;
	}

	bool DeQueue(T *pVal) {
		//empty queue
		if (_head == _tail) { return false; }

		//出队
		*pVal = _arr[_head];
		_head = (_head + 1) % _capacity;
		std::cout << "dequeue: head " << _head << std::endl;
		return true;
	}

private:
	T *_arr;
	int _capacity;
	int _head;
	int _tail;
};


#endif //__QUEUE_H__
