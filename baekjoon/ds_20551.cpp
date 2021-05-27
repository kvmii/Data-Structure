#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> vec;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	// �̺�Ž���� ����Ͽ��ٰ� �Ȱ��� ���ڵ� ������ lower_bound�� ����
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		int index = lower_bound(vec.begin(), vec.end(), num) - vec.begin();

		if (index != m && vec[index] == num) cout << index << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}