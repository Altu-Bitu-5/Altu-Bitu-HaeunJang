#include <iostream>
#include <vector>

using namespace std;

// 1. "회전" 초밥이므로 회전하여 만들 수 있는 묶음도 생각한다.
//k개의 묶음을 확인하려고 한다면, 0부터 k-1까지의 초밥을 vector의 뒷부분에 넣어준다. //즉, 총 n+k크기의 vector에 초밥 정보를 저장하게 된다.

//2. 슬라이딩 윈도우 방식을 사용해서 연속 k개의 초밥 중 다른 종류의 초밥 수(cnt)를 샌다.
//이를 위해 초밥 종류에 대한 벡터 vector<int> susi(d,0)를 사용한다.
//초밥 수를 샌 후에 쿠폰 초밥의 value가 0이라면 cnt 를 1증가해준 후에 max값에 반영해주고 다시 1을 빼준다.

//3. max를 출력한다.

int findMax(int k, int c, int d, vector<int>& v){
    vector<int> susi(d+1,0);
    int cnt=0;
    for(int i=0;i<k;i++){
        if(susi[v[i]]==0){
            cnt++;
        }
        susi[v[i]]++;
    }
    if(susi[c]==0) cnt++;
    int max = cnt;

    for(int i=1;i<=v.size()-k;i++){
        if(susi[c]==0) cnt--;

        int old_s = v[i-1];
        int new_s = v[i+k-1];
        
        if(susi[old_s]==1) cnt--;
        susi[old_s]--;
        if(susi[new_s]==0) cnt++;
        susi[new_s]++;
        
        if(susi[c]==0) cnt++;
        if(cnt>max) max=cnt;
    }
    return max;
}

int main(){
    int n,d, k, c;
    cin >> n >> d >> k >> c;
    
    //입력
    vector<int> v(n+k,0);
    for(int i=0;i<k;i++){
        int num;
        cin >> num;
        v[i]=v[n+i]=num;
    }
    for(int i=k;i<n;i++){
        cin >> v[i];
    }
    
    cout << findMax(k,c,d,v);
    
    return 0;
}