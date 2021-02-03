#include <iostream>
#include <algorithm>

using namespace std;

struct singly_11_node {
	int data;
	singly_11_node* next;
};

class singly_11 {
public:
	using node = singly_11_node;
	using node_ptr = node*;

private:
	node_ptr head;

public:
	void push_front(int val) {
		auto new_node = new node{ val, NULL };
		if (head != NULL)
			new_node->next = head;
		head = new_node;
	}

	void pop_front() {
		auto first = head;
		if (head) {
			head = head->next;
			delete first;
		}
	}

	struct singly_11_iterator {
	private:
		node_ptr ptr;

	public:
		singly_11_iterator(node_ptr p) : ptr(p) {}
		int& operator*() { return ptr->data; }
		node_ptr get() { return ptr; }
		
		singly_11_iterator& operator++() {
			ptr = ptr->next;
			return *this;
		}

		singly_11_iterator operator++(int) {
			singly_11_iterator result = *this;
			++(*this);
			return result;
		}

		friend bool operator==(const singly_11_iterator& left, const singly_11_iterator& right) {
			return left.ptr == right.ptr;
		}

		friend bool operator != (const singly_11_iterator& left, const singly_11_iterator& right) {
			return left.ptr != right.ptr;
		}
	};

	singly_11_iterator begin() { return singly_11_iterator(head); }
	singly_11_iterator end() { return singly_11_iterator(NULL); }
	singly_11_iterator begin() const { return singly_11_iterator(head); }
	singly_11_iterator end() const { return singly_11_iterator(NULL); }

	singly_11() = default;

	singly_11(const singly_11& other) : head(NULL) {
		if (other.head) {
			head = new node{ 0, NULL };
			auto cur = head;
			auto it = other.begin();
			while (true) {
				cur->data = *it;

				auto tmp = it;
				++tmp;
				if (tmp == other.end())
					break;

				cur->next = new node{ 0, NULL };
				cur = cur->next;
				it = tmp;
			}
		}
	}

	singly_11(const std::initializer_list<int>& ilist) : head(NULL) {
		for (auto it = std::rbegin(ilist); it != std::rend(ilist); it++)
		{
			push_front(*it);
		}
	}

};

int main() {
	singly_11 sll = { 1, 2, 3 };
	sll.push_front(0);

	cout << "ù ��° ����Ʈ: ";
	for (auto i : sll)
		cout << i << " ";
	cout << endl;

	auto sll2 = sll;
	sll2.push_front(-1);
	cout << "ù ��° ����Ʈ�� ������ ��, �� �տ� -1�� �߰�: ";
	for (auto i : sll2)
		cout << i << " ";
	cout << endl;

	cout << "���� ���� �� ù ��° ����Ʈ: ";

	for (auto i : sll)
		cout << i << " ";
	cout << endl;
}