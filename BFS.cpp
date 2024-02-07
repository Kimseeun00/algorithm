#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//int wt = 0;
//int visited[6];

//1. 큐 대기열 준비
// //2. 시작점 큐에 등록
// //3. 맨 앞에 있는 노드를 확인하고 추출
// //4. 추출된 노드와 연결되어 있었던 다른 노드 탐색
// //5. next에 해당하는 다른 노드를 큐에 등록
vector<int> alis[6];
queue<int>q;
int k;
char text[2] = { 'o','x' };
string path;
//char path[10];
// int alis[6][6];
/*int arr[6][6] = {
	{0,0,0,0,1,0},
	{1,0,1,0,0,1},
	{1,0,0,1,0,0},
	{1,1,0,0,0,0},
	{0,1,0,1,0,1},
	{0,0,1,1,0,0}
};
*/
void dfs(int now) {
	
	if (now == k) {
		cout << path << "\n";
		return;
	}
	for (int i = 0; i < 2; i++) {
		path += text[i];
		//cout << text[i];
		dfs(now + 1);
		path.pop_back();
	}
	
}
int main() {


	cin >> k;

	dfs(0);

	return 0;

}