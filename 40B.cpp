#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, b;
    cin >> n >> b;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int maxSum = 0;
    for (int i = 0; i < n; i++){
        int numberDollar = floor(b * 1.0 / a[i]);
        for (int j = i + 1; j < n; j++){
            if (a[i] < a[j]){
                int profit = numberDollar * (a[j] - a[i]);
                maxSum = max(profit, maxSum);
            }
        }
    }

    cout << maxSum + b;

    return 0;
}