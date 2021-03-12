#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> card;
vector<int> vec;
int n, m;

int main() {
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		card.push_back(a);
	}
	cin >> m;
	while (m--) {
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(card.begin(), card.end());
	// ���� ���ں��� ����

	for (auto x : vec) {
		auto upper = upper_bound(card.begin(), card.end(), x);
		auto lower = lower_bound(card.begin(), card.end(), x);

		// x���� ū ���� �ε��� - ���� ���� �ε��� = ����
		cout << upper - lower << " ";
	}
}