#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//각 단어의 알파벳 빈도수를 vector에 저장한 후, 빈도수를 비교하여 비슷한 단어를 판별한다.

const int WORD = 26;

void countFreq(string s, vector<int>& v){ //알파벳 빈도수 계산
    for(int i=0;i<s.length();i++){
        v[s[i]-'A']++;
    }
}

//기준 알파벳과 알파벳 빈도수 비교
int cmpFreq(vector<int> a, vector<int> b){
    int cnt=0;
    for(int i=0;i<WORD;i++){
        if(a[i]!=b[i]){
            cnt += abs(a[i]-b[i]);
        }
    }
    return cnt; //다른 빈도수만큼 반환
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n;
    cin >> n;
    
    string a;
    cin >> a;
    vector<int> a_v(WORD,0);
    countFreq(a,a_v);
    
    int ans=0;
    for(int i=0;i<n-1;i++){
        string b;
        cin >> b;
        vector<int> b_v(WORD,0);
        countFreq(b,b_v);
        
        int cnt = cmpFreq(a_v,b_v);
        if(cnt==0||cnt==1||cnt==2&&a.length()==b.length()) ans++;
        //빈도수의 차가 0, 1 또는 2인데 길이가 같을때(하나를 바꾸면 같은 경우) 비슷한 단어
    }
    
    cout << ans;
    return 0;
}