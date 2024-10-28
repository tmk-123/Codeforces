#include <iostream>
using namespace std;

int main() {
    int side, x, y;
    cin >> side >> x >> y;
    
    int n = side / 2;

    // những hình vuông giao với giữa thì không chia được thành 2 phần đối xứng 
    if ((x == n && y == n) || (y == n + 1 && x == n + 1) || (x == n + 1 && y == n) || (x == n && y == n + 1))
        cout << "NO";
    else cout << "YES";

    return 0;
}
