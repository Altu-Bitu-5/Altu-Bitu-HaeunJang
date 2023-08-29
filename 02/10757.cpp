#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack <int> aStack;
	stack <int> bStack;
	stack <int> s;
	string a, b;

	cin >> a >> b;
	for (int i = 0; i < a.length();i++) {
		aStack.push(a[i] - '0');
	}
	for (int i = 0; i < b.length();i++) {
		bStack.push(b[i] - '0');
	}

	int sum = 0, y = 0;
	while (!aStack.empty() || !bStack.empty() || y != 0) {
		int x = sum;
		if (!aStack.empty()) {
			x += aStack.top();
			aStack.pop();
		}
		if (!bStack.empty()) {
			x += bStack.top();
			bStack.pop();
		}
		x += y;
		y = x / 10;
		x %= 10;
		s.push(x);

	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}
