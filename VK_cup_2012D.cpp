#include<bits/stdc++.h>

using namespace std;

// n đỉnh cách đều 
int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long maxSum = INT_MIN;

    // k là số số đỉnh
    for (int k = 3; k <= n; k++){
        // chỉ xét những k mà n chia hết để tạo đa giác đều
        if (n % k != 0) continue;    

        int step = n / k; // khoảng cách giữa các bức tượng
        for (int start = 0; start < step; start++){
            long long sum = 0;
            for (int i = start; i < n; i += step){
                sum += a[i];
            }
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum;
}