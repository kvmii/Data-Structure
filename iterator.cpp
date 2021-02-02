#include <iostream>
#include <forward_list>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> vec = { "Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
		"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
	"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso" };

	auto it = vec.begin(); // ��� �ð�
	cout << "���� �ֱ� �����: " << *it << endl;
	
	it += 8;
	cout << "8�� �� �����: " << *it << endl;

	advance(it, -3);
	cout << "�� �� 3�� �� �����: " << *it << endl;

	forward_list<string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	cout << "���� �ֱ� �����: " << *it1 << endl;

	advance(it1, 5);
	cout << "5�� �� �����: " << *it1 << endl;
	// forward_list�� ���������θ� �̵��� �� �����Ƿ�
	// �Ʒ� �ڵ�� ������ �߻��մϴ�
	// advance(it1, -2);
	system("PAUSE");
}