#include <iostream>

using namespace std;

//최대공약수 찾기 
int getGcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return getGcd(b, a%b);
}

int main() {
	//입력
	int a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;

	//연산
	int gcd = getGcd(max(a2, b2), min(a2, b2));
	int lcm = a2 * b2 / gcd; //통분 (분모 값)
	a1 *= lcm/a2;
	b1 *= lcm/b2;

	int up = a1+b1; //분자 값

	int result = getGcd(max(up, lcm), min(up, lcm)); //약분

	//출력
	cout << up / result << " " << lcm / result;
}