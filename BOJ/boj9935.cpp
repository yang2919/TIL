#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <stack>
#include <cstring>
#include <utility>

using namespace std;

stack<pair<char, int>> st;
char temp[1000005];
char tar[50];

int main()
{
	scanf("%s", temp);
	scanf("%s", tar);

	int len = strlen(temp);
	int t_len = strlen(tar);
	int k = -1;

	for (int i = 0; i < len; i++)
	{
		if (temp[i] == tar[0])
			k = 0;
		else if (temp[i] == tar[k + 1])
			k += 1;
		else 
			k = -1;

		st.push(make_pair(temp[i], k));

		if (k == t_len - 1) {
			for (int j = 0; j < t_len; j++)
				st.pop();
			if (st.empty()) k = -1;
			else k = st.top().second;
		}
	}

	if (st.size() == 0) printf("FRULA");
	else {
		tar[st.size()] = '\0';
		for (int i = st.size() - 1; i >= 0; i--) {
			tar[i] = st.top().first;
			st.pop();
		}
		printf("%s", tar);
	}

	return 0;
}