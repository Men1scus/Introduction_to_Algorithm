#include<iostream>
#include<vector>
using namespace std;

int n; // vertices
int m; // directed edges
int x, y; // edge from vertex x to vertex y
int a[55][55];
int t[55];
int cnt;
int has_been[55];

// 打印图的邻接矩阵
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// 返回DAG图的可作为起点的节点的列坐标，如果没有起点，说明有环，返回0
int DAG() {
	for (int j = 1; j <= n; j++) {
		if (has_been[j]) {
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (a[i][j] == 1)
				break;
			else if (i == n && a[i][j] == 0) {
				has_been[j] = 1;
				return j;
			}
		}
	}
	return 0;
}

// 对DAG图进行拓扑排序，如果不是DAG，直接break，cnt就是0，输出NO
void Topology() {
	while (true) {
		int ver = DAG();
		if (!ver) 
			break;
		t[++cnt] = ver;
		for (int j = 1; j <= n; j++) 
			a[ver][j] = 0;
		//print();
	}
}
bool visited[55];
vector<int> path;

void printCycle(int start, int cur) {
	// 找到环的起始节点位置
	int  i = path.size() - 1;
	while (path[i] != start)
		i--;

	// 输出环
	for (; i < path.size(); i++) {
		cout << path[i] << ",";
	}
	cout << cur << endl;
}

void DFS(int cur) {
	if (visited[cur]) {
		printCycle(cur, cur);
		exit(0); //打印完就直接结束程序，不考虑其他函数
	}
	visited[cur] = true;
	path.push_back(cur); // 将当前节点加入路径

	for (int next = 1; next <= n; next++) {
		if (a[cur][next]) { // 对于每一个邻接的节点
			DFS(next);
		}
	}

	path.pop_back(); // 从路径中移除当前节点
}

void Cycle() {
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			DFS(i);
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}

	//print();

	Topology();

	if (cnt == n) {
		cout << "YES" << endl;
		for (int i = 1; i <= n; i++) {
			cout << t[i] << (i < n ? "," : "");
		}
	}
	else {
		cout << "NO" << endl;
		Cycle();
	}

	return 0;
}