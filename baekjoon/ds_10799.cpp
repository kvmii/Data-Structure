#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	stack<int> stk;
	int result = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			// (�� ������ �踷����� ����++
			stk.push(i);
		}
		else {
			// )�� ������ --
			if (stk.top() + 1 == i) {
				// �������� ���
				stk.pop();
				result += stk.size();
				// ������� ������ŭ �߰�
			}
			else {
				// �������� �ƴҰ��
				// ����� �ϳ��� �����Ƿ� + 1
				stk.pop();
				result += 1;
			}
		}
	}

	cout << result;
}