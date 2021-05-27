#include <iostream>
#include <stack>

using namespace std;

string str;
stack<char> stk;
int score = 0;

int main() {
	cin >> str;

	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] == '(') {
			// (�� ������ ��
			if (stk.empty()) {
				score++;
				// ������ ����ִٸ� )�� �߰�
			}
			else {
				// )�� �ִٸ� () �� �� ����
				stk.pop();
			}
		}
		else if (str[i] == ')') {
			stk.push(')');
		}
	}

	while (!stk.empty()) {
		// ���� )�� �����ִٸ� (�� �߰�
		stk.pop();
		score++;
	}

	cout << score;
}