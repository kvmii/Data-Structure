#include <iostream>
#include <stack>

using namespace std;
int n, k;
int result[500001];
stack<pair<int, int>> stk;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		while (!stk.empty()) {
			if (stk.top().first >= k) {
				// �տ� ū ���ڰ� �����ϸ�
				cout << stk.top().second << " ";
				break;
				// �� ������ index����ϰ� break;
			}
			stk.pop();
			// ���ڰ� ������ �ʿ������ ����
			// i���� i+1�� ũ�� i+1�� �ε����� ������ i�� �����ص� �ȴ�
		}
		if (stk.empty()) cout << 0 << " ";
		// ū ���ڰ� �������� ������
		stk.push({ k, i });
		// �Է¹����鼭 ��
	}
	
}