#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	queue<int> q;

	cin >> n >> k;
	for (int i = 1; i < n + 1;i++) {
		q.push(i);
	}
	cout << "<";
	while (true) {
		if(!q.empty()) {
			for (int i = 1; i < k;i++) {
				int x = q.front();
				q.pop();
				q.push(x);
			}
			cout << q.front();
			q.pop();
			if (q.empty()) {
				break;
			}
		}
		cout << ", ";
	}
	cout << ">";
}
