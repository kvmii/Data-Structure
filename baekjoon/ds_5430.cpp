#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;
int n, k;

int main() {
	cin >> n;
	while (n--) {
		string str, input;
		bool check = false;
		cin >> str;
		cin >> k;
		cin >> input;
		deque<int> dq;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] != '[' && input[i] != ']' && input[i] != ',') {
				string temp;
				while (1) {
					temp += input[i];
					// 42�� ��� �ϳ��� ������ 4�� 2�� ��
					// �׷��� ������ ������ ��ȯ
					i++;
					if (input[i] == ']' || input[i] == ',') {
						break;
					}
				}
				dq.push_back(stoi(temp));
				// int�� ��ȯ
			}
		}

		bool reverse = false;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'R') {
				// ������
				if (reverse) reverse = false;
				else reverse = true;
			}
			else if (str[i] == 'D') {
				if (dq.empty()) {
					check = true;
					break;
				}
				else {
					if (reverse == false) dq.pop_front();
					// �ȵ������� �տ��� �����
					else dq.pop_back();
					// �������� �ڿ��� �����
				}
			}
		}

		if (check) cout << "error" << endl;
		else {
			cout << "[";
			if (!dq.empty()) {
				// ��������� [ ]���
				if (reverse == false) {
					// ������ ������ �տ������� ���
					while (1) {
						cout << dq.front();
						dq.pop_front();
						if (!dq.empty()) cout << ",";
						if (dq.empty()) break;
					}
				}
				else {
					// ������ ������ �ڿ������� ���
					while (1) {
						cout << dq.back();
						dq.pop_back();
						if (!dq.empty()) cout << ",";
						if (dq.empty()) break;
					}
				}
			}
			cout << "]" << endl;
		}
	}
}