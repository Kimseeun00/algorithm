#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


// 분할 정복(Devide and Conquer)
//   - 알고리즘 설계 방법론 중 하나
//   - 큰 문제를 작은 문제로 나누어서 해결한 후, 결과를 합치자
//   - ex) 병합 정렬, 퀵 정렬, 이진 탐색

// 방법
// 1. 분할(Divide)
//   - 가능하다면, 더 작은 문제로 분할
// 2. 정복(Conquer)
//   - 각 하위 문제를 해결
// 3. 결합(Combine)
//   - 하위 문제들의 해를 결합해서 원래 문제의 해를 얻음

// C ^ N 을 구해보자.
// 재귀함수
// 10번 곱할것
// -> 1번 * 9번
// -> 1번 * 1번 * 8번
int count1 = 0;
int recur(int C, int N) {
    if (N == 1) return C;

    count1++;
    return C * recur(C, N - 1);
}

// 효율적인 분할정복 ?
// 방법을 생각해보자!
// C ^ n
// n 이 짝수 : C ^ 2/n * C ^ 2/n
// n 이 홀수 : C ^ 2/(n-1) * C ^ 2/(n-1) * C
// n 이 1 : return C
int count2 = 0;
int recur2(int C, int N) {
    // 정복
    if (N == 0) return 1;
    if (N == 1) return C;

    count2++;
    // 분할
    if (N % 2 == 0) {
        int half = recur2(C, N / 2);
        // 결합
        return half * half;
    }
    else {
        int half = recur2(C, (N - 1) / 2);
        // 결합
        return half * half * C;
    }
}

int main() {
    int r1 = recur(2, 10);
    cout << r1 << " / count : " << count1 << "\n";

    int r2 = recur2(2, 10);
    cout << r2 << " / count : " << count2 << "\n";

    return 0;
}
