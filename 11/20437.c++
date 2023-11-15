#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int,int> p;

int cnt = 0;

void find(int k, vector<vector<int>>& num, int min){
    int max_length=0, min_length=min+1;
    int length=0;
    
    for(int i=0;i<27;i++){
        if(num[i].size()>=k){
            for(int j=0;j<=num[i].size()-k;j++){
                length = num[i][j+k-1] - num[i][j] + 1;
                if(length>max_length) max_length=length;
                if(length<min_length) min_length=length;
            }
        }
    }
    if(min_length==min+1){
        cout << -1 << "\n";
        return;
    }
    else{
        cout<< min_length << " " << max_length << "\n";
    }   
}

int main(){
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, k;
    string s;
    
    cin >> t;
    while(t--){
        cin >> s >> k;
        vector<int> v;
        vector<vector<int>> num(27,vector<int>(0,0));

        for(int i=0;i<s.length();i++){
            num[s[i]-'a'].push_back(i);
        }
        find(k, num, s.length());
        
    }
    
    return 0;
}