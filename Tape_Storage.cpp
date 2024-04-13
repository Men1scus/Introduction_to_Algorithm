#include<iostream>
using namespace std;

int n; // 文件个数
int L; // 磁带长度
int a[1005];
int cnt;

int main() {
	cin >> n >> L;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	// Bubble Sort
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	for(int i = 0;i< n; i++) {
		if (a[i] > L) break;
		L -= a[i];
		cnt++;
	}
	cout << cnt << endl;

	return 0;
}