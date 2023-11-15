#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> p;

int cnt = 0;

p direction(int d){
    switch(d){
        case(0): //북
            return {-1,0};
        case(1): //동
            return {0,1};
        case(2): //남 
            return {1,0};
        case(3): //서 
            return {0,-1};
    }
}

//특정 경로가 있는 탐색이므로 dfs를 사용하였다.
void move(int r, int c,int d, vector<vector<int>>& v){
    if(v[r][c]==0){
        cnt++;
        v[r][c]=-1;
    } 
    
    for(int i=0;i<4;i++){
        d--;
        if(d<0) d=3; //반시계 방향 회전 (북-서-남-동)
        p dd = direction(d);

        int next_r = r + dd.first;
        int next_c = c + dd.second;
        
        if(v[next_r][next_c]==0){ //청소할 블록이 있는 경우 dfs
            move(next_r, next_c, d, v);
        }
    }
    //주변에 청소할 블록이 없는 경우 후진
    p dd = direction(d);
    int next_r = r - dd.first;
    int next_c = c - dd.second;
    
    if(v[next_r][next_c]!=1) { //후진할 블록이 벽이 아닌 경우 dfs
        move(next_r, next_c, d, v);
    }
    
    else cout<< cnt;
    exit(0);
}

int main(){
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;
    
    vector<vector<int>> v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j] ;
        }
    }
    
    move(r,c,d,v);
    
    return 0;
}