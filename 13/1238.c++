#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e5; //최대 경로 값 (간선의 수 * 가중치 최대값)

vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
	vector<int> dist(v + 1, INF); // 각 정점까지의 최단 경로 저장
	priority_queue<ci> pq;
	// 시작 정점 초기화
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int w = -pq.top().first; // 현재 정점까지의 경로값
		int n = pq.top().second; // 현재 탐색하려는 정점
		pq.pop();
		if (w > dist[n]) { // 이미 다 작은 경로가 있다면 continue 
			continue;
		}
		for (auto [nxt_node, nxt_weight] : graph[n]) {
			if (dist[nxt_node] > dist[n] + nxt_weight) { //최소값 갱신
				dist[nxt_node] = dist[n] + nxt_weight;
				pq.push({ -dist[nxt_node],nxt_node }); 
			}
		}
	}
	return dist;
}

int main() {
	int v, e, k, a, b, w;
	int answer = 0;
	//입력
	cin >> v >> e >> k;
	vector<vector<ci>> graph(v + 1, vector<ci>(0)); // 인접 리스트
	while (e--) {
		cin >> a >> b >> w;
		graph[a].push_back({ b, w });
  	}
	// 연산
	// 가고 오는 시간을 다익스트라 알고리즘을 사용해 따로 구한다. 
	vector<int> go(v + 1), back;
	//파티 장소로 가는데 걸리는 시간 (모든 정점 -> 파티 장소)
	for (int i = 1; i <= v; i++) {
		vector<int> tmp = dijkstra(i, v, graph);
		go[i] = tmp[k]; //각 정점에서 출발했을 때 파티 장소까지의 최단 경로 
	}
	// 집으로 오는데 걸리는 시간 (파티 장소 -> 모든 정점)
	back = dijkstra(k, v, graph);

	//총 걸리는 시간 비교
	for (int i = 1; i <= v; i++) {
		answer = max(answer, go[i] + back[i]);
	}
	// 출력
	cout << answer;
	return 0;
}