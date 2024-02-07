#include <string>
#include <cstring>
using namespace std;

int main() {
	char str[100] = "AAA";

	//C언어 기반이다? 메모리 위주로 접근
	//memset(시작 주소, 원하는 값, 원하는 길이)

	memset(str, 0, strlen(str));
	// 이건 '\0'이 들어감

	memset(str, '0', 20);
	// char 배열은 마음대로 초기화 가능
	// char : 1바이트
	// int : 4바이트
	// memset은 내부적으로 unsigned char형태로 데이터를 다룬다.
	memset(str, 'a', 20);

	// int  배열 사용해보기
	int arr[100];


	memset(arr, 1, 100);
// 이렇게 하면 memset은 바이트 단위로 초기하 하기 때문에 000001 000001  이런식으로 초기화 됨. 

	// 음수는 이진수에서 어떻게 표현할까?
	// 2의 보수
	/* 전체 숫자 반전 후  + 1
	* EX)  숫자 3 : 00000011
	*		반전: 11111100
	*		+1 : 11111101
	* 
	* => 확인 하기 : 숫자 3과 보수를 더해보면 000000 즉 , 0이 나옴. 
	* 
	* 
	* memset정리 -> 
	* char 배열에서는 자유롭게 원하는 값을 사용
	* int 배열에서는 0, -1 로만 초기화 가능(바이트 단위이기 때문)
	*/



	//cstring과 string
	/*
	* cstring : char 배열
	* string : string class를 사용
	* 
	* 코테에서 IDE를 못씀
	* -string 메서드를 외우셔야 합니다. 
	*/
	return 0;
}