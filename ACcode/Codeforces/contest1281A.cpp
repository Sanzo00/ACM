#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
 
char s[1005];
int main() {
	
	int t;
	cin >> t;
	char *s1 = "po";
	char *s2 = "desu";
	char *s3 = "masu";
	char *s4 = "mnida";
	
 	while (t--) {
		memset(s, 0, sizeof(s));
		cin >> s;
		int len = strlen(s);
		if (strcmp(s+len-2, s1) == 0) cout << "FILIPINO\n";
		else if(strcmp(s+len-4, s2) == 0 || strcmp(s+len-4, s3) == 0) cout << "JAPANESE\n";
		else cout << "KOREAN\n";
	}
	
	return 0;
}