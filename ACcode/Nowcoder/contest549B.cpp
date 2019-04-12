#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
using namespace std;
const int maxn = 100000;
int RL[maxn << 1];
int Manacher(string s) {
	string t;
	for (int i = 0; i < (int)s.size(); ++i) {
   		t += s[i];
   		t += '#';
   	}
   	s = "#" + t;
   	int MaxRight = 0, pos = 0, MaxLen = 0;
   	for (int i = 0; i < (int)s.size(); ++i) {
   		if (i < MaxRight)	RL[i] = min(RL[2 * pos - i], MaxRight - i + 1); // 好多这里写的是 MaxRight - i，个人感觉根据算法思想应该+1计算长度。
   		else 	RL[i] = 1;
   		int l = i - RL[i];
   		int r = i + RL[i];
   		while (l >= 0 && r < (int)s.size() && s[l] == s[r])	{
   			RL[i] += 1;
   			l = i - RL[i];
   			r = i + RL[i];
   		}
   		if (RL[i] + i - 1 > MaxRight) {
   			MaxRight = RL[i] + i - 1;
   			pos = i;
   		}
   		MaxLen = max(MaxLen, RL[i]);
   	}
   	return MaxLen - 1;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int len = s.size();
    s += s;
    int ans = Manacher(s);
    if (ans > len) {
    	if ((ans - len) & 1) ans -= ans - len + 1;
    	else ans = len;
    }
    cout << ans << endl;

    return 0;
}