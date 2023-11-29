#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> p;
const int INF = 250001;

//최종적으로 양 쪽 중 하나라도 true인 경우만 count 
//양방향으로 false라면 누가 우위인지 알 수 없다는 뜻 
int count(int n, vector<vector<bool>>& v){
    int cnt = 0;
    for(int i=1;i<n+1;i++){
        int flag = 1;
        for(int j=1;j<n+1;j++){
            if(i==j) continue;
            if(!v[i][j] && !v[j][i]){
                flag=0;
                break;
            }
        }
        if(flag) cnt++;
    }
    return cnt;
}

void floydWarshall(int n,vector<vector<bool>>& v){
    //v[1][5]=true, v[5][2]=true라면 v[1][2]도 true 
    for(int k=1;k<n+1;k++){ //중간 
        for(int i=1;i<n+1;i++){ //시작
            for(int j=1;j<n+1;j++){ //끝
                if(v[i][k] && v[k][j]){
                    v[i][j]=true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    //크기가 N * N인 이차원 벡터에 비교 결과를 bool형으로 저장한다. 
    vector <vector<bool>> v(n+1,vector<bool>(n+1,false));
    while(m--){
        int a, b;
        cin >> a >> b;
        
        v[a][b]=true; //a에서 b로 갈 수 있다면 true 
    }
    
    floydWarshall(n,v);
    cout << count(n,v);
    
    return 0;
}