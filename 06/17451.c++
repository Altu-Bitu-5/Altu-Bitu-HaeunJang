#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

//1. 최소 속도값을 구하기 위해서는 뒤에서부터 봐야한다.
//2. 기준값을 잡아서 기준값보다 큰 수라면 그 수로 기준값을 업데이트한다.
//3. 기준값보다 작은 수라면 기준값보다 큰 작은 수의 배수를 계산한 후 기준값을 업데이트한다.
//4. 최종적으로 기준값에 저장된 수가 정답이 된다.


ll calc(vector<ll>& v){
    ll ans=0;
    for(int i=v.size()-1;i>=0;i--){ //뒤에서부터 순회
        if(ans<v[i]) ans = v[i]; //기준값보다 크다면 그대로 업데이트
        else{ //기준값보다 작다면 기준값보다 처음으로 큰 배수로 업데이트
            ll tmp = ans/v[i];
            if(ans%v[i]>0) tmp +=1;
            ans = v[i]*tmp;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    int n;
    cin >> n;
    
    vector<ll> v(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cout << calc(v);
    
    return 0;
}