#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int y, x, weight;
};

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

// queue: ���� �տ� �����͸� ���� ���� �̾Ƴ��ڴ�.
// priority queue : ���� �켱������ ���� �����͸� ���� ���� �̾Ƴ��ڴ�.
int main() {
    // ���� �⺻���� ����
    // priority_queue<int> pq;

    // Ǯ��� �Ʒ��� ����
    priority_queue<int, vector<int>, less<>> pq;

    // pq ������ operator ���� true �� ��ȯ�� �� swap �� �߻��Ѵ�.
    // less ���꿡����, �������� ������ true �� return
    // -> ū ���� �ڲ� ������ ��
    // -> less �� ������ : ������������ ���ĵȴ�.
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

    // pq�� ���� ���淡 ���� ?
    // - �켱������ ���� ������ �̱� -> ��� �����ϸ� ��
    //    -> but, ������ ��� ������ �߰��ϸ� �� �������־�� �� (��ȿ����)
    // - �����Ͱ� �߰� or ���� �� ������ ���ĵ� �����Ͱ� �ʿ��� ��

    // pq �� ���������� heap ���� �����������
    // ���̶� ?
    // 1. ���� ���� Ʈ��
    // 2. �� �Ӽ��� ������
    //   -> (max heap�� ��������) �θ� �ڽĺ��� ������ ũ��.
    // �ð� ���⵵
    //   - ���԰� ���� ������ ��� O(logN) ���� �̷������.
    //   -> ª�� �ð��ȿ� ����

    // ����
    // ���� �� ������� �� ��ƴ�.
    // �ڽ� index ����� �ؾ���.
    // ���� - ������ index : n
    //   - ���� : n * 2 + 1
    //   - ������ : n * 2 + 2

    return 0;
}
//pq�� ���� ���� ���ö����� �ٽ� ���Ľ�Ű�� ���� ��� ���� ��


/*
���� ����
1. ���� ���ʿ� ����
2. �� �ڸ��� ã�� �� ���� �θ�� ��  + swap ���� ����(�θ� ������ Ŀ�� ��)


 ���Կ����� �ð�
 =-(Ʈ���� ���� - 1) ��ŭ �߻�

 �����Ͱ� n�� �� ��, Ʈ���� ���̴�?
     == >  -nlogN��

     �������� �� N: (2^k + 1) - 1

     ��������? ����

     ���� Ʈ���� ���̴� nlogn + 1]



���԰� ���� ��� logn���� �̷������.
pop()��  �ʹ� ����.....
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;


struct Node {
    int y, x, weight;
};

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

// queue: ���� �տ� �����͸� ���� ���� �̾Ƴ��ڴ�.
// priority queue : ���� �켱������ ���� �����͸� ���� ���� �̾Ƴ��ڴ�.
int main() {
    // ���� �⺻���� ����
    // priority_queue<int> pq;

    // Ǯ��� �Ʒ��� ����
    priority_queue<int, vector<int>, less<>> pq;

    // pq ������ operator ���� true �� ��ȯ�� �� swap �� �߻��Ѵ�.
    // less ���꿡����, �������� ������ true �� return
    // -> ū ���� �ڲ� ������ ��
    // -> less �� ������ : ������������ ���ĵȴ�.
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

    // pq�� ���� ���淡 ���� ?
    // - �켱������ ���� ������ �̱� -> ��� �����ϸ� ��
    //    -> but, ������ ��� ������ �߰��ϸ� �� �������־�� �� (��ȿ����)
    // - �����Ͱ� �߰� or ���� �� ������ ���ĵ� �����Ͱ� �ʿ��� ��

    // pq �� ���������� heap ���� �����������
    // ���̶� ?
    // 1. ���� ���� Ʈ��
    // 2. �� �Ӽ��� ������
    //   -> (max heap�� ��������) �θ� �ڽĺ��� ������ ũ��.
    // �ð� ���⵵
    //   - ���԰� ���� ������ ��� O(logN) ���� �̷������.
    //   -> ª�� �ð��ȿ� ����

    // ����
    // ���� �� ������� �� ��ƴ�.
    // �ڽ� index ����� �ؾ���.
    // ���� - ������ index : n
    //   - ���� : n * 2 + 1
    //   - ������ : n * 2 + 2

    return 0;
}

*/

