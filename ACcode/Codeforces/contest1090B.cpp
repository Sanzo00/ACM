#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<string> old, now;
    map<string, vector<string>> mp;
    while (cin >> s) {
        if (s == "\\begin{thebibliography}{99}") break;
        if (s.substr(0, 6) == "\\cite{") {
            string t;
            int i = 6;
            int len = s.size();
            for (i = 6; s[i] != '}' && i < len; ++i) {
                t += s[i];
            }
            if (i >= len) continue;
            old.push_back(t);
        }
    }
    string last;
    while (cin >> s) {
        if (s == "\\end{thebibliography}") break;
        string t;
        if (s.substr(0, 9) == "\\bibitem{") {
            int i;
            int len = s.size();
            for (i = 9; s[i] != '}' && i < len; ++i) {
                t += s[i];
            }
            if (i >= len) continue;
            last = t;
            now.push_back(last);
            mp[last].push_back(s);
        }else {
            mp[last].push_back(s);
        }
     }
     if (old == now) {
        cout << "Correct\n";
     }else {
        cout << "Incorrect\n";
        cout << "\\begin{thebibliography}{99}\n";
        for (string it : old) {
        	int len = mp[it].size();
        	for (int i = 0; i < len; ++i) {
        		if (i) cout << " ";
        		cout << mp[it][i];
        	}
        	cout << "\n";
        }
        cout << "\\end{thebibliography}\n";
     }

    return 0;
}
