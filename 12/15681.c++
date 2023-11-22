#include <iostream>
#include <vector>

using namespace std;

//1. 모든 간선 정보를 이차원 벡터에 저장한다.
//2. 각 노드의 정점의 수를 저장할 수 있는 vector<int> node(n+1,1) 을 만든다. (초기값이 1인 이유는 자기 자신도 포함해야하기 때문)
//3. dfs를 통해 가장 마지막 자식 노드(자식이 없는 노드)의 정점의 수를 부모 노드의 정점 수에 더하도록 한다. 

void dfs(int cur, int prev, vector<vector<int>>& v, vector<int>& node){
    for(int next : v[cur]){
        if(next==prev){
            continue;
        }
        dfs(next, cur, v, node);
        node[cur]+=node[next];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, r, q; //정점의 수, root, 쿼리의 수 
    cin >> n >>  r >> q;
    
    vector<vector<int>> graph(n+1,vector<int>(0));
    int u,v;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> node(n+1,1); //각 트리의 자식 노드 수 
    dfs(r, 0, graph, node);

    for(int i=0;i<q;i++){
        cin >> u;
        cout << node[u] << "\n";
    }

    return 0;
}