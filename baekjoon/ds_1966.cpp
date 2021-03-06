#include <iostream>
#include <queue>

using namespace std;
int n, m, cnt;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		// �߿䵵�� ���� ��
		cin >> m >> cnt;
		int result = 0;

		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			pq.push(a);
			q.push({ a, i });
		}

		while (1) {
			int num = q.front().first;
			int index = q.front().second;
			if (num == pq.top()) {
				// �߿䵵�� �� ������ ���
				result++;
				// result��° ���
				if (index == cnt) {
					// �츮�� ã�� ���� ����ϸ�
					cout << result << endl;
					break;
				}
				q.pop();
				pq.pop();
			}

			else {
				// �߿䵵�� �� �����ź��� ������
				// �ڷ� �ѱ��
				q.push({ num, index });
				q.pop();
			}
		}
	}
}