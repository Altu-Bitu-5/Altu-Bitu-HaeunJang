#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
set<int> s;
vector<int> ans;

void backtrack(int cnt){ //백트래킹
    if(cnt==m){ //m개의 수를 채웠을때 재귀 호출
        for(int i=0;i<m;i++){
            cout<<ans[i]<<" ";
        }
        cout <<"\n";
        return;
    }
    for(auto it: s){ //중복 허용하여 숫자 선택
        ans[cnt]=it;
        backtrack(cnt+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    ans.assign(m,0);
    
    for(int i=0;i<n;i++){ //set에 저장하여 중복 없애고 오름차순 정렬
        int x;
        cin >> x;
        s.insert(x);
    }

    backtrack(0);
    
    return 0;
}