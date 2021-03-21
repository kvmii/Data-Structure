#include <iostream>
#include <string>
#include <stack>

using namespace std;
int n;
bool check;

int main() {
	while(1) {
		string str;
		getline(cin, str);

		if (str == ".") break;
		// .�� ������ ����

		stack<char> stk;

		int Left = 0;
		int Right = 0;
		int left = 0;
		int right = 0;
		check = false;


			for (int j = 0; j < str.size(); j++) {
				if(str[j] == '[' || str[j] == '(')
					stk.push(str[j]);
				// [, (�� ������ ���ÿ� �ֱ�

				if (str[j] == ')') {
					// )�� ������ �� �տ� (�� �־�� ��
					if (stk.empty()) {
						check = true;
						break;
					}
					else if (stk.top() != '(') {
						check = true;
						break;
					}
					else stk.pop();
				}
				else if (str[j] == ']') {
					// ]�� ������ �� �տ� [�� �־�� ��
					if (stk.empty()) {
						check = true;
						break;
					}
					else if (stk.top() != '[') {
						check = true;
						break;
					}
					else stk.pop();
				}
			}

			if (check == false && stk.empty()) {
				// ������ ������� ������ ��ĪX
				cout << "yes" << endl;
			}
			else cout << "no" << endl;
	}
}