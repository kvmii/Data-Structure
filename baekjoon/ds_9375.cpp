#include <iostream>
#include <string>
#include <map>

using namespace std;
int T, n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		int result = 1;
		map<string, int> clothes;
		// map Ȱ��
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			clothes[b]++;
			// ���� ���� �ľ��ϱ�
		}

		map<string, int>::iterator it;
		for (auto it = clothes.begin(); it != clothes.end(); it++) {
			result *= it->second + 1;
			// �ϳ��� �����ֱ�
		}
		cout << result - 1 << endl;
		clothes.clear();
	}
}