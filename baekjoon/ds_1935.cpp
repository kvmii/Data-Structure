#include <iostream>
#include <stack>
#include <string>
using namespace std;

double arr[26];
string str;

int main() {
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    int num;
    cin >> num;
    cin >> str;
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
        // ���� �Է¹ޱ�
    }
    stack<double> stk;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-') {
            // �����ȣ�� ������ ���� �ֱ� �ΰ� ���� ����
            double a = stk.top();
            stk.pop();
            double b = stk.top();
            stk.pop();
            if (str[i] == '*') stk.push(a * b);
            else if (str[i] == '/') stk.push(b / a);
            else if (str[i] == '+') stk.push(b + a);
            else if (str[i] == '-') stk.push(b - a);
        }
        else stk.push(arr[str[i] - 'A']);
        // �ش��ϴ� ���� push
    }

    cout << fixed;
    cout.precision(2); //�Ҽ��� ��°�ڸ����� ���
    cout << stk.top();
    return 0;
}