#include<bits/stdc++.h>

using namespace std;

int main (){
    string s;
    cin >> s;
    
    int i = 0;
    
    if (s.length() == 1){
        cout << 0;
        return 0;
    }

    while (i < s.length() - 1){
        if (s[i] == '-' && s[i + 1] == '.'){
            cout << 1;
            i += 2;
        }
        if (s[i] == '-' && s[i + 1] == '-'){
            cout << 2;
            i += 2;
        }
        if (s[i] == '.' ){
            cout << 0;
            i++;
        }
    }

    if (i == s.length() - 1) cout << 0; 

    return 0;
}