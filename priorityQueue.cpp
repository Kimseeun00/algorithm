#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int y, x, weight;
};

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

// queue: 제일 앞에 데이터를 가장 먼저 뽑아내겠다.
// priority queue : 제일 우선순위가 높은 데이터를 가장 먼저 뽑아내겠다.
int main() {
    // 가장 기본적인 형태
    // priority_queue<int> pq;

    // 풀어쓰면 아래와 같음
    priority_queue<int, vector<int>, less<>> pq;

    // pq 에서는 operator 에서 true 를 반환할 때 swap 이 발생한다.
    // less 연산에서는, 기존값이 작으면 true 를 return
    // -> 큰 값이 자꾸 앞으로 옴
    // -> less 비교 연산자 : 내림차순으로 정렬된다.
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(6);
    pq.push(10);
    pq.push(-3);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop(); // pop_back
    }

    // pq는 뭐가 좋길래 쓸까 ?
    // - 우선순위에 따라 데이터 뽑기 -> 사실 정렬하면 됨
    //    -> but, 정렬의 경우 데이터 추가하면 또 정렬해주어야 함 (비효율적)
    // - 데이터가 추가 or 변경 될 때마다 정렬된 데이터가 필요할 때

    // pq 는 내부적으로 heap 으로 만들어져있음
    // 힙이란 ?
    // 1. 완전 이진 트리
    // 2. 힙 속성을 만족함
    //   -> (max heap을 기준으로) 부모가 자식보다 무조건 크다.
    // 시간 복잡도
    //   - 삽입과 삭제 연산이 모두 O(logN) 만에 이루어진다.
    //   -> 짧은 시간안에 가능

    // 단점
    // 코테 시 디버깅이 좀 어렵다.
    // 자식 index 계산을 해야함.
    // 계산법 - 본인의 index : n
    //   - 왼쪽 : n * 2 + 1
    //   - 오른쪽 : n * 2 + 2

    return 0;
}
//pq는 값이 새로 들어올때마다 다시 정렬시키고 싶을 경우 많이 씀


/*
삽입 연산
1. 가장 왼쪽에 삽입
2. 내 자리를 찾을 때 까지 부모와 비교  + swap 연산 수행(부모가 나보다 커야 함)


 삽입연산의 시간
 =-(트리의 높이 - 1) 만큼 발생

 데이터가 n개 일 때, 트리의 높이는?
     == >  -nlogN개

     데이터의 수 N: (2^k + 1) - 1

     증명과정? 몰랑

     따라서 트리의 높이는 nlogn + 1]



삽입과 삭제 모두 logn만에 이루어진다.
pop()을  너무 졸려.....
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int y, x, weight;
};

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

// queue: 제일 앞에 데이터를 가장 먼저 뽑아내겠다.
// priority queue : 제일 우선순위가 높은 데이터를 가장 먼저 뽑아내겠다.
int main() {
    // 가장 기본적인 형태
    // priority_queue<int> pq;

    // 풀어쓰면 아래와 같음
    priority_queue<int, vector<int>, less<>> pq;

    // pq 에서는 operator 에서 true 를 반환할 때 swap 이 발생한다.
    // less 연산에서는, 기존값이 작으면 true 를 return
    // -> 큰 값이 자꾸 앞으로 옴
    // -> less 비교 연산자 : 내림차순으로 정렬된다.
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(6);
    pq.push(10);
    pq.push(-3);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop(); // pop_back
    }

    // pq는 뭐가 좋길래 쓸까 ?
    // - 우선순위에 따라 데이터 뽑기 -> 사실 정렬하면 됨
    //    -> but, 정렬의 경우 데이터 추가하면 또 정렬해주어야 함 (비효율적)
    // - 데이터가 추가 or 변경 될 때마다 정렬된 데이터가 필요할 때

    // pq 는 내부적으로 heap 으로 만들어져있음
    // 힙이란 ?
    // 1. 완전 이진 트리
    // 2. 힙 속성을 만족함
    //   -> (max heap을 기준으로) 부모가 자식보다 무조건 크다.
    // 시간 복잡도
    //   - 삽입과 삭제 연산이 모두 O(logN) 만에 이루어진다.
    //   -> 짧은 시간안에 가능

    // 단점
    // 코테 시 디버깅이 좀 어렵다.
    // 자식 index 계산을 해야함.
    // 계산법 - 본인의 index : n
    //   - 왼쪽 : n * 2 + 1
    //   - 오른쪽 : n * 2 + 2

    return 0;
}

*/


