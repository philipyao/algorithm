#include <iostream>

struct Node { 
	char value;
    Node *next;
};

static int is_palindrome(Node *list) {
	//思路：先根据快慢指针找到中点，快指针到头时，慢指针正好指向中点
	//在找到中点前，将前半部分链表反转
	//找到中点后，分别两个指针指向中点和之前的慢指针位置，由于反转后中点两侧方向正好相反，因此可以依次遍历比较内容是否相同，如果是则是回文数
	//这里修改了原单链表，所以空间复杂度是 O(1), 时间复杂度是 O(n)
	//如果要求不修改原链表，可以再新建一个链表来方式需要反转的链表，则时间复杂度和空间复杂度都是 O(n)

    Node *slow, *fast;
    Node *middle = nullptr;
    Node *prev = nullptr;
    Node *next = nullptr;
    for (slow = list, fast = list; slow != nullptr;) {
        next = slow->next;
        std::cout << "node: " << slow->value << std::endl;
        if (middle == nullptr) {
        	fast = fast->next;

            //没到中点前，反转链表
            slow->next = prev;
            prev = slow;

        	if (fast == nullptr) {
            	middle = slow->next; //往回退一位
            	std::cout << "odd middle: " << middle->value << std::endl;
        	} else {
				fast = fast->next;
    	    	if (fast == nullptr) {
       		     	middle = slow;
            		std::cout << "even middle: " << middle->value << std::endl;
        		}
			}
            slow = next;
        } else {
			break;
		}
    }
	std::cout << "breaked" << std::endl;
	Node *n1, *n2;
	for (n1 = middle, n2 = slow; n1 != nullptr && n2 != nullptr; n1 = n1->next, n2 = n2->next) {
        std::cout << "n1: " << n1->value << ", n2: " << n2->value << std::endl;

		if (n1->value != n2->value) {
			std::cout << "result: non-palindrome" << std::endl;
			return 0;
		}
	}
	std::cout << "result: palindrome" << std::endl;

	return 0;
}

static Node* reverse(Node *list) {
	Node *next = nullptr;
    Node *prev = nullptr;
    for (Node *node = list->next; node != nullptr;) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
	return prev;
}

static Node *build_list(const char *str) {
    Node *list = nullptr;
    Node *curr = nullptr;
    for (int i = 0; i < strlen(str); i++) {
        Node *node = new Node;
        node->value = str[i];
		if (list == nullptr) {
			list = node;
			curr = list;
		}
        curr->next = node; 
		curr = node;
    }
	if (curr != nullptr) {
    	curr->next = nullptr;
	}
	std::cout << "build list: " << std::endl;
	for (Node *nd = list; nd != nullptr; nd = nd->next) {
        std::cout << nd->value << std::endl;
    }
	return list;
}

int main() {
    const char* str_arr[] = {"hello", "level", "abcddcba"};
    for (int i = 0; i < 3; i++) {
		Node *list = build_list(str_arr[i]);
    	is_palindrome(list);
	}

	/*
    Node *reversed = reverse(list);
    std::cout << "after reversed:" << std::endl;
	for (Node *nd = reversed; nd != nullptr; nd = nd->next) {
        std::cout << nd->value << std::endl;
    }
	*/
    
	return 0;
}

