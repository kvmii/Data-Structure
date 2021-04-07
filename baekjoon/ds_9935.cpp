#include <iostream>
#include <stack>

using namespace std;
string str1, str2;
bool check = false;

int main() {
	stack<char> stk;
	// list��ٰ� �ð��ʰ��� �������� ����
	cin >> str1;
	cin >> str2;
	int index = str2.size() - 1;
	for (int i = 0; i < str1.size(); i++) {
		stk.push(str1[i]);
		// �ϴ� �־��ְ�

		if (stk.top() == str2[index] && i >= index) {
			// ���� �� ���ڸ� ã���� ��, ���̰� �����Ҷ�
			stack<char> save;
			for (int i = index; i >= 0; i--) {
				if (stk.top() == str2[i]) {
					// �ڿ������� �ϳ��� ��
					save.push(stk.top());
					// ����� ���ÿ� ����
					stk.pop();
				}
				else {
					// ���ϴٰ� Ʋ�ȴٸ�
					while (!save.empty()) {
						stk.push(save.top());
						save.pop();
						// �ٽ� �������ֱ�
					}
					break;
				}
			}
		}
	}

	if (stk.empty()) cout << "FRULA";
	// ������ ����ִٸ�
	else {
		stack<char> c;
		while (!stk.empty()) {
			c.push(stk.top());
			stk.pop();
		}
		while (!c.empty()) {
			cout << c.top();
			c.pop();
		}
	}
}