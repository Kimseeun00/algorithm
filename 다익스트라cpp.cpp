/*  ( 노드 수/ 간선수)
9 10     
0 2 2 
2 3 37 
2 4 5 
4 1 17 
3 5 11 
4 5 45
4 6 9
5 7 4
6 7 9
7 8 28
*/

#include < iostream>
#include < algorithm>
#include < vector>
#include < queue>
#include <string>
using namespace std;

//BFS 매우 유사
//dist 정답 배열 : 0~ 특정 노드까지의 최단 거리 기록
// Queue > priorityQueue : 노드 추출시 인접해 있는 경로를 추출하는게 아니라 거리가 제일 짧은 간선을 뽑아낸다

struct Edge {
	int num;
	int cost;

	bool operator<(Edge right) const{
		if (cost < right.cost) return false;
		else if (cost > right.cost) return true;
		return false;
	}
};
vector<Edge>alis[10];
int N, M;

void dijkstra(int node) {
	

	//1.pq 준비
	priority_queue<Edge>pq;
	//2. 정답 배열 만들기
	int dist[100] = { 0. };
	// 2_1. max값으로 초기화
	for (int i = 0; i < 100; i++) {
		dist[i] = 213546;
	}
	//2_2.시작 노드를 dist에 기록
	dist[node] = 0;
	//3. 시작 노드 등록
	pq.push({ node,0 });
	while (!pq.empty()) {
		// 4.큐 맨앞에 있는 노드 확인 및 추출
		Edge now = pq.top(); //현재 now위치에 있다~!
		pq.pop(); //특정 A ~> 현재 노드까지 최단거리임을 확정~! (pq에서 우선운쉬에 맞춰서 뽑았으니까!)


		//5. 추출된 노드에서 갈 수 있는 다른 후보 탐색
		for (int i = 0; i < alis[now.num].size(); i++) {
			Edge next = alis[now.num][i];//현재 now에서 갈 수 있는 (간서이 연결되어 있는) 후보를 하나씩 확인
			int nextcost = next.cost + dist[now.num]; // now까지의 최단거리 + now  > next 노드 사이의 거리 비용
			if (dist[next.num] <= nextcost) continue;
			pq.push({ next.num, nextcost });
			dist[next.num] = nextcost; //다음으로 진행할 때의 비용을 기록
		}
	}
	for (int i = 0; i < N; i++) {
		cout << i << ":" << dist[i] << "\n";
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		alis[from].push_back({ to, cost });
	}
	dijkstra(0);
	return 0;

}
//priority queue 데이터 추가 삭제 는 0log(N)
//o(1) 노드 확인
// 장점: 데이터 추가 삭제 logN
//		우선순위에 맞는 최대값 최소값을 찾기 좋다
//단점: 중간값을 찾기 어렵다.

//===========sort ===nlog(N)
//장점: 중간값을 찾기 좋다
//단점: 데이터 추가 삭제 효율성이 떨어짐.

//===============================

// 