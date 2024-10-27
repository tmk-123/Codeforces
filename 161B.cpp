#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    
    // a[i] là hình vuông lớn hớn
    // xét các hình vuông a[j] nhỏ hơn
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= i; j++) {
            ll x = a[j]; // nằm ở hình vuông a[j]
            ll y = a[i] - a[j]; // ở giữa hình vuông a[i] và a[j]

            int count = 0;
            for (int l = 0; l < n; l++) {
                if (x <= a[l] && y <= a[l]) {
                    count++;
                }
            }

            if (count == k) {
                cout << x << " " << y << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
