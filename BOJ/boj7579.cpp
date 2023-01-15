#include <stdio.h>
#include <algorithm>

using namespace std;

int v[105], c[105];
int d[105][10000];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 1 ; i <= N ; i++)
		scanf("%d", &v[i]);
	
	for(int i = 1 ; i <= N ; i++)
		scanf("%d", &c[i]);
		
	for(int i = 1 ; i <= N ; i++)
	{
		for(int j = 0 ; j <= 10000 ; j++){
			d[i][j] = d[i - 1][j];
			if(j - c[i] >= 0) d[i][j] = max(d[i - 1][j], d[i - 1][j - c[i]] + v[i]);
		}
	}
	/*
	for(int i = 0 ; i <= N ; i++){
		for(int j = 0 ; j <= 200 ; j++){
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i = 0 ; i <= 10000 ; i++)
	{
		if(d[N][i] >= M) { 
			printf("%d", i);
			break;
		}
	}
		
	return 0;
}