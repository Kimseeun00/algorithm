#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int N,M;
char arr[100][100];
int move_i, move_j;
int f_index(char a,int j) {
	int k;
	for (k = 0; k % 2 == 0; k++) {
		if (k == j) {
			continue;
		}
		else {
			for (int p = 0; p < N; p++) {
				if (arr[p][k] == a) {
					move_i = p;
					move_j = k;
					return k;
				}
			}
		}
	}
	return k;
}
int play(int j) {
	int i;
	for (i = 0; i < N; i++) {
		if (arr[i][j] == ' | ') {
			continue;
		}
		else {
			f_index(arr[i][j],j);
			i = move_i;
			j = move_j;
		}
	}
}
int main() {
	int array[100] = { 0 };
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2*M - 1; j++) {
			cin >> arr[i][j];
		}
	}

	for (int j = 0; j < 2 * M - 1; j++) {
		if (j % 2 == 0) {
			array[play(j)] = j + 1;
		}
	}

	for (int p = 0; p < 100; p++) {
		if (array[p] >= 0)
			cout << array[p] << " ";
	}
}