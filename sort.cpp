#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int y, x, weight;
};

// Node 객체 덧셈(+) 연산자 오버로딩
// 1. 가장 기본적인 형태의 연산자 오버로딩
// -> 매개변수를 받을 때 복사가 발생한다! 비효율적임.
//int operator+(Node left, Node right) {
//    return left.weight + right.weight;
//}

// 2. 복사하지 않도록 참조로 바꾸자
//  -> 원본 데이터가 바뀔 수가 있네 ?
//int operator+(Node &left, Node &right) {
//    return left.weight + right.weight;
//}

// 3. 혹시나 함수에서 원본 값을 바꾸면 ?
// -> 바꾸지 않도록 const 를 추가
/*int operator+(const Node& left, const Node& right) {
    return left.weight + right.weight;
}

// 왼쪽의 weight 가 작으면 true 를 반환하도록 < 연산자 오버로딩
/*bool operator<(const Node& left, const Node& right) {
    if (left.weight < right.weight) return true;
    return false;
}
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int y, x, weight;

    // 우선순위가 제일 높음
    bool operator<(const Node& right) {
        // weight 비교
        if (weight < right.weight) return true;
        else if (weight > right.weight) return false;

        // weight 가 같다면 y 비교
        if (y < right.y) return true;
        else if (y > right.y) return false;

        // y 까지 같다면 x 비교
        if (x < right.x) return true;
        else if (x > right.x) return false;

        // 모두 같다면
        return false;
    }
};

// Node 객체 덧셈(+) 연산자 오버로딩
// 1. 가장 기본적인 형태의 연산자 오버로딩
// -> 매개변수를 받을 때 복사가 발생한다! 비효율적임.
//int operator+(Node left, Node right) {
//    return left.weight + right.weight;
//}

// 2. 복사하지 않도록 참조로 바꾸자
//  -> 원본 데이터가 바뀔 수가 있네 ?
//int operator+(Node &left, Node &right) {
//    return left.weight + right.weight;
//}

// 3. 혹시나 함수에서 원본 값을 바꾸면 ?
// -> 바꾸지 않도록 const 를 추가
int operator+(const Node& left, const Node& right) {
    return left.weight + right.weight;
}

// 왼쪽의 weight 가 작으면 true 를 반환하도록 < 연산자 오버로딩
//bool operator<(const Node& left, const Node& right) {
//    if (left.weight < right.weight) return true;
//    return false;
//}

bool operator<(const Node& left, const Node& right) {
    // weight 비교
    if (left.weight < right.weight) return true;
    else if (left.weight > right.weight) return false;

    // weight 가 같다면 y 비교
    if (left.y < right.y) return true;
    else if (left.y > right.y) return false;

    // y 까지 같다면 x 비교
    if (left.x < right.x) return true;
    else if (left.x > right.x) return false;

    // 모두 같다면
    return false;
}

int main() {
    Node arr[10];

    // ex) weight 값을 더한 결과를 출력
    //cout << "arr[0] + arr[1] : " << arr[0] + arr[1] << "\n"; // 9

    //cout << "arr[0] < arr[1] : " << (arr[0] < arr[1]) << "\n";

    // [참고] 기본 연산자는 오버로딩 하지 말자!
    // ex) 덧셈 연산자를 바꾸지 말자.
    /*int a = 10;
    int b = 20;
    cout << a + b << "\n";*/

    // 아래 기준을 우선순위 순서대로 정렬해보세요.
    // 1. weight 가 작을수록 앞으로
    // 2. y 가 작을수록 앞으로
    // 3. x 가 작을수록 앞으로

    arr[0] = { 1, 2, 6 };
    arr[1] = { 4, 5, 3 };
    arr[2] = { 3, 4, 3 };
    arr[3] = { 1, 4, 3 };
    arr[4] = { 2, 3, 10 };
    arr[5] = { 0, 3, 10 };
    arr[6] = { 4, 3, 3 };

    // 주의 : 쓰레기값도 함께 정렬됨
    // sort(arr, arr + 10);
    sort(arr, arr + 7);

    return 0;
}