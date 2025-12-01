#include <stdio.h>

int main(){
	int a=50, ans=0;
	char s[20];

	while (fgets(s, sizeof s, stdin)){
		int x;
		char c;
		sscanf(s, " %c%d", &c, &x);
		if (c=='L') a-=x;
		else a+=x;
		a=(a+100)%100;
		if (a==0) ans++;
	}

	printf("%d",ans);
}
