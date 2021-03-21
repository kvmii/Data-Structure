#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int n, k;
priority_queue<int, vector<int>, greater<int>> mq;
priority_queue<int, vector<int>, less<int>> pq;
// ��������, ��������

int main() {
	cin >> n;
	while (n--) {
		cin >> k;
		if (k == 0) {
			if (pq.empty() && mq.empty()) cout << 0 << endl;
			else if (pq.empty()) {
				cout << mq.top() << endl;
				mq.pop();
			}
			else if (mq.empty()) {
				cout << pq.top() << endl;
				pq.pop();
			}
			else {
				if (abs(pq.top()) > abs(mq.top())) {
					//������� �� �����Ͱ� �������� �� ū�� ��(����)
					cout << mq.top() << endl;
					mq.pop();
				}
				else {
					cout << pq.top() << endl;
					pq.pop();
				}
			}
		}
		else {
			if (k > 0) {
				// ����϶�
				mq.push(k);
			}
			else {
				// �����϶�
				pq.push(k);
			}
		}
	}
}
