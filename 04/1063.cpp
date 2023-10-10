#include <iostream>

using namespace std;

int k_x = 1, k_y = 1;
int s_x = 1, s_y = 1;

void start(string s, int& x, int& y) {
    x = int(s[0]) - 64;
    y = s[1] - 48;
}

bool move(string m, int& x, int& y) {
    int temp_x = x;
    int temp_y = y;

    for (int i = 0;i < m.length();i++) {
        switch (m[i]) {
        case 'R':
            ++temp_x;
            break;
        case 'L':
            --temp_x;
            break;
        case 'B':
            --temp_y;
            break;
        case 'T':
            ++temp_y;
            break;
        }
    }
    if (temp_x == s_x && temp_y == s_y) {
        if (move(m, s_x, s_y)) {
            move(m, k_x, k_y);
            return true;
        }
        return false;
    }
    else if (1 <= temp_x && temp_x <= 8 && 1 <= temp_y && temp_y <= 8) {
        x = temp_x;
        y = temp_y;
        return true;
    }
    else return false;
}

int main() {
    string king, stone;
    int n;

    cin >> king >> stone >> n;
    start(king, k_x, k_y);
    start(stone, s_x, s_y);

    string m;
    while (n--) {
        cin >> m;
        move(m, k_x, k_y);
    }
    cout << char(k_x + 64) << k_y << "\n" << char(s_x + 64) << s_y;
    return 0;
}