#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int cnt = 0;
int sum = 0;
int visited[10] = { 0 };
int arr[5];
string path;
void dfs(int node) {
	
	if (sum >= 10 && sum <= 20) {
		cnt++;
		//cout << "세은이바보\n";
		cout << path << "\n";	
	}
	if (node == 5) {
		
		
		return;

	}
	

	for (int i = node; i <5; i++) {
			
		if (visited[i] != 1) {
			path += arr[i] + '0';
			visited[i] = 1;
			sum += arr[i];
			dfs(i + 1);
			visited[i] = 0;
			sum -= arr[i];
			path.pop_back();
		}
		
	}
}
int main() {

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	
		
	dfs(0);
	cout << cnt << "\n";
	
	
	
}