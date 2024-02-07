#include<iostream>
using namespace std;

int main() {
	int DAT[31] = { 0, };
	int arr[10] = { 27, 30, 28, 22, 7, 10, 20,1,11,5 };

	int Q;
	cin >> Q;

	for (int i = 0; i < 10; i++) {
		DAT[arr[i]] = 1;


	}
	//Q만큼 확인
	for (int i = 0; i < Q; i++) {
		int num = 0;
		cin >> num;
		cout << num << ":" << DAT[num] << "\n";
	}

	//이중 포문 돌리는것보다 훨씬 적음

}