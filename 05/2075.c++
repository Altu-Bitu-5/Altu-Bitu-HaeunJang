#include <iostream>
#include <queue>

using namespace std;

//n개의 수만큼 입력 받을 때마다 pop을 하여 가장 작은 수를 없앤다.
//priority queue를 사용할 것이기 때문에 min heap으로 만들자.
//priority_queue<int, vector<int>, greate<int>> pq //min heap

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
    priority_queue<int, vector<int>, greater<int>> pq; //min heap
    int n;
    cin >> n;
    
    for(int i=0;i<n*n;i++){
        int a;
        cin >> a;
            
        pq.push(a);
        if(pq.size()>n){ //pq의 크기가 n보다 커질 때마다 pop
            pq.pop();
        }
    }
    
    cout << pq.top(); 
    
    return 0;
}