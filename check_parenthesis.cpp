#include "stack.h"
#include <iostream>

static bool check_parenthesis(const char *str) {
	std::cout << "check_parenthesis: " << str << std::endl;
	ArrayStack<char> *stack = new ArrayStack<char>(100);
	for (int i = 0; i < strlen(str); ++i) {
		char checker = 0;
		char c = str[i];
		switch (c) {
		case ')':
			checker = '(';
			break;
		case ']':
			checker = '[';
			break;
		case '}':
			checker = '{';
			break;
		default:
			break;
		}
		if (checker == 0) {
			stack->Push(c);
			std::cout << "push " << c << std::endl;
		} else {
			//碰到右括号，要在栈中查找匹配的左括号
			//如果先碰到其他括号，则返回 false
			//如果栈空，也返回 false
			std::cout << "find " << c << ", check " << checker << std::endl;
			char element;
			bool ret = stack->Pop(&element);
			if (!ret) {
				return false;
			}
			std::cout << "pop " << element << std::endl;
			if (element != checker) {
				std::cerr << "mismatch" << std::endl;
				return false;	
			}
		}
	}
	return stack->IsEmpty() == true;
}


int main() {
	bool ret = false;	
	const char* cases[] = {"{[{}]}", "[{()}([])]", "{[}()", "[({)]"};
	for (int i = 0; i < 4; ++i) {
		ret = check_parenthesis(cases[i]);
		std::cout << "result: " << ret << std::endl;
	}
}
