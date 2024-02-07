#include <iostream>
#include <queue>
using namespace std;
int visited[5][5];
int startY, startX;
//길: 0 장애물 : -3
int M[5][5] = {
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0
};
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
struct Node {
	int y;
	int x;
};

void bfs(int y, int x) {

	queue<Node>q;

	q.push({ y, x });
	visited[y][x] = 1;
	M[y][x] = 1;
	while (!q.empty() ) {
		Node now = q.front();

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];

			if (ny >= 5 || nx >= 5 || ny < 0 || nx < 0) continue;
			if (visited[ny][nx] != 0) continue;
			//if (M[ny][nx] < 0) continue;// 장애물이면 continue;
			//
			q.push({ ny,nx });
			visited[ny][nx] = visited[now.y][now.x] + 1;
			M[ny][nx] = visited[ny][nx];
		}
	}
	int de = -1;
}
void print() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	cin >> startY >> startX;
	bfs(startY, startX);
	print();
	return 0;
}