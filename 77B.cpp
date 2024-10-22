#include<bits/stdc++.h>

#define ll long long

using namespace std;

vector<string> v;

void Try(string s, int cnt4, int cnt7, int n){
    if (s.length() == n){
        if (cnt4 == cnt7){
            v.push_back(s);
        }
        return;
    }

    Try(s + '4', cnt4 + 1, cnt7, n);
    Try(s + '7', cnt4, cnt7 + 1, n);
}
int main(){
    string s;
    cin >> s;
    int n = s.length();
    int ok = 0;
    
    if (n % 2 == 0){
        Try("", 0, 0, n);
        sort(v.begin(), v.end());
        
        for (int i = 0; i < v.size(); i++){
            if (v[i] >= s){
                cout << v[i];
                ok = 1;
                break;
            }
        }

        // nếu không tìm được số nào với n chữ số to hơn thì phải tăng lên n + 2 chữ số
        if (!ok){
            for (int i = 0; i <= n / 2; i++){
                cout << 4;
            }
            for (int i = 0; i <= n / 2; i++){
                cout << 7;
            }
        }
    }
    else if (n % 2 == 1){
        for (int i = 0; i <= n / 2; i++){
            cout << 4;
        }
        for (int i = 0; i <= n / 2; i++){
            cout << 7;
        }
    }
}