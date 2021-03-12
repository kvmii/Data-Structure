#include <iostream>
#define MAX 1000000
using namespace std;

int n, m, parent[MAX + 1];

int find(int n) {
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	return find(parent[n]);
	// root ��带 ã�� �Լ�
}

void uni(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	// root�� ���ٸ�
	parent[b] = a;
	// �ٸ��� ���� ����
	// �������ִ� �Լ�
}

int main() {
	// ���Ͽ� �Ŀ�� ����
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cout.tie(NULL);

	fill(parent, parent + MAX + 2, -1);

	int a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 0) uni(b, c);
		else {
			if (find(b) == find(c)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}