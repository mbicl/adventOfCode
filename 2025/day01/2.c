#include <stdio.h>

int main(){
	int a=50, ans=0;
	char s[20];

	while (fgets(s, sizeof s, stdin)) {
		int x;
		char c;
		sscanf(s, " %c%d", &c, &x);

		if (c=='L') {
			while (x--) {
				a--;
				if (a==-1) a=99;
				if (a==0) ans++;
			}
		} else {
			while (x--) {
				a++;
				if (a==100) {
					a=0;
					ans++;
				}
			}
		}
	}

	printf("%d", ans);
}
