#include<iostream>
using namespace std;

int n;
bool flag = 1;

struct man {
	int rate[30] = { 0 };
	int rate_index[30] = { 0 };
	int if_proposed[30] = { 0 };
	int dating = 0; // dating Ϊ 0 ��ʾ���ɣ�����dating����ֵ���ǵڼ��ź�ѡ��
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
	while (flag) { // While �������������ɵ��һ�û��ÿ��Ů�˶�����飬 ѡ��������һ������ m
		flag = 0;

		if (m[i].dating == 0) {
			for (int j = 1; j <= n; j++) { // �� w �� m �����ȱ��� m ��û���������������Ů��
				int k = m[i].rate[j]; // k �ǵ�ǰ�� w �ı��
				if (w[k].dating == 0 && m[i].if_proposed[k] == 0) { // w �����ɵ�
					m[i].dating = k; // (m, w) ���Լ��״̬
					w[k].dating = i;
					S[i][k] = 1;
					m[i].if_proposed[k] = 1;
					//printf("S[%d][%d]: %d\n", i, k, S[i][k]);
					break;


				}
				else { // w ��ǰ�� m' Լ��
					if (w[k].rate_index[w[k].dating] < w[k].rate_index[i]) { // w ��ƫ��m'
						m[i].dating = 0; // m ��������
					}
					else { // w ��ƫ��m
						m[w[k].dating].dating = 0; // m' �������
						S[w[k].dating][k] = 0; 

						m[i].dating = k; // (m, w) ���Լ��״̬
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