#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct node {
	string position;
	node* first;
	node* second;
};

struct org_tree {
	node* root;

	static org_tree create_org_structure(const string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	static node* find(node* root, const string& value) {
		if (root == NULL)
			return NULL;
		if (root->position == value)
			return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		return org_tree::find(root->second, value);
	}

	bool addSubordinate(const string& manager, const string& subordinate) {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			cout << manager << "��(��) ã�� �� �����ϴ�: " << endl;
			return false;
		}

		if (managerNode->first && managerNode->second) {
			cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��� �� �����ϴ�." << endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		cout << manager << " �Ʒ��� " << subordinate << "��(��) �߰��߽��ϴ�." << endl;

		return true;
	}
};

int main() {
	auto tree = org_tree::create_org_structure("CEO");

	tree.addSubordinate("CEO", "�λ���");
	tree.addSubordinate("�λ���", "IT����");
	tree.addSubordinate("�λ���", "�����ú���");
	tree.addSubordinate("IT����", "��������");
	tree.addSubordinate("IT����", "�۰�������");
	tree.addSubordinate("�����ú���", "��������");
	tree.addSubordinate("�����ú���", "ȫ������");
	tree.addSubordinate("�λ���", "�繫����");
	system("PAUSE");
}