#include <iostream>
#include <queue>

using namespace std;
int n, k;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> k;
		if(k == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				// endl ���� \n �������
				// �ð��ʰ�
				pq.pop();
			}
		}
		else {
			pq.push(k);
		}
	}
}