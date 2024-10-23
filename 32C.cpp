#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ll n, m , s;
    cin >> n >> m >> s;
    
    // tính theo khoảng cách bước nhảy nên trừ 1
    n--;
    m--;

    // n % s là số ô còn lại ví dụ 5 % 3 thì sẽ còn 2 ô còn lại nhảy y hệt như cách 
    // ban đầu nên ta nhân thêm
    ll row = (n / s + 1) * (n % s + 1);
    ll col = (m / s + 1) * (m % s + 1);

    cout << row * col;
}