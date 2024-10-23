#include<bits/stdc++.h>

using namespace std;

int main (){
    int n, d;
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int cnt = 0;
    sort(a, a + n);

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (abs(a[i] - a[j]) <= d){
                cnt++;
            }
            else break;
        }
    }

    cout << cnt * 2;
}