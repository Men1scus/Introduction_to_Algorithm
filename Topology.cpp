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

// ��ӡͼ���ڽӾ���
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// ����DAGͼ�Ŀ���Ϊ���Ľڵ�������꣬���û����㣬˵���л�������0
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

// ��DAGͼ�������������������DAG��ֱ��break��cnt����0�����NO
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
	// �ҵ�������ʼ�ڵ�λ��
	int  i = path.size() - 1;
	while (path[i] != start)
		i--;

	// �����
	for (; i < path.size(); i++) {
		cout << path[i] << ",";
	}
	cout << cur << endl;
}

void DFS(int cur) {
	if (visited[cur]) {
		printCycle(cur, cur);
		exit(0); //��ӡ���ֱ�ӽ������򣬲�������������
	}
	visited[cur] = true;
	path.push_back(cur); // ����ǰ�ڵ����·��

	for (int next = 1; next <= n; next++) {
		if (a[cur][next]) { // ����ÿһ���ڽӵĽڵ�
			DFS(next);
		}
	}

	path.pop_back(); // ��·�����Ƴ���ǰ�ڵ�
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