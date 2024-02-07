/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
int mat[4][4];
int N, M; // N개의 노트 와 M개의 간선 정보
//vector : vector 맨 뒤에 메모리를 추가해가면서 value를 저장하는 자료 구조
//vector<데이터 자료형> 이름;
vector<int>v;


int main() {
	//데이터를 맨 뒤에 추가 .push_back(value);
	// 데이터를 맨뒤에서부터 하나 삭제 .pop_back();
	v.push_back(1);
	v.pop_back();
}
*/
#include <iostream>
#include <vector>
using namespace std;
/*
vector<int> alist[5];
int value[5] = { 1, 5, 4, 9, 2 };
void run(int now) {
    cout << value[now];

    for (int num : alist[now]) {
        run(num);
    }
}
int main() {
    alist[0] = { 1, 2, 3 };
    alist[2] = { 4 };

    int n;
    cin >> n;

    //for
    for (int i = 0; i < alist[n].size(); i++) {
        int tar = alist[n][i];
        cout << value[tar];
    }

    //ranged for
    for (int num : alist[n]) {
        cout << value[num];
    }

    return 0;
}
*/
// 모든 노드를 한번씩만 탐색
#include <iostream>
#include <vector>
using namespace std;

vector<int> alist[4];
int used[4];

void run(int now) {

    cout << now << " ";

    for (int num : alist[now]) {

        //여권검사
        if (used[num] == 1) continue;
        used[num] = 1;
        run(num); // 이 나라로 갈건데
    }

}

int main() {
    alist[0] = { 1, 2, 3 };
    alist[1] = { 2, 3 };
    alist[2] = { 3, 0 };

    used[0] = 1;
    run(0);
}

// 모든 경로를 다 탐색
#include <iostream>
#include <vector>
using namespace std;

vector<int> alist[4];
int used[4];
int cnt = 0;

void run(int now) {

    //cout << now << " ";

    if (now == 3) {
        cnt++;
        return;
    }

    for (int num : alist[now]) {

        //여권검사
        if (used[num] == 1) continue;
        used[num] = 1;
        run(num); // 이 나라로 갈건데
        used[num] = 0; //한줄 추가하면, 모든 경로를 탐색
    }

}

int main() {
    alist[0] = { 1, 2, 3 };
    alist[1] = { 2, 3 };
    alist[2] = { 3, 0 };

    used[0] = 1;
    run(0);

    cout << cnt;
}