#include <iostream>
#include <deque>

using namespace std;
int n, k;
int result = 0;

int main() {
	deque<int> deq;
	// ����� ���� = dequeȰ��
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		deq.push_back(i);
	}

	int score = 0;
	while (k--) {
		int a, index;
		cin >> a;
		while (1) {
			if (deq.front() == a) {
				// �� ���� �´ٸ� pop
				deq.pop_front();
				break;
			}
			for (int i = 0; i < deq.size(); i++) {
				if (deq[i] == a) {
					index = i;
					// ������ ��ġ ã��
				}
			}
			if (index <= deq.size() / 2) {
				// ��ġ�� �����̶��
				// �տ��� �ڷ� �ű��
				int num = deq.front();
				deq.push_back(num);
				deq.pop_front();
				result++;
			}
			else {
				// ��ġ�� �����̶��
				// �ڿ��� ������ �ű��
				int num = deq.back();
				deq.push_front(num);
				deq.pop_back();
				result++;
			}
		}
	}

	cout << result;
}