#include <iostream>
#include <vector>

using namespace std;

int index = 0;

bool findWord(int x, int n, vector<string>& word, string y) {
    index += x;
    index %= n;

    //중복 예외처리 
    for (int i = 0; i < n;i++) {
        if (word[i] == y) {
            if (i == index) continue;
            else return false;
        }
    }
  
    if (word[index].empty() || word[index] == y) {
        word[index] = y;
        return true;
    }

    else {
        return false;
    }
}


int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    //입력
    int n, k;
    cin >> n >> k;

    //연산
    int last_index;

    vector <string> word(n);

    while (k--) {
        int x;
        string y;
        cin >> x >> y;

        if (!findWord(x, n, word, y)) {
            cout << "!";
            exit(0);
        }
        last_index = index;
    }

    //출력
    for (int i = last_index; i >= 0; i--) {
        if (word[i].empty()) {
            cout << "?";
        }
        else {
            cout << word[i];
        }
    }

    for (int i = n - 1; i > last_index; i--) {
        if (word[i].empty()) {
            cout << "?";
        }
        else {
            cout << word[i];
        }
    }
    return 0;
}