#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 7;
string board1[MAX_N]; 
int board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = { 0 };
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

bool isValid(int r, int c) {
    return r >= 0 && r < MAX_N && c >= 0 && c < MAX_N;
}

void checkRule(int board[MAX_N][MAX_N], int visited[MAX_N][MAX_N]) {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            if (board[i][j] == 1 && visited[i][j] == 0) {  // 새우인 경우
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];


                    if (isValid(nr, nc) && board[nr][nc] == 1) {
                        visited[i][j] = 1;
                    }
                }
            }
            else if (board[i][j] == 2 && visited[i][j] == 0) {  // 오징어인 경우
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];


                    if (isValid(nr, nc) && board[nr][nc] == 2) {
                        visited[i][j] = 1;
                    }
                }
            }
        }
    }
}

bool canServe(int visited[MAX_N][MAX_N]) {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            if (board[i][j] != 0 && visited[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {


    // 입력 받기
    for (int i = 0; i < MAX_N; i++) {
     
         cin >> board1[i];
        
    }

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            board[i][j] = board1[i][j];
        }
    }

    // 규칙 확인
    checkRule(board, visited);


    if (canServe(visited)) {
        cout << "pass" << endl;
       
    }
    else {
        cout << "fail" << endl;
    }

    return 0;
}