#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, s;
    cin >> n >> m >> s;
    
    // Số hàng bọ chét có thể đến được từ một vị trí bất kỳ
    long long rows = (n - 1) / s + 1;  // Số lượng hàng bọ chét có thể đến
    long long cols = (m - 1) / s + 1;  // Số lượng cột bọ chét có thể đến
    
    // Số lượng vị trí ban đầu (x, y) mà có thể nhảy tới nhiều ô nhất
    cout << rows * cols << endl;
    
    return 0;
}
