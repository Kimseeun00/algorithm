// N개의 정수 중 k개르 리용해서 만들 수 있는 수들의 합을 구하시오
// 이미 뽑았던 수는  뽑을 수 없다
#include<iostream>
using namespace std;

int n, k;
int arr[1000];
int DAT[10]; // path 라는 이름으로 많이 사용함. 
int DAT2[10];
void run(int now) {
	int sum;
	// 2. 기저 조건 - 언제 멈출것인가? -> 기저에서 무언가를 판별하면 시간초과 가능성이 높음
	if (now >= k) {  //{ k - 1 까지는 뽑고 k 부터는 뽑지 말어라
		for (int i = 0; i < k; i++) {
			//sum += DAT[i];
			cout << DAT[i] << " ";
		}
		cout << "=" << sum << "\n";
		return;
	}
	//1. 재귀 기본 recursive case
	for (int i = 0; i < n; i++) {
		//5. 판별 // 내가 이 선택을 하는게 맞는가??/ 맞아??/?? 난 안맞아
		// 앞에 있는 것만 보기 

		// 이렇게 코드를 처리하는것을 백트레킹이라고 함. 
		if (now > 0 && DAT[now - 1] - arr[i] == 1 ||
			DAT[now - 1] - arr[i] == -1) {
			continue;

		}
		if (DAT[arr[i]] == 1)continue;

		//3. 앞으로 진행되면서 실행되는 코드
		DAT[now] = arr[i];// index = now 번째,value = 뽑은 수
		DAT2[arr[i]] - 1;
		sum += arr[i]; // sum 계산

		run(now + 1);

		//4. 복구
		sum -= arr[i]; // 계산을 복구
		DAT[now] = 0; // 0으로 초기화
		DAT2[arr[i]] = 0;
	}

}
int main() {

	cin >> k >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];

	}
	run(0);
	return 0;

}
// 인접한 수로 1차이가 나는 수는 뽑을 수 없다
/*
#include<iostream>
using namespace std;
int sum;
int n, k;
int arr[1000];
int DAT[10]; // path 라는 이름으로 많이 사용함. 
void run(int now) {
	
	// 2. 기저 조건 - 언제 멈출것인가? -> 기저에서 무언가를 판별하면 시간초과 가능성이 높음
	if (now >= k) {  //{ k - 1 까지는 뽑고 k 부터는 뽑지 말어라
		for (int i = 0; i < k; i++) {
			//sum += DAT[i];
			cout << DAT[i] << " ";
		}
		cout << "=" << sum << "\n";
		return;
	}
 //1. 재귀 기본 recursive case
	for (int i = 0; i < n; i++) {
		//5. 판별 // 내가 이 선택을 하는게 맞는가??/ 맞아??/?? 난 안맞아
		// 앞에 있는 것만 보기 
		if (now > 0 && DAT[now - 1] - arr[i] == 1 ||
			DAT[now - 1] - arr[i] == -1) {
			continue;

		}

		//3. 앞으로 진행되면서 실행되는 코드
		DAT[now] = arr[i];// index = now 번째,value = 뽑은 수
		sum += arr[i]; // sum 계산

		run(n + 1);

		//4. 복구
		sum -= arr[i]; // 계산을 복구
		DAT[now] = 0; // 0으로 초기화
	}
		
}
int main() {

	cin >> k >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		
	}
	run(0);
	return 0;

}
/*
#include<iostream>
using namespace std;

int n, k;
int arr[1000];
int DAT[10];
void run(int now, int sum) {
	int sum = 0;

	// 2. 기저 조건 - 언제 멈출것인가?
	if (now == k) {  //{ k - 1 까지는 뽑고 k 부터는 뽑지 말어라
		for (int i = 0; i < k; i++) {
			//sum += DAT[i];
			cout << DAT[i] << " ";
		}
		cout << "=" << sum << "\n";
		return;
	}
	//1. 재귀 기본 recursive case
	for (int i = 0; i < n; i++) {

		//3. 앞으로 진행되면서 실행되는 코드
		DAT[now] = arr[i];// index = now 번째,value = 뽑은 수

		run(n, sum + arr[i]);
	}

}
int main() {

	cin >> k >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];

	}
	run(0, 0);
	return 0;

}
*/
/*
* // 전역변수로 구하기
#include<iostream>
using namespace std;
int sum;
int n, k;
int arr[1000];
int DAT[10]; // path 라는 이름으로 많이 사용함.
void run(int now) {

	// 2. 기저 조건 - 언제 멈출것인가?
	if (now >= k) {  //{ k - 1 까지는 뽑고 k 부터는 뽑지 말어라
		for (int i = 0; i < k; i++) {
			//sum += DAT[i];
			cout << DAT[i] << " ";
		}
		cout << "=" << sum << "\n";
		return;
	}
 //1. 재귀 기본 recursive case
	for (int i = 0; i < n; i++) {
		//5. 판별 // 내가 이 선택을 하는게 맞는가??/ 맞아??/?? 난 안맞아

		//3. 앞으로 진행되면서 실행되는 코드
		DAT[now] = arr[i];// index = now 번째,value = 뽑은 수
		sum += arr[i]; // sum 계산

		run(n + 1);

		//4. 복구
		sum -= arr[i]; // 계산을 복구
		DAT[now] = 0; // 0으로 초기화
	}

}
int main() {

	cin >> k >> n;

	int i;
	for (i = 0; i < n; i++) {
		cin >> arr[i];

	}
	run(0);
	return 0;

}
*/