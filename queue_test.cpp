#include "queue.h"
#include <iostream>


int main() {
	ArrayQueue<int> *q = new ArrayQueue<int>(5);
	bool ret = false;
	int value = 0;

	ret = q->EnQueue(1);
	std::cout << "EnQueue 1 result: " << ret << std::endl;
	ret = q->EnQueue(2);
	std::cout << "EnQueue 2 result: " << ret << std::endl;


	ret = q->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	ret = q->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	ret = q->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	ret = q->EnQueue(3);
	std::cout << "EnQueue 3 result: " << ret << std::endl;
	ret = q->EnQueue(4);
	std::cout << "EnQueue 4 result: " << ret << std::endl;
	ret = q->EnQueue(5);
	std::cout << "EnQueue 5 result: " << ret << std::endl;
	ret = q->EnQueue(6);
	std::cout << "EnQueue 6 result: " << ret << std::endl;
	ret = q->EnQueue(7);
	std::cout << "EnQueue 7 result: " << ret << std::endl;
	ret = q->EnQueue(8);
	std::cout << "EnQueue 8 result: " << ret << std::endl;

	delete q;
	q = NULL;

	LinkListQueue<int> *lq = new LinkListQueue<int>();
	std::cout << "====== LinkListQueue ======" << std::endl;

	lq->EnQueue(1);
	std::cout << "EnQueue 1" << std::endl;
	lq->EnQueue(2);
	std::cout << "EnQueue 2" << std::endl;


	ret = lq->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	ret = lq->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	ret = lq->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	lq->EnQueue(3);
	std::cout << "EnQueue 3" << std::endl;
	lq->EnQueue(4);
	std::cout << "EnQueue 4" << std::endl;
	lq->EnQueue(5);
	std::cout << "EnQueue 5" << std::endl;
	lq->EnQueue(6);
	std::cout << "EnQueue 6" << std::endl;
	lq->EnQueue(7);
	std::cout << "EnQueue 7" << std::endl;
	lq->EnQueue(8);
	std::cout << "EnQueue 8" << std::endl;

	delete lq;
	lq = NULL;

	std::cout << "====== CircularQueue ======" << std::endl;
	CircularQueue<int> *cq = new CircularQueue<int>(5);

	ret = cq->EnQueue(1);
	std::cout << "EnQueue 1 result: " << ret << std::endl;
	ret = cq->EnQueue(2);
	std::cout << "EnQueue 2 result: " << ret << std::endl;


	ret = cq->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	ret = cq->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	ret = cq->DeQueue(&value);
	std::cout << "DeQueue result: " << ret << ", value: " << value << std::endl;

	ret = cq->EnQueue(3);
	std::cout << "EnQueue 3 result: " << ret << std::endl;
	ret = cq->EnQueue(4);
	std::cout << "EnQueue 4 result: " << ret << std::endl;
	ret = cq->EnQueue(5);
	std::cout << "EnQueue 5 result: " << ret << std::endl;
	ret = cq->EnQueue(6);
	std::cout << "EnQueue 6 result: " << ret << std::endl;
	ret = cq->EnQueue(7);
	std::cout << "EnQueue 7 result: " << ret << std::endl;
	ret = cq->EnQueue(8);
	std::cout << "EnQueue 8 result: " << ret << std::endl;

	delete cq;
	cq = NULL;

	return 0;
}

