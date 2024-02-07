#include <iostream>
using namespace std;

/*
 1. 지역변수인 경우 
void func() {
	int a = 10;
}
int main() {
	int a = 5;
	cout << a;
	func();
	cout << a;

	return 0;
}

*/


 // 2. 지역 변수인 경우
/*
int a = 5;
void func() {
	 a = 10;
}
int main() {
	
	cout << a;
	func();
	cout << a;

	return 0;
}
*/

//3. 매개 변수가 있는 경우
/*
void func(int n) {
	for (int i = 0; i <= n; i++) {
		cout << i << " ";
	}
	cout << "\n";
}
int main() {
	func(7);
}
*/

#include <iostream>
using namespace std;

void bbq(int n) {

	if (n < 1) {
		cout << n << " ";
		return;
	}
	else {
		cout << n << " ";
		bbq(n - 1);
		cout << n << " ";
	}
}
int main()
{
	int n;
	cin >> n;

	bbq(n);

}