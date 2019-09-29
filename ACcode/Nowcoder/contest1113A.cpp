#include <bits/stdc++.h>
using namespace std;
int check(int x) {
    int sum = 0;
    for (int i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) sum += i, sum += x / i;
        if (x % i == 0 && x / i == i) sum -= i;
    }
    return sum - x;
}
int main() {
    int s;
    cin >> s;
    for (int i = s; s <= 50; ++i) {
        int t = check(i);
        cout << i << " " << t << endl;
        if (check(t) == i && t != i) {
            cout << i << " " << t << endl;
            break;
        }
    }
    return 0;
}
