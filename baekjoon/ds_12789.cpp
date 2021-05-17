#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n;
int num = 1;
stack<int> stk;
queue<int> q;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		q.push(m);
	}

	while (1) {
		if (num == n + 1) {
			// ��ΰ� ������ ������
			cout << "Nice";
			break;
		}
		if (!q.empty() && q.front() == num) {
			// ������ ������ �׳� ������ ������ ����
			num++;
			q.pop();
		}
		else if (!stk.empty() && stk.top() == num) {
			stk.pop();
			num++;
		}
		else {
			if (q.empty()) {
				// ��� ������ ��������
				cout << "Sad";
				break;
			}
			// �Ѹ� ���� �������� �̵�
			stk.push(q.front());
			q.pop();
		}
	}

}