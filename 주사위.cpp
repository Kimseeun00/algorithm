// 주사위 눈 1~6, N을 입력 받아서, N개의 주사위 눈의 조합으로 나올 수 있는 조합을 모두 출력하시오.
// 단, 같은 눈을 사용하는 케이스는 제외.
#include<iostream>
using namespace std;

int sum;
int N, k;
int arr[1000];
int DAT[10]; // path 라는 이름으로 많이 사용함. 
int path[10];
void func(int now) {
	if (now - 1 > 0 && DAT[path[now - 1]] >= 2)
		return;
	//2. 기저
	if (now >= N) {
		for (int i = 0; i < N; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++) {
		//3.판별
		if (DAT[i] == 1) continue;

		//4.기록 및 계산
		path[now] = i;
		DAT[i] = 1;
		//1. 가라
		func(now + 1);

		//5.기록 및 계산을 복구
		path[now] = 0;
		DAT[i] = 0;
	}
	
}
int main() {
	cin >> N;

	func(0);
	return 0;
}