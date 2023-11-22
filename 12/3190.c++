#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int direction(char c){
    switch (c){
        case 'L': //왼쪽 회전
            return 1;
        case 'D': //오른쪽 회전 
            return -1;
    }
}

int move(vector<vector<int>>& v, queue <pair<int,char>> change, int num){
    int t=0, r=1, c=1, i=0;
    int n[4] = {0,-1,0,1}; //동, 남, 서, 북 
    int m[4] = {1,0,-1,0};
    
    queue <pair<int,int>> snake;
    snake.push({1,1});

    while(true){
        if(t==change.front().first){ //방향 변환 
            i += direction(change.front().second);
            change.pop();
            if(i>3){
                i=0;
            }
            if(i<0){
                i=3;
            }
        }
        
        int n_r = r + n[i];
        int n_c = c + m[i];
	//맵 밖으로 나가거나 몸과 부딪히며면 끝
        if(n_r<=0 || n_c<=0 || n_r>num || n_c>num || v[n_r][n_c]==1){
            return t;
        }
	//아무것도 없는 칸이라면 꼬리 자름 (몸 길이 유지) 
        else if(v[n_r][n_c]==0){
            v[snake.front().first][snake.front().second]=0;
            snake.pop();
        }
        snake.push({n_r,n_c});
        v[n_r][n_c]=1;
        r = n_r;
        c = n_c;
        t++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    int n1, n2;
    vector<vector<int>> v(n+1,vector<int>(n+1,0));
    v[1][1]=1; //맨위 맨좌측에서 시작
    while(k--){
        cin >> n1 >> n2;
        v[n1][n2] = 2; //사과 표시 
    }
    
    queue <pair<int,char>> change; //방향 변환 정보 저장 
    int l, x;
    char c;
    cin >> l;
    while(l--){
        cin >> x >> c;
        change.push(make_pair(x,c));
    }
    cout << move(v,change, n)+1;
    
   
   return 0;
}