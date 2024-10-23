#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n][3];
    int count = 0;

    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int j = 0; j < 3; j++){
            cin >> a[i][j];
            if (a[i][j]){
                cnt++;
            }
        }
        if (cnt >= 2){
            count++;
        }
    }
    cout << count;
}