#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (int j = 0; j < m; j++) {
		int num;
		cin >> num;
		auto it = s.find(num);
		if (it != s.end()) {
			// ã���� ��� ���ֱ�
			s.erase(it);
		}
	}

	cout << s.size() << endl;
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
}