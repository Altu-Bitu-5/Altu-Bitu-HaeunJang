#include <iostream>
#include <vector>

using namespace std;
const int NUM=100001;

int findMax(int k, vector<int>& v){
    vector<int> num(NUM, 0); //윈도우에 들어온 수를 인덱스 번호로 저장

    int max=0, length=0, start=0; //최장 길이, 현재 길이, 수열 시작 포인터터
    for(int i=0;i<v.size();i++){
        num[v[i]]++;

        if(num[v[i]]<=k){
            length++;
            if(length>max) max = length;
            continue;
        }
        //중복 수가 k개 이상일 경우 max값 업데이트 후 초기화 
        for(int j=start; j<=i;j++){
            length--;
            num[v[j]]--;
            if(v[j]==v[i]){
                start=j+1;
                length++;
                break;
            }
        }
    }
    
    return max;
}

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    cout << findMax(k,v);
    
    return 0;
}