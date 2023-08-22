// 시리얼 번호 #1431

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct serial
{
    int len;
    string input;
};

bool cmp(const serial &s1, const serial &s2)
{
    int s1sum = 0;
    int s2sum = 0;

    if (s1.len != s2.len)
    {
        return s1.len < s2.len;
    }
    for (int i = 0; i < s1.len; i++)
    {
        if (s1.input[i] <= '9' && s1.input[i] >= '0')
        {
            s1sum += s1.input[i] - '0';
        }
        if (s2.input[i] <= '9' && s2.input[i] >= '0')
        {
            s2sum += s2.input[i] - '0';
        }
    }
    if (s1sum != s2sum)
    {
        return s1sum < s2sum;
    }
    return s1.input < s2.input;
};

int main()
{
    int n;
    cin >> n;
    vector<serial> my_class;
    my_class.assign(n, {});

    for (int i = 0; i < n; i++)
    {
        cin >> my_class[i].input;
        my_class[i].len = my_class[i].input.length();
    }

    sort(my_class.begin(), my_class.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << my_class[i].input << '\n';
    }
    return 0;
}
