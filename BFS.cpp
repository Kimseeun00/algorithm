#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//int wt = 0;
//int visited[6];

//1. ť ��⿭ �غ�
// //2. ������ ť�� ���
// //3. �� �տ� �ִ� ��带 Ȯ���ϰ� ����
// //4. ����� ���� ����Ǿ� �־��� �ٸ� ��� Ž��
// //5. next�� �ش��ϴ� �ٸ� ��带 ť�� ���
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