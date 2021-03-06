#include <iostream>
#include <stack>

using namespace std;
int n, k;
int result = 0;

int main() {
	stack<int> stk;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 0) stk.pop();
		// 0�̸� �ֱٿ� �� �� �����
		else stk.push(k);
		// �ƴϸ� ����
	}

	while (!stk.empty()) {
		int num = stk.top();
		stk.pop();
		result += num;
	}

	cout << result;
}