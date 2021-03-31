#include <iostream>
#include <stack>

using namespace std;

int main() {
	string str;
	stack<char> s;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(') {
			s.push(c);
		}
		else if (c == '*' || c == '/') {
			// * /�� �켱������ �����Ƿ� ���� ó��
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
		else if (c == '+' || c == '-') {
			while (!s.empty() && s.top() != '(') {
				// (�� ������ ������ ��
				cout << s.top();
				s.pop();
			}
			s.push(c);
		}
		else if (c == ')') { 
			// )�� ���ð�� (������ ������ ��
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			cout << c;
		}
	}
	while (!s.empty()) {
		char ch = s.top();
		s.pop();
		cout << ch;
	}

}