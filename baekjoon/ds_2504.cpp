#include <iostream>
#include <string>
#include <stack>

using namespace std;
int n;
bool check;

int main() {
		string str;
		cin >> str;

		stack<char> stk;

		int temp = 1;
		int result = 0;
		check = false;


		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				// (������ 2 ���ϱ�
				temp *= 2;
				stk.push(str[j]);
			}
			else if (str[j] == '[') {
				// [������ 3 ���ϱ�
				temp *= 3;
				stk.push(str[j]);
			}

			else if (str[j] == ')') {
				if (stk.empty() || stk.top() != '(') {
					check = true;
				}
				else {
					if (str[j - 1] == '(') {
						// ()���ð�� �����ֱ�
						result += temp;
					}
					// ������������ �ٽ� 2�� �����ֱ�
					stk.pop();
					temp /= 2;
				}
			}
			else if (str[j] == ']') {
				if (stk.empty() || stk.top() != '[') {
					check = true;
				}
				else {
					if (str[j - 1] == '[') {
						// [] ���ð�� �����ֱ�
						result += temp;
					}
					// ������������ �ٽ� 3���� ������
					stk.pop();
					temp /= 3;
				}
			}
			
		}

		if (check == false && stk.empty()) {
			// ������ ������� ������ ��ĪX
			cout << result << endl;
		}
		else cout << 0 << endl;
}