#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
stack<string> stk;

int main() {
	while (1) {
		getline(cin, str);
		if (str == "������ ����� ��") break;
		else if (str == "����") {
			stk.push(str);
		}
		else if (str == "������") {
			if (stk.empty()) {
				stk.push("����");
				stk.push("����");
			}
			else {
				stk.pop();
			}
		}
	}
	if (stk.empty()) cout << "�������� �����";
	else cout << "����";
}