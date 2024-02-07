#include <iostream>
#include <queue>
using namespace std;

/*
5
___#_
___#_
##___
__#__
_____
0 0 4 0
*/

int N;
char M[5][5];
int visited[5][5];
int elsaY, elsaX;
int annaY, annaX;
struct Node {
	int y;
	int x;
};
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(int y, int x) {
	queue<Node> q;

	q.push({ y ,x });
	visited[y][x] = 1;

	while (!q.empty()) {
		Node now = q.front();

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dr[i];
			int nx = now.x + dc[i];

			if (ny >= 5 || nx >= 5 || ny < 0 || nx < 0) continue;
			if (M[ny][nx] == '#') continue;// 장애물이면 continue;
			if (visited[ny][nx] != 0) continue;


			q.push({ ny,nx });
			visited[ny][nx] = visited[now.y][now.x] + 1;
		}
	}
	int de = -1;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M[i];

	}
	cin >> elsaY >> elsaX >> annaY >> annaX;

	bfs(elsaY, elsaX);

	int ans = visited[annaY][annaX] /  2;

	cout << ans;

	return 0;
}

