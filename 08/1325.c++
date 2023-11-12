#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> p;

//1. 컴퓨터들의 신뢰관계를 vector<vector<int>>에 저장하여 신뢰 방향을 알아볼 수 있도록 한다.
//2. 모든 컴퓨터를 한 번씩 해킹하여 각 컴퓨터에 따라 해킹할 수 있는 컴퓨터 수를 모두 구한다.
//3. 해킹할 수 있는 컴퓨터 수는 bfs 탐색을 통해 찾는다. (queue와 해킹 여부 bool vector 사용)
//4. 정렬하여 출력한다.

bool cmp(p& p1, p&p2){
    if(p1.first!=p2.first){
        return p1.first>p2.first;
    }
    return p1.second<p2.second;
}

int hack(int node, vector<vector<int>>&v, int n){ //bfs 탐색으로 해킹한다.
    queue<int> q; //해킹된 컴퓨터를 queue에 저장한다. (해당 컴퓨터를 신뢰하는 다른 컴퓨터를 찾는 용도)
    vector<bool> hacked(n+1, false); //해킹 여부를 bool vector에 저장한다.
    q.push(node); 
    hacked[node]=true;
    int cnt=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
	//해킹된 컴퓨터를 신뢰하는 모든 컴퓨터를 해킹한다.
        for(const auto& next : v[node]){ 
            if(!hacked[next]){
                q.push(next);
                hacked[next]=true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1,vector<int>(0));

    //신뢰 방향이 있으므로, 신뢰 받는 컴퓨터 인덱스에 신뢰하는 컴퓨터를 value로 넣는다.
    while(m--){ 
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    
    vector<p> ans;
    for(int i=n;i>0;i--){ //모든 컴퓨터를 한 번씩 해킹하여 전파된 컴퓨터 개수를 처음 해킹한 컴퓨터 번호와 함께 저장한다.
        int h = hack(i,v,n);
        ans.push_back({h,i});
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        if(ans[i].first==ans[0].first){
            cout << ans[i].second << " ";
        }
    }
    
    return 0;
}