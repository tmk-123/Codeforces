#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt = 1, Max = 1;
    for (int i = 1; i < s.length(); i++){
        if (s[i] == s[i - 1]){
            cnt++;
            Max = max(cnt, Max);
        }
        else cnt = 1;
    }
    if (Max >= 7) cout << "YES";
    else cout << "NO";
}