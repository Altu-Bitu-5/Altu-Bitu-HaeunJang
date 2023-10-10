#include <iostream>

using namespace std;


bool three(int i) {
    bool tmp;
    int n = 2;
    while (n--) {
        i /= 10;
        if (i % 10 == 6) {
            tmp = true;
        }
        else {
            tmp = false;
            break;
        }
    }
    return tmp;
}


bool six(int i) {
    int cnt = 0;
    while (i > 0) {
        if (i % 10 == 6) {
            if (three(i)) {
                return true;
                break;
            }
        }
        i /= 10;
    }
    return false;
}


int main() {
    int count = 0;

    //입력
    int n;
    cin >> n;

    //연산, 출력
    for (int i = 666; i < 2666800;i++) {
        if (six(i)) {
            count++;
        }
        if (count == n) {
            cout << i;
            break;
        }
    }
    return 0;
}