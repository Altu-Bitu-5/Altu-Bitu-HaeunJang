#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//1. 앞 단어부터 같은 단어가 있는지 확인한다.
//2. 순서대로 vector에 저장한다. (두 개의 같은 단어 중 한 단어만)
//3. 짝지어지지 않은 단어가 한 개 이상이라면 실패한다.
//4. vector을 정렬 후 순서대로 출력 + 단어 한 개 있다면 출력 + vector를 역순으로 출력

void check_ans(string s, vector<char> ans){
    for(int i=0;i<s.length();i++){
        if(s[i]=='.') continue;
        for(int j=i+1;j<s.length();j++){
            if(s[i]==s[j]){
                ans.push_back(s[i]);
                s[i]=s[j]='.';
                break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    
    int cnt=0;
    char word;
    for(int i=0;i<s.length();i++){
        if(s[i]!='.') {
            cnt++;
            word=s[i];
        }
    }
    if(cnt>1) cout << "I'm Sorry Hansoo";
    else{
        for(auto it : ans){
            cout << it;
        }
        if(cnt==1){
            cout << word;
        }
        for(auto it=ans.rbegin();it!=ans.rend();it++){
            cout << *it;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    string s;
    cin >> s;
    
    vector<char> ans;
    check_ans(s, ans);
    
    return 0;
}