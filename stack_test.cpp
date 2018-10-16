#include "stack.h"
#include <iostream>

static void test_linklist_stack() {
	LinkListStack<std::string> *s = new LinkListStack<std::string>();
	std::string tmp;

	std::string val = "hello";
	s->Push(val);
	bool ret = s->Peek(&tmp);
	if (!ret) {
		std::cerr << "peek err" << std::endl;
	} else {
		std::cout << "push ok: " << tmp << std::endl;
	}
	val = "world";	
	s->Push(val);
	ret = s->Peek(&tmp);
	if (!ret) {
		std::cerr << "peek err" << std::endl;
	} else {
		std::cout << "push ok: " << tmp << std::endl;
	}

	ret = s->Pop(&tmp);
	if (ret) {
		std::cout << "pop ok: " << tmp << std::endl;
	} else {
		std::cerr << "Pop err" << std::endl;
	}

	val = "foo";	
	s->Push(val);
	ret = s->Peek(&tmp);
	if (!ret) {
		std::cerr << "peek err" << std::endl;
	} else {
		std::cout << "push ok: " << tmp << std::endl;
	}

	ret = s->Pop(&tmp);
	if (ret) {
		std::cout << "pop ok: " << tmp << std::endl;
	} else {
		std::cerr << "Pop err" << std::endl;
	}

	ret = s->Pop(&tmp);
	if (ret) {
		std::cout << "pop ok: " << tmp << std::endl;
	} else {
		std::cerr << "Pop err" << std::endl;
	}

	ret = s->Pop(&tmp);
	if (ret) {
		std::cout << "pop ok: " << tmp << std::endl;
	} else {
		std::cerr << "Pop err" << std::endl;
	}

	delete s;
	s = NULL;
}


static void test_array_stack() {
	ArrayStack<std::string> *s = new ArrayStack<std::string>(3);
	std::string tmp;

	std::string val = "hello";
	bool ret = s->Push(val);
	if (ret) {
		ret = s->Peek(&tmp);
		if (!ret) {
			std::cerr << "peek err" << std::endl;
		} else {
			std::cout << "push ok: " << tmp << std::endl;
		}
	}
	val = "world";	
	ret = s->Push(val);
	if (ret) {
		ret = s->Peek(&tmp);
		if (!ret) {
			std::cerr << "peek err" << std::endl;
		} else {
			std::cout << "push ok: " << tmp << std::endl;
		}
	}

	ret = s->Pop(&tmp);
	if (ret) {
		std::cout << "pop ok: " << tmp << std::endl;
	} else {
		std::cerr << "Pop err" << std::endl;
	}

	val = "foo";	
	ret = s->Push(val);
	if (ret) {
		ret = s->Peek(&tmp);
		if (!ret) {
			std::cerr << "peek err" << std::endl;
		} else {
			std::cout << "push ok: " << tmp << std::endl;
		}
	}

	ret = s->Pop(&tmp);
	if (ret) {
		std::cout << "pop ok: " << tmp << std::endl;
	} else {
		std::cerr << "Pop err" << std::endl;
	}

	ret = s->Pop(&tmp);
	if (ret) {
		std::cout << "pop ok: " << tmp << std::endl;
	} else {
		std::cerr << "Pop err" << std::endl;
	}

	ret = s->Pop(&tmp);
	if (ret) {
		std::cout << "pop ok: " << tmp << std::endl;
	} else {
		std::cerr << "Pop err" << std::endl;
	}

	delete s;
	s = NULL;
}

int main() {
	test_array_stack();
	test_linklist_stack();
	
	return 0;
}
