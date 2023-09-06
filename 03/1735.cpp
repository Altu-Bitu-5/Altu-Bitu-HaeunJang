#include <iostream>

using namespace std;

//�ִ����� ã�� 
int getGcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return getGcd(b, a%b);
}

int main() {
	//�Է�
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;

	//����
	int gcd = getGcd(max(a2, b2), min(a2, b2));
	int lcm = a2 * b2 / gcd; //��� (�и� ��)
	a1 *= lcm/a2;
	b1 *= lcm/b2;

	int up = a1+b1; //���� ��

	int result = getGcd(max(up, lcm), min(up, lcm)); //���

	//���
	cout << up / result << " " << lcm / result;
}