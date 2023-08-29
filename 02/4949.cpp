#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> input;
	string in;

	while (true) {
		getline(cin, in);
		if (in == ".") {
			break;
		}
		input.push_back(in);
	}

	for(const string &str : input){
		bool balanced = true;
		stack<char> s;
		for (int i = 0;i < str.size();i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (s.empty() || s.top() != '(') {
					balanced = false;
					break;
				}
				s.pop();
			}
			else if (str[i] == ']') {
				if (s.empty() || s.top() != '[') {
					balanced = false;
					break;
				}
				s.pop();
			}
			else if (str[i] == '.') {
				if (!s.empty()) {
					balanced = false;
				}
				while (!s.empty()) {
					s.pop();
				}
			}
		}
		if (balanced) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}