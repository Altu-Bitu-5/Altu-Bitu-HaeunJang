#include <iostream>
#include <vector>

using namespace std;

int index = 0;

bool findWord(int x, int n, vector<string>& word, string y) {
    index += x;
    index %= n;

    //�ߺ� ����ó�� 
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
    //����� �ӵ� ���
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    //�Է�
    int n, k;
    cin >> n >> k;

    //����
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

    //���
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