#include<bits/stdc++.h>
 
using namespace std;
 
// tính d bằng hiệu tổng vị trí lẻ trừ chẵn

int main(){
    int n, d, l;
    cin >> n >> d >> l;
    
    vector<int> a(n + 1, 1);

    // số thẻ ở vị trí chẵn, lẻ
    int sum_even = n / 2;
    int sum_odd = n - sum_even;

    // chọn vị trí bắt đầu điều chỉnh
    int start;

    // d > 0 nghĩa là lẻ > chẵn
    if (d > 0) start = 1;
    else if (d < 0) start = 2;
    // khi d = 0 nếu n lẻ thì xét start từ vị trí chẵn cuối cùng để không phải lặp tiếp
    // nếu n chẵn thì vector(n, 1) là đủ không cần xét
    else if (d == 0 && n % 2 == 1) start = n - 1;
    
    for (int i = start; i <= n; i += 2){
        if (sum_odd - sum_even == d) break;

        while (a[i] < l && sum_odd - sum_even != d){
            a[i]++;
            if (i % 2 == 1) sum_odd++;
            else sum_even++;
        }
    }

    if (sum_odd - sum_even != d) cout << -1;
    else {
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
    }
}