#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, less<int>> maxpq; //�ִ� ��
	priority_queue<int, vector<int>, greater<int>> minpq; //�ּ� ��
	int mid;
	int n;
	cin >> n;
	int i = 0;

	while (n--) {
		int k;
		cin >> k;

		if (i == 0) {
			// ������� ���
			mid = k;
			i++;
		}
		else {
			if (k >= mid) minpq.push(k);
			// �߰������� ũ��
			else if (k < mid) maxpq.push(k);
			// �߰������� ������

			int minsize = minpq.size();
			int maxsize = maxpq.size();

			if ((minsize + maxsize + 1) % 2 == 0) {
				//��ü ¦�������
				if (minsize <= maxsize) {
					int tmp = mid;
					mid = maxpq.top();
					maxpq.pop();
					minpq.push(tmp);
				}
			}
			else {
				//��ü Ȧ������� 
				if (minsize < maxsize) {
					// max�� �� ������ max���� �� ū�� �߰���
					minpq.push(mid);
					mid = maxpq.top();
					maxpq.pop();
				}
				else if (minsize > maxsize) {
					// min�� �� ������ min���� �� ������ �߰���
					maxpq.push(mid);
					mid = minpq.top();
					minpq.pop();
				}
			}
		}
		cout << mid << '\n';
	}
	return 0;
}