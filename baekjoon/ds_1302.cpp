#include <iostream>
#include <map>

using namespace std;
int n;
map<string, int> book;
int score = 0;
string result;

int main() {
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		// �ȸ� ����
		book[str]++;
	}

	for (auto it = book.begin(); it != book.end(); it++) {
		if (score < it->second) {
			// ���� ���� �ȷȴٸ�
			score = it->second;
			result = it->first;
		}
	}

	cout << result;
}