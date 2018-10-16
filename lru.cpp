#include <iostream>


struct Node{
	std::string key;
	int value;

	Node *next;
	Node *prev;
};

static const int kMaxCacheNum = 10;
static Node *cache_head = nullptr;
static Node *cache_tail = nullptr;

static int get_node_value(std::string key) {
	std::cout << "get node: " << key << std::endl;
	Node *found = nullptr;
    int count = 0;
	for (Node *n = cache_head; n != nullptr; n = n->next) {
        ++count;
		if (n->key == key) {
			found = n;
			if (found == cache_head) {
				cache_head = found->next;
			}
			if (found == cache_tail) {
				cache_tail = found->prev;
			}
			if (found->prev != nullptr) {
				found->prev->next = found->next;
			}
			if (found->next != nullptr) {
				found->next->prev = found->prev;
			}
			break;
		}
	}
	if (found == nullptr) {
		//缓存中未找到，去其他地方找
		found = new Node;
		found->key = key;
		found->value = 1;

		//最近访问的插入队尾
		found->next = nullptr;
		found->prev = cache_tail;
        if (cache_tail != nullptr) {
			cache_tail->next = found;
		}
		cache_tail = found;
        if (cache_head == nullptr) {
			cache_head = found;
		}

        if (count >= kMaxCacheNum) {
			//缓存满了,  头部删除
			Node *next = cache_head->next;
			delete cache_head;
			cache_head = next;
			if (cache_head != nullptr) {
				cache_head->prev = nullptr;
			}
		} 
	} else {
		//最近访问的插入队尾
    	found->next = nullptr;
		found->prev = cache_tail;
        if (cache_tail != nullptr) {
			cache_tail->next = found;
		}
		cache_tail = found;
	}

	for (Node *n = cache_head; n != nullptr; n = n->next) {
		std::cout << n->key << ":" << n->value << std::endl;
	}

	return found->value;
}

int main() {
	std::string keys[] = {"1", "2", "3", "4", "2", "7", "10", "8", "3", "11", "4", "5", "6", "7", "1", "3", "9", "20"};
	for (int i = 0; i < 18; ++i) {
		std::cout << "==== get_node_value() ====" << std::endl;
		get_node_value(keys[i]);
	}
}
