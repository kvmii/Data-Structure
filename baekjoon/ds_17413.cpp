#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	stack<char> stk;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			// <�� ������ ���
			if (!stk.empty()) {
				while (!stk.empty()) {
					cout << stk.top();
					stk.pop();
					// �̹� �� �ܾ�� �������ֱ�
				}
			}
			while (1) {
				cout << str[i];
				if (str[i] == '>') break;
				// >������ ������ �״�� ���
				i++;
			}
		}

		else if (str[i] == ' ') {
			// ���� ������ ���
			while (!stk.empty()) {
				cout << stk.top();
				stk.pop();
				// �� �ܾ�� ������
			}
			cout << ' ';
			// ���� ���
		}

		else if (i == str.size() - 1) {
			// ���� ������ ���
			stk.push(str[i]);
			// ������ ���� �����ֱ�
			while (!stk.empty()) {
				cout << stk.top();
				stk.pop();
				// �Ųٷ� ���
			}
		}

		else {
			// ������ ���ڵ� ����
			stk.push(str[i]);
		}
	}
}