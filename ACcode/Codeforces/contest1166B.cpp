#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main() {
    
    int n;
    cin >> n;
    int flag = -1;
    for (int i = 5; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        cout << "-1\n";
    }else {
        int l = flag;
        int r = n / flag;
        vector <char> a{'a', 'e', 'i', 'o', 'u'};    
        for (int i = 0; i < l; ++i) {
            int now = i;
            for (int j = 0; j < r; ++j) {
                cout << a[(now++)%5];
            }
        }
        cout << endl;
    }
    
    return 0;
}