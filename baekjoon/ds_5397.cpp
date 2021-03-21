#include <iostream>
#include <string>
#include <list>

using namespace std;
int n;
char c;

int main() {
	cin >> n;
	while (n--) {
		list<char> vec;
		string str;
		cin >> str;
		list<char>::iterator it = vec.begin();
		// ó������ ����

		for (int i = 0; i < str.size(); i++) {
			char c = str[i];
			if (c == '<' && it != vec.begin()) {
				// < ���ý� �� ĭ ������
				it--;
			}
			else if (c == '>' && it != vec.end()) {
				// > ���ý� �� ĭ �ڷ�
				it++;
			}
			else if (c == '-' && it != vec.begin()) {
				it = vec.erase(--it);
				// - ������ �տ� �ִ°� �����
			}
			else {
				if (c == '<' || c == '>' || c == '-') continue; 
				// �� �� ���ڸ� �ֱ�
				it = vec.insert(it, c);
				it++;
			}
		}
		for (auto i = vec.begin(); i != vec.end(); i++) {
			cout << *i;
		}
		cout << '\n';
	}
}