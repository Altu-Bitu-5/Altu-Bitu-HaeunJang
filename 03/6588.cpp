#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//�Է��� ���� �ִ񰪺��� ���� ��� �Ҽ� ã�� (�����佺�׳׽��� ü)
vector<int> getPrime(int max) {
	vector<int> prime(max + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(max + 1); i++) {
		if (!prime[i]) {
			continue;
		}
		for (int j = i * i;j <= max + 1;j += i) {
			if (!prime[j]) {
				continue;
			}
			prime[j] = false;
		}
	}
	return prime;
}

//�Ҽ��� �� ã��
vector<int> find(int n, vector<int>& prime) {
	vector<int> find;
	for (int i = 2; i <= n;i++) {
		if (!prime[i]) {
			continue;
		}
		int temp = n - i;
		if (!prime[temp]) {
			continue;
		}
		else {
			find.push_back(i);
			find.push_back(temp);
			break;
		}
	}
	return find;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�Է�
	int max = 0;
	vector <int> num;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		else if (n > max) max = n;
		num.push_back(n);
	}

	//����
	vector <int> prime = getPrime(max);
	vector<int> result;
	for (int i = 0; i < num.size();i++) {
		result = find(num[i], prime);
		//���
		if (result.empty()) {
			cout << "Goldbach's conjecture is wrong.";
		}
		cout << num[i] << " = " << result[0] << " + " << result[1] << "\n";
	}
}