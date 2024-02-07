#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int y, x, weight;
};

// Node ��ü ����(+) ������ �����ε�
// 1. ���� �⺻���� ������ ������ �����ε�
// -> �Ű������� ���� �� ���簡 �߻��Ѵ�! ��ȿ������.
//int operator+(Node left, Node right) {
//    return left.weight + right.weight;
//}

// 2. �������� �ʵ��� ������ �ٲ���
//  -> ���� �����Ͱ� �ٲ� ���� �ֳ� ?
//int operator+(Node &left, Node &right) {
//    return left.weight + right.weight;
//}

// 3. Ȥ�ó� �Լ����� ���� ���� �ٲٸ� ?
// -> �ٲ��� �ʵ��� const �� �߰�
/*int operator+(const Node& left, const Node& right) {
    return left.weight + right.weight;
}

// ������ weight �� ������ true �� ��ȯ�ϵ��� < ������ �����ε�
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

    // �켱������ ���� ����
    bool operator<(const Node& right) {
        // weight ��
        if (weight < right.weight) return true;
        else if (weight > right.weight) return false;

        // weight �� ���ٸ� y ��
        if (y < right.y) return true;
        else if (y > right.y) return false;

        // y ���� ���ٸ� x ��
        if (x < right.x) return true;
        else if (x > right.x) return false;

        // ��� ���ٸ�
        return false;
    }
};

// Node ��ü ����(+) ������ �����ε�
// 1. ���� �⺻���� ������ ������ �����ε�
// -> �Ű������� ���� �� ���簡 �߻��Ѵ�! ��ȿ������.
//int operator+(Node left, Node right) {
//    return left.weight + right.weight;
//}

// 2. �������� �ʵ��� ������ �ٲ���
//  -> ���� �����Ͱ� �ٲ� ���� �ֳ� ?
//int operator+(Node &left, Node &right) {
//    return left.weight + right.weight;
//}

// 3. Ȥ�ó� �Լ����� ���� ���� �ٲٸ� ?
// -> �ٲ��� �ʵ��� const �� �߰�
int operator+(const Node& left, const Node& right) {
    return left.weight + right.weight;
}

// ������ weight �� ������ true �� ��ȯ�ϵ��� < ������ �����ε�
//bool operator<(const Node& left, const Node& right) {
//    if (left.weight < right.weight) return true;
//    return false;
//}

bool operator<(const Node& left, const Node& right) {
    // weight ��
    if (left.weight < right.weight) return true;
    else if (left.weight > right.weight) return false;

    // weight �� ���ٸ� y ��
    if (left.y < right.y) return true;
    else if (left.y > right.y) return false;

    // y ���� ���ٸ� x ��
    if (left.x < right.x) return true;
    else if (left.x > right.x) return false;

    // ��� ���ٸ�
    return false;
}

int main() {
    Node arr[10];

    // ex) weight ���� ���� ����� ���
    //cout << "arr[0] + arr[1] : " << arr[0] + arr[1] << "\n"; // 9

    //cout << "arr[0] < arr[1] : " << (arr[0] < arr[1]) << "\n";

    // [����] �⺻ �����ڴ� �����ε� ���� ����!
    // ex) ���� �����ڸ� �ٲ��� ����.
    /*int a = 10;
    int b = 20;
    cout << a + b << "\n";*/

    // �Ʒ� ������ �켱���� ������� �����غ�����.
    // 1. weight �� �������� ������
    // 2. y �� �������� ������
    // 3. x �� �������� ������

    arr[0] = { 1, 2, 6 };
    arr[1] = { 4, 5, 3 };
    arr[2] = { 3, 4, 3 };
    arr[3] = { 1, 4, 3 };
    arr[4] = { 2, 3, 10 };
    arr[5] = { 0, 3, 10 };
    arr[6] = { 4, 3, 3 };

    // ���� : �����Ⱚ�� �Բ� ���ĵ�
    // sort(arr, arr + 10);
    sort(arr, arr + 7);

    return 0;
}