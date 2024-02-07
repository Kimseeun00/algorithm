#include <iostream>
using namespace std;

int main() {

	int arr[10] = { 27, 30, 28, 22, 7, 10, 20,1,11,5 };
	// 배열의 이름은 메모리 상의 주소 값

	/*cout << arr[4];// []의미 => 배열의 시작 주소 + 데이터 타입 크기 (4바이트) * 2 
					// 해당하는 주소의 값

	cout << arr << "\n";
	*/

	int a;
	cin >> a;


	int i;
	for (i = 0; i < 10; i++) {
		if (a == arr[i])
			return 0;
	}
	return 1;
}