#include <iostream>

using namespace std;

void change(string word, int& S, int x) {
    int tmp = 1 << x;

    if (word == "add") {
        S = S | tmp;
    }
    else if (word == "remove") {
        S = S & ~tmp;
    }
    else if (word == "check") {
        if (S & tmp) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
    else if (word == "toggle") {
        S = S ^ tmp;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int S = 0;
    while (n--) {
        string s;
        int x;

        cin >> s;

        if (s == "all") {
            S = 2097151; //11111111111111111111
        }
        else if (s == "empty") {
            S = 0;
        }
        else {
            cin >> x;
            change(s, S, x);
        }
    }
    return 0;
}