#include <iostream>
#include <list>
#include <string>

using namespace std;
int n;

int main() {
	list<char> lst;
	// list ���
	string str;
	cin >> str;
	for(int i = 0; i <str.size(); i++)
	lst.push_back(str[i]);
	cin >> n;
	list<char>::iterator it = lst.end();
	while(n--) {
		char ch;
		cin >> ch;

		if (ch == 'L') {
			if (it != lst.begin()) {
				it--;
				// ó���� �ƴ϶�� Ŀ���� ��������
			}
		}
		else if (ch == 'D') {
			if (it != lst.end()) {
				it++;
				// �������� �ƴ϶�� Ŀ���� ����������
			}
		}
		else if (ch == 'B') {
			if (it != lst.begin()) {
				it = lst.erase(--it);
				// Ŀ�� ���� �����
			}
		}
		else if (ch == 'P') {
			char d;
			cin >> d;
			lst.insert(it, d);
			// �߰�
		}
	}

	for (auto i = lst.begin(); i != lst.end(); i++) {
		cout << *i;
	}
}