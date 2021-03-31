#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[100000];
int n, m;
int arr[32001];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		arr[b]++;
		// ���๮���� ����
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	// ��ȣ�� ���� ������ ����
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			// ���๮���� ���� ��
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int t = pq.top();
		pq.pop();
		cout << t << " ";
		for (int i = 0; i < vec[t].size(); i++) {
			int cnt = vec[t][i];
			arr[cnt]--;
			// ���๮���� �ϳ� ���������� ���ֱ�
			if (arr[cnt] == 0) pq.push(cnt);
			// ���๮���� �� �ߴٸ�
		}
	}
}