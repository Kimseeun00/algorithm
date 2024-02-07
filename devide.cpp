#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


// ���� ����(Devide and Conquer)
//   - �˰����� ���� ����� �� �ϳ�
//   - ū ������ ���� ������ ����� �ذ��� ��, ����� ��ġ��
//   - ex) ���� ����, �� ����, ���� Ž��

// ���
// 1. ����(Divide)
//   - �����ϴٸ�, �� ���� ������ ����
// 2. ����(Conquer)
//   - �� ���� ������ �ذ�
// 3. ����(Combine)
//   - ���� �������� �ظ� �����ؼ� ���� ������ �ظ� ����

// C ^ N �� ���غ���.
// ����Լ�
// 10�� ���Ұ�
// -> 1�� * 9��
// -> 1�� * 1�� * 8��
int count1 = 0;
int recur(int C, int N) {
    if (N == 1) return C;

    count1++;
    return C * recur(C, N - 1);
}

// ȿ������ �������� ?
// ����� �����غ���!
// C ^ n
// n �� ¦�� : C ^ 2/n * C ^ 2/n
// n �� Ȧ�� : C ^ 2/(n-1) * C ^ 2/(n-1) * C
// n �� 1 : return C
int count2 = 0;
int recur2(int C, int N) {
    // ����
    if (N == 0) return 1;
    if (N == 1) return C;

    count2++;
    // ����
    if (N % 2 == 0) {
        int half = recur2(C, N / 2);
        // ����
        return half * half;
    }
    else {
        int half = recur2(C, (N - 1) / 2);
        // ����
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