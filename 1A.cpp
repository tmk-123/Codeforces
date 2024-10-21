#include<bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long n, m, a;
    cin >> n >> m >> a;
    unsigned long long value = ceil((double) n / a) * ceil((double) m * 1.0 / a);
    cout << value;
}