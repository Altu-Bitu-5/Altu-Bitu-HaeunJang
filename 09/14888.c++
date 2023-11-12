#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
const int ADD=0, SUB=1, MUL=2, DIV=3;
const int INF=1e9;
vector<int> num(11,0);
vector<int> calc(4,0);
int max_val=-INF, min_val=INF;

void backtrack(int cnt, int ans){ //백트래킹
    //연산자를 다 쓴 경우 재귀 호출 종료
    if(cnt==n-1){
        max_val=max(max_val,ans); //최댓값 저장
        min_val=min(min_val,ans); //최솟값 저장
        return;
    }
    //연산
    for(int i=0;i<4;i++){
        if(calc[i]==0){ //연산 기호 다 씀 (연산 끝)
            continue;
        }
        calc[i]--; //연산
        int new_ans=0;
        switch(i){
            case ADD:
                new_ans = ans + num[cnt+1];
                break;
            case SUB:
                new_ans = ans - num[cnt+1];
                break;
            case MUL:
                new_ans = ans*num[cnt+1];
                break;
            case DIV:
                new_ans = ans / num[cnt+1];
                break;
        }
    
        backtrack(cnt+1, new_ans);
        calc[i]++; //연산자 반납
    
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    for(int i=0;i<4;i++){ 
        cin >> calc[i];
    }
    
    //연산
    backtrack(0,num[0]);

    //출력
    cout << max_val << "\n" << min_val;
    
    return 0;
}