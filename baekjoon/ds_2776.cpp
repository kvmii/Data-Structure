#include <iostream>
#include <algorithm>

using namespace std;

int T, m, n;
int arr[1000005];

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> arr[i];
		}
		
		sort(arr + 1, arr + 1 + m);
		// ����������� �з�

		cin >> n;
		for (int i = 1; i <= n; i++) {
			int start = 1;
			// ���۹�ȣ
			int end = m;
			// ����ȣ
			int mid = (start + end) / 2;
			// �߰���ȣ
			int num, result = 0;
			cin >> num;
			while (start <= end) {
				mid = (start + end) / 2;
				// �߰���ȣ ����
				if (arr[mid] < num) {
					//�Է°��� �߰��� �ִ� ������ Ŭ���
					// mid + 1 ~ end
					start = mid + 1;
				}
				else if (arr[mid] > num) {
					// �Է°��� �߰��� �ִ� ������ �������
					// start ~ mid - 1
					end = mid - 1;
				}
				else {
					result = 1;
					break;
				}
			}

			cout << result << '\n';
		}
	}
}