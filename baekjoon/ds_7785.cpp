#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;
int n;

int main() {
	cin >> n;
	stack<string> stk;
	map<string, bool> p;
	// map���� Ǯ���µ� Ǯ�� ���� set�� �� ����� �� ����..
	while (n--) {
		string a, b;
		cin >> a >> b;
		if (b == "enter") {
			// ���
			p[a] = true;
		}
		else {
			// ���
			p[a] = false;
		}
	}

	for (auto it = p.begin(); it != p.end(); it++) {
		if (it->second == true)
			// ����� ���¶��
			stk.push(it->first);
		// �������� �����ϱ� ���� stack���
	}

	while (!stk.empty()) {
		cout << stk.top() << '\n';
		stk.pop();
	}
}
