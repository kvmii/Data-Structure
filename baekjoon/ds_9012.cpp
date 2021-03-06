#include <iostream>
#include <stack>
#include <string>

using namespace std;
int n;
bool check;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		stack<char> stk;
		// ���� �ʱ�ȭ�� ���ؼ� Ʋ�ȴ�
		// ������ ���� ����� �ʰ� ���� ���̽��� �Ѿ�� ���� ��������

		int Left = 0;
		int Right = 0;
		check = false;

		if (str[0] == ')') {
			cout << "NO" << endl;
		}

		else {
			for (int j = 0; j < str.size(); j++) {
				stk.push(str[j]);
			}

			while (!stk.empty()) {
				char c = stk.top();
				stk.pop();
				if (c == ')') {
					Right++;
				}
				if (c == '(') {
					if (Left == Right) {
						cout << "NO" << endl;
						// () ������ �Ȱ����� (�� ���� ���� ��
						check = true;
						break;
					}
					else
					{
						Left++;
					}
				}
			}

			if (check == false) {
				if (Left == Right) {
					// ( )�� ������ ������
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
			}
		}
	}
}
