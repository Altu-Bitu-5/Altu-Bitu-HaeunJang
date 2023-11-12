#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> p;

//1. 왼쪽-위부터 바둑돌이 놓아져 있는지 확인한다.
//2. 바둑돌을 발견한다면 그 바둑돌 기준으로 오른쪽, 아래, 오른쪽-아래, 왼쪽-아래에 같은 색 바둑돌이 있는지 확인한다.
//3. 같은색 바둑돌을 발견한다면 그 방향으로 정확히 5개의 바둑돌이 놓여져있는지 확인한다.
//4. 만약 5개의 바둑돌이 놓여져있다면, 처음으로 발견한 바둑돌 반대 방향에 같은 색 바둑돌이 있는지 확인한다. (6개가 아닌지 확인)

bool dfs(int color, int cnt, int r, int c, vector<vector<int>>& v, int ud, int rl){
    int nr = r + ud;
    int nc = c + rl;

    if(nr>=0 && nc>=0 && nr<19 && nc<19 && v[nr][nc]==color){
        cnt++;
        return dfs(color, cnt, nr, nc, v, ud, rl);
    }
    else if(cnt==5) return true; //같은 방향으로 5번 나올시 승
    return false;
}

void check(int color, int r, int c, vector<vector<int>>& v, p& ans){
    //왼쪽-위에서부터 탐색하므로 오른쪽, 아래, 오른쪽-아래, 왼쪽-아래 대각선만 봐도 된다.
    int n[4]={1,0,1,-1};
    int m[4]={0,1,1,1};
    
    for(int i=0;i<4;i++){ 
        int nr = r + n[i];
        int nc = c + m[i];
        
	//연결된 같은색 바둑돌을 발견 시 같은 방향으로 dfs 탐색
        if(nr>=0 && nc>=0 && nr<19 && nc<19 && v[nr][nc]==color){
            if(dfs(color, 2, nr, nc, v, n[i],m[i])){
		//5개 이상부터는 답이 아니므로 반대 방향 같은 색인지 확인
                int pr = r-n[i];
                int pc = c-m[i];
                if(pr>=0&&pc>=0&&pr<19&&pc<19&&v[pr][pc]==color){
                    continue;
                }
                ans = make_pair(r,c);
                break;
            }
        }
    }
}

p find_win(vector<vector<int>>& v){ //왼쪽-위부터 바둑알 탐색
    p ans={-1,-1}; 
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(v[i][j]==1){
                check(1,i,j,v,ans);
            }
            else if(v[i][j]==2){
                check(2,i,j,v,ans);
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<vector<int>> v(19,vector<int>(19,0));

    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin >> v[i][j];
        }
    }
    p ans = find_win(v);
    if(ans!=make_pair(-1,-1)){
        cout << v[ans.first][ans.second] << "\n";
        cout << ans.first+1 << " " << ans.second+1;
    }
    else cout<<0;
    return 0;
}