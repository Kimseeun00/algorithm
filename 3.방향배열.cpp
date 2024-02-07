#include<iostream>
using namespace std;

int main() {
	int x, y;
	
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };

	int sum = 0; 

	int x, y;
	cin >> x >> y;

	/*if (y - 1 >= 0)//예외 처리
		sum += arr[y-1][x];
	sum += arr[y+1][x];
	sum += arr[y][x-1];
	sum += arr[y][x-1];
		
	return 0;
	*/
	// 위에껀 예외 처리 까지 넣으면 코드가 너무 길어짐. 

	int ydir[8] = { -1,1,0,0,-1,1,1,-1 };
	int xdir[8] = { 0,0,-1,1,1,1,-1,-1 }; /// 탐색할 방향을 미리 배열에 저장해둠. 

	for (int i = 0; i < 8; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];

		if (ny >= 3 || ny < 0 || nx >= 3 || nx < 0)//예외처리
			continue;
		sum += arr[ny][nx];
	}
	// 조건이 추가 될때 쉽게 변경 가능
}