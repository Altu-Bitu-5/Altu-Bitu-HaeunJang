#include <iostream>
<<<<<<< Updated upstream
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 1. 각 시리얼 번호를 문자열로 받아 배열에 차례대로 저장한다.
// 2. sort의 비교함수를 사용하여 각 조건대로 swap 한다.

bool cmp(string &a, string &b)
{ // 비교 함수
    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < a.length(); i++)
    { // 문자열 내 모든 수 합
        if (isdigit(a[i]))
        {
            sum_a += a[i] - '0'; // char을 int로
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (isdigit(b[i]))
        {
            sum_b += b[i] - '0';
        }
    }
    if (a.length() != b.length())
    { // 1. 길이 비교
        return a.length() < b.length();
    }
    else if (sum_a != sum_b)
    { // 2. 문자열 내 숫자 합 비교
        return sum_a < sum_b;
    }
    else
    { // 3. 사전순 비교
        return a < b;
    }
}
=======
#include <set>

using namespace std;

// 검색 시간 복잡도가 O(log2n)으로 낮은 Set을 사용한다.
>>>>>>> Stashed changes

int main()
{
    // 입력
<<<<<<< Updated upstream
    int n;
    cin >> n;

    vector<string> v(n, "");

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 연산
    sort(v.begin(), v.end(), cmp);

    // 출력
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\n";
    }
=======
    int n, m;
    cin >> n >> m;

    set<string> s;
    while (n--)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    // 연산
    int cnt = 0;
    while (m--)
    {
        string input;
        cin >> input;
        if (s.find(input) != s.end())
        {
            cnt++;
        }
    }

    // 출력
    cout << cnt;
>>>>>>> Stashed changes
    return 0;
}