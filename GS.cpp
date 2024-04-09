#include<iostream>
using namespace std;

int n;
bool flag = 1;

struct man {
	int rate[30] = { 0 };
	int rate_index[30] = { 0 };
	int if_proposed[30] = { 0 };
	int dating = 0; // dating 为 0 表示自由，否则dating的数值就是第几号候选人
	int wife = 0;
}m[30];

struct woman {
	int rate[30] = { 0 };
	int rate_index[30] = { 0 };
	int dating = 0;
	int husband = 0;
}w[30];

int S[30][30];
	
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> m[i].rate[j];
			m[i].rate_index[m[i].rate[j]] = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w[i].rate[j];
			w[i].rate_index[w[i].rate[j]] = j;

		}
	}
	int i = 1;
	while (flag) { // While 存在男人是自由的且还没对每个女人都求过婚， 选择这样的一个男人 m
		flag = 0;

		if (m[i].dating == 0) {
			for (int j = 1; j <= n; j++) { // 令 w 是 m 的优先表中 m 还没求过婚的最高排名的女人
				int k = m[i].rate[j]; // k 是当前的 w 的标号
				if (w[k].dating == 0 && m[i].if_proposed[k] == 0) { // w 是自由的
					m[i].dating = k; // (m, w) 变成约会状态
					w[k].dating = i;
					S[i][k] = 1;
					m[i].if_proposed[k] = 1;
					//printf("S[%d][%d]: %d\n", i, k, S[i][k]);
					break;


				}
				else { // w 当前与 m' 约会
					if (w[k].rate_index[w[k].dating] < w[k].rate_index[i]) { // w 更偏爱m'
						m[i].dating = 0; // m 保持自由
					}
					else { // w 更偏爱m
						m[w[k].dating].dating = 0; // m' 变成自由
						S[w[k].dating][k] = 0; 

						m[i].dating = k; // (m, w) 变成约会状态
						w[k].dating = i;
						S[i][k] = 1;
						//printf("S[%d][%d]: %d\n", i, k, S[i][k]);
						break;
					}
				}
			}
		}
		for (int t = 1; t <= n; t++)
			if (m[t].dating == 0)
				flag = 1;

		i++;
		//cout << i << endl;
		if (i > n) i = 1;
	}
	
	/*for (int i = 1; i <= n; i++, cout<<endl)
		for (int j = 1; j <= n; j++)
			cout << S[i][j] << ' ';*/
		
	for (int i = 1; i <= n; i++)
		cout << m[i].dating <<' ';

	/*for (int i = 1; i <= n; i++)
		cout << w[i].dating << endl;*/
	return 0;
}