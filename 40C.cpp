#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    //vì nhỏ nhất theo thứ tự từ điển nên @ nhỏ hơn chữ cái vậy tìm vị trí @ gần nhất
    int at_pos = s.find("at", 1);
    s.replace(at_pos, 2, "@");

    int dot_pos = 0;

    // giá trị hàm find được gán cho dot_pos sau đó so sánh dot_pos với npos
    // find("dot", dot_pos) là tìm vị trí dot gần nhất kể từ dot_pos
    while ((dot_pos = s.find("dot", dot_pos)) != string::npos){
        if (dot_pos != 0 && dot_pos != s.length() - 3){
            s.replace(dot_pos, 3, ".");
        }
        dot_pos += 1;
    }

    cout << s;
}
