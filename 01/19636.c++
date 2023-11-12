#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t)
{
    // w: 몸무게, m: 기초대사량
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 안했을 때
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 했을 때

    while (d--)
    {
        // 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w1 += i - (m1 + a);
        w2 += i - (m2 + a);

        // 일일 기초대사량 변화
        if (abs(i - (m2 + a)) > t)
        {                                    //|일일 에너지 섭취량 - 일일 에너지 소비량| > 기초 대사량 변화 역치
            m2 += float(i - (m2 + a)) / 2.0; // 일일 기초 대사량 += ⌊(일일 에너지 섭취량 − 일일 에너지 소비량) / 2⌋
        }
    }
    return {w1, w2, m2};
}
int main()
{
    int w0, i0, i, a;
    int d, t;
    int final_weight, final_meta;
    // 입력
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

    // 연산
    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t);
    int w1 = get<0>(tmp), m1 = i0;
    int w2 = get<1>(tmp), m2 = get<2>(tmp);

    // 출력
    if (w1 <= 0)
    { // 체중 0 이하인 경우
        cout << "Danger Diet\n";
    }
    else
    {
        cout << w1 << " " << m1 << "\n";
    }

    if (w2 <= 0 || m2 <= 0)
    { // 체중 or 일일 기초대사량 0 이하인 경우
        cout << "Danger Diet";
    }
    else
    {
        cout << w2 << " " << m2 << " ";
        if (m2 < i0)
        { // 변화한 일일 기초대사량 < 기존 일일 기초대사량인 경우 요요
            cout << "YOYO";
        }
        else
        {
            cout << "NO";
        }
    }
    return 0;
}