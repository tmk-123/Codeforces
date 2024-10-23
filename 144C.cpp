#include<bits/stdc++.h>

#define ll long long

using namespace std;

// tìm số lần xuất hiện tối đa bằng cửa sổ trượt

pair<ll, ll> max_occurrences(ll n, ll k, vector<int> &a){
    sort(a.begin(), a.end());
    ll max_count = 0; // số phần tử liên tiếp bằng nhau lớn nhất(sau khi sắp xếp thì xét liên tiếp)
    int best_number = 0; // giá trị nhỏ nhất đạt max_count
    int left = 0;
    ll operations = 0; // tổng số thay đổi được sử dụng

    for (int right = 0; right < n; right++){
        if (right > 0){
            // số phép tăng = (giá trị mới - giá trị cũ) * số phần tử cần tăng
            ll new_operations = (ll)(a[right] - a[right - 1]) * (right - left);
            operations += new_operations;
        }

        // nếu phép tăng vượt quá k thì tăng left sang cửa số mới
        while (operations > k){
            // trừ đi số phép tăng để a[left] biến thành a[right]
            operations = operations - (a[right] - a[left]);
            left++;
        }

        int current_count = right - left + 1;

        if (current_count > max_count || (current_count == max_count && a[right] < best_number)){
            max_count = current_count;
            best_number = a[right];
        }
    }
    
    return {max_count, best_number};
}
int main(){
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    auto res = max_occurrences(n, k, a);
    cout << res.first << " " << res.second;
}