#include <iostream>
#include <queue>

using namespace std;

//산타가 가지고 있는 선물을 가치가 큰 순으로 아이들에게 주기 때문에 priority queue의 Max heap을 사용한다.

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	priority_queue<int> pq; //산타가 가장 큰 선물 순서대로 주므로, MAX Heap사용
	
    int n;
    cin >> n;
    
    while(n--){
        int a;
        cin >> a;
        
        if(a==0){ //아이들에게 선물 줄때
            if(pq.empty()) cout << -1 << "\n"; //선물 없음
            else { //가장 큰 선물 출력 후 삭제
                cout << pq.top() << "\n"; 
                pq.pop();
            }
        }
        else{ //거점지에 들렀을때
            while(a--){
                int present;
                cin >> present;
                
                pq.push(present); //선물 가치 pq에 저장
            }
        }
    }
    
    return 0;
}