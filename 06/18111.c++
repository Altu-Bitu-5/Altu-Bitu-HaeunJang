#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<long long, long long> p;
const int MAX = 257;

//1. 초기의 높이값의 빈도수를 vector에 저장한다.
//2. 0부터 256까지 기준 높이를 정해, 빈도수를 저장한 vector를 사용하여 시간을 모두 구한다.
//3. 시간과 높이를 함께 저장하여 sort를 통해 조건대로 정렬한다.

bool cmp(p& p1, p& p2){
    if(p1.first!=p2.first) return p1.first < p2.first;
    return p1.second > p2.second;
}

p build(int block, vector<ll> height, int max){
    vector<p> ans;
    for(int i=0;i<=max;i++){
        int b = block; 
        ll t=0;
        for(int j=i+1;j<=max;j++){ //기준 높이보다 높다면
            if(height[j]>0){
                ll tmp = (j-i)*height[j];
                t+=2*tmp;
                b+=tmp;
            }
        }
        for(int k=i-1;k>=0;k--){ //기준 높이보다 낮다면
            if(height[k]>0){
                ll tmp = (i-k)*height[k];
                t+=tmp;
                b-=tmp;
            }
        }
        if(b<0) continue;
        ans.push_back(make_pair(t,i));
    }
    sort(ans.begin(), ans.end(),cmp);
    return ans[0];
}


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n,m,b;
    cin >> n >> m >> b;
    
    vector<ll> v(MAX,0);
    vector<p> height;
    int max=0;
    while(n--){ //초기 블록 높이를 빈도수로 저장
        for(int i=0;i<m;i++){
            int j;
            cin >> j;
            if(max<j) max=j;
            v[j]++;
        }
    }
    p ans = build(b,v,max);
    cout << ans.first << " " << ans.second;
    
    
    return 0;