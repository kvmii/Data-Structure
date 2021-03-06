#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int n, k;
vector<char> vec;
int num = 0;
int result;
bool check = false;

int main() {
	cin >> n;
	stack<int> stk;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (num < k) {
			// ũ�� �ϳ���  �� �ֱ�
			while (num <= k - 1) {
				num++;
				stk.push(num);
				vec.push_back('+');
			}

			// �� ������ num�� pop
			result = stk.top();
			stk.pop();
			vec.push_back('-');
			continue;
		}

		else {
			// ���� ���� �ٷ� pop
			result = stk.top();
			
			if (result == k) {
				// pop�� ���� �Է°��� ������
				stk.pop();
				vec.push_back('-');
			}
			else {
				// �ٸ��� �Ұ���
				check = true;
			}
		}

	}

	if (check == true) {
		cout << "NO";
	}

	else {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << '\n';
		}
	}

}