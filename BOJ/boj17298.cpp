#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

int a[1000005], nge[1000005];
int N;
stack<int> st;

int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		while (!st.empty() && st.top() < a[i])
			st.pop();
		if (st.empty()) nge[i] = -1;
		else nge[i] = st.top();
		st.push(a[i]);
	}

	for (int i = 0; i < N; i++)
		printf("%d ", nge[i]);
	return 0;
}