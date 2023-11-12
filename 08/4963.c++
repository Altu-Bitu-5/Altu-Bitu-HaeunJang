#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> p;

const int VISITED = 2;

void bfs(int i, int j, int w, int h, vector<vector<int>>& v){
    //상하좌우 대각선 한 칸씩
    int n[8]={1, -1, 0, 0,1,1,-1,-1}; 
    int m[8]={0, 0, 1, -1,1,-1,1,-1};
    
    queue <p> q;
    q.push({i,j});
    v[i][j]=VISITED;

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for(int i=0;i<8;i++){ //기준 칸의 상하좌우, 대각선 모두 보기
            int nr = r+n[i];
            int nc= c + m[i];
            
            if(nr>=0 && nc>=0 && nr<h && nc<w && v[nr][nc]==1){
                q.push({nr,nc});
                v[nr][nc]=VISITED;
            }
        }
    }
}

int cntIsland(int h, int w, vector<vector<int>> &v){
    int cnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(v[i][j]==1){ //섬 발견
                cnt++; //섬 개수 ++;
                bfs(i,j,w,h,v); //이어진 땅 찾기
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> v;
    queue <p> q;
    
    while(true){
        int w, h;
        cin >> w >> h;
        if(w==0 && h==0) break; //0 0 입력시 종료
        
        v.assign(h, vector<int> (w,0)); //땅 정보
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> v[i][j];
            }
        }
        cout << cntIsland(h,w,v)<<"\n";
    }
    
    return 0;
}