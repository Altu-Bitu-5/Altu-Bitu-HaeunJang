#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int XY = 101;
typedef pair<int,int> p;

vector<vector<int>> v(XY, vector<int>(XY,0));
int x, y;

void move(int d, int g, int cnt, vector<int>& directions){
    int n[4] = {1,0,-1,0};
    int m[4] = {0,-1,0,1};
    
    if(cnt>g) return;
    if(cnt==0){ //0세대 
        v[x][y]=true;
        x += n[d];
        y += m[d];
        v[x][y]=true;
        directions.push_back(d);
        cnt++;
        move(d,g,cnt,directions);
    }
    else{ //n세대라면 (n>0) 
        int tmp=1, idx=directions.size();
	//방향 벡터의 크기가 2^n가 될 때까지 방향 정보를 생성해준다. 
	//새로운 방향은 기존의 방향과 데칼코마니 형식으로 1씩 증가시켜준다. 
	//즉, 3세대고 초기 방향이 0이라면 
	// 0세대 : 0
	// 1세대 : 0, 1
	// 2세대 : 0, 1, 2, 1
	// 3세대 : 0, 1, 2, 1, 2, 3, 2, 1
	// 위와 같은 형식으로 방향 값을 구해 저장해주고 해당 방향으로 움직여 준다. 
        while(directions.size()!=pow(2,cnt)){ 
            int d = directions[idx-tmp]+1; 
            if(d>3) d=0;
            directions.push_back(d);
            idx++;
            tmp+=2;
            
            x += n[d];
            y += m[d];
	
            if(x<=100 && y<=100 && x>=0 && y>=0) {
                v[x][y]=true;
            }
        }
        cnt++;
        move(d,g,cnt,directions);
    }
}

int checkAns(){ //(0,0)부터 출발해서 네 꼭짓점이 모두 true일 때 count 해준다.
    int ans=0;
    for(int i=0;i<XY-1;i++){
        for(int j=0;j<XY-1;j++){
            if(v[i][j]&&v[i+1][j]&&v[i][j+1]&&v[i+1][j+1]){
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    while(n--){
        int d,g;
        cin >> x >> y >> d >> g;
        
        vector<int> directions; //방향 정보를 저장한다. 
        move(d,g,0,directions);
    }
    
    cout << checkAns();

    return 0;
}