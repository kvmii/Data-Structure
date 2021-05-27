#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
priority_queue<float, vector<float>, less<float>> pq;
vector<float>vec[101];

int n, m, k;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			float b;
			cin >> a >> b;
			vec[a].push_back(b);
			// �����ں��� �з�
		}
	}

	for (int i = 1; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end(), greater<float>());
		// �����ڰ� �ڽ��ִ� ����
		pq.push(vec[i].front());
	}

	float score = 0;
	while (k--) {
		// ���� ���� ���� k�� �̱�
		score += pq.top();
		pq.pop();
	}

	score = abs(score);
	printf("%.1f", score);
}