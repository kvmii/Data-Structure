#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int arr[101][101];
int n, m, k;
int X[] = { 0, 1, 0, -1 };
int Y[] = { 1, 0, -1, 0 };
char turn[101];
queue <pair<int, int>> q;
// ť
vector < pair<int, char>> vec;
// ȸ�� ����� ����

int move(int x, int y) {
	int k = 0;
	int i = 0;
	int count = 0;
	arr[x][y] = 1;
	q.push({ x, y });
	while (1) {
		count++;
		int dx = x + X[k];
		int dy = y + Y[k];
		// ����
		x = dx;
		y = dy;
		if (dx > n || dy > n || dx <= 0 || dy <= 0) break;;
		if (arr[dx][dy] == 1) break;
		// �湮�ߴ� ���̸�
		else if (arr[dx][dy] == 2) {
		}
		else if (arr[dx][dy] == 0) {
			// ���� ���� ���� �� ����
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			arr[a][b] = 0;
			// ��� = 0
		}
		q.push({ dx, dy });
		arr[dx][dy] = 1;
		// �湮 = 1

		if (i < vec.size()) {
			if (vec.at(i).first == count) {
				char ch = vec.at(i).second;
				if (ch == 'L') {
					k--;
					if (k < 0) k += 4;
					// �������� ȸ��
				}
				if (ch == 'D') {
					k++;
					if (k > 3) k -= 4;
					// ���������� ȸ��
				}
				i++;
			}
		}
	}
	return count;
}

int main() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 2;
		// ��� = 2
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a;
		char c;
		cin >> a >> c;
		vec.push_back({ a,c });
	}

	cout << move(1, 1);
	return 0;
}