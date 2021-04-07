#include <iostream>
#include <stack>

using namespace std;
int arr[1000001];
int n;
stack<int> stk;
stack<int> result;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = n; i >= 1; i--) {
		// �����ʺ��� ����
		if (stk.empty()) result.push(-1);
		// ū ���� ����ִٸ�
		else {

			while (1) {
				if (arr[i] < stk.top()) {
					// ū���� �ִٸ�
					result.push(stk.top());
					// �����ϱ�
					break;
				}
				else {
					// ũ�� ������ �����ʿ��� �ٸ� ū�� ã��
					stk.pop();
				}
				if (stk.empty()) {
					result.push(-1);
					break;
				}
			}
		}
		stk.push(arr[i]);
		// �־��ֱ�
	}

	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
}