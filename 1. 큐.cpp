#include <iostream>
#include<queue>
using namespace std;
int N, M;
vector<int>alis[15];//노드의 맨 마지막 번호 + 1
int visited[15];
/*
6 7
1 2
1 4
2 3
2 5
3 6
4 6
4 5
*/

//1. 큐 대기열 준비
// //2. 시작점 큐에 등록
// //3. 맨 앞에 있는 노드를 확인하고 추출
// //4. 추출된 노드와 연결되어 있었던 다른 노드 탐색
// //5. next에 해당하는 다른 노드를 큐에 등록
// 
//visited 처리 : 동일한 노드를 다시 복원하는 것을 처리 
//int cnt= 0;
void bfs(int node) {
	//1. 큐 대기열 준비
	queue<int>q;

	//2. 시작점 큐에 등록
	q.push(node); // 시작점 (1번 노드 등록)
	
	visited[node] = 1;

	while (!q.empty()) {
		//3. 맨 앞에 있는 노드를 확인하고 추출
		int now = q.front();// 큐 맨앞에 있는 노드를 확인
		q.pop();// 큐에서 노드 추출
		

		cout << now << " ";

		//4. 추출된 노드와 연결되어 있었던 다른 노드 탐색
		for (int i = 0; i < alis[now].size(); i++) {
			//now -> next 가 될 수 있는 다른 후보들 찾기
			// 비지트 판별

			int next = alis[now][i];

			if (visited[next] != 0)continue;
		
			
			//5. next에 해당하는 다른 노드를 큐에 등록
			q.push(next); // now에서 next로 가도 된다!!
			visited[next] = visited[now] + 1;

			
		}
	}
	cout << "\n";
	for (int i = 1; i < 6; i++) {
		cout << i << " = " << visited[i] << "\n";

	}

}
//queue<int>q; // queue 키워드 +<자료형 타익> + 이름, 대기열 들어온 순서대로 나감. 

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		alis[from].push_back(to);
	}
	bfs(1);
}