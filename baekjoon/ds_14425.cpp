#include <iostream>
#include <map>

using namespace std;

map<string, int> word;
int m, n, score = 0;

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		word[str]++;
	}

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (word[str] != 0) score++;
	}
	// map���� Ǯ������ ���� Ʈ���̸� ����ϴ� ����
	// Ʈ���̿� ���ؼ� �ѹ� �����غ� �ʿ䰡 �ִ�

	cout << score;
}