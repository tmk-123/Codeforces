#include<bits/stdc++.h>

using namespace std;

string number_to_string(int n){
    string res;
    
    while (n > 0){
        n--;
        res += 'A' + n % 26;
        n /= 26;
    }

    reverse(res.begin(), res.end());
    return res;
}

int string_to_number(string s){
    int n = 0;
    
    for (int i = 0; i < s.length(); i++){
        n = n * 26 + s[i] - 'A' + 1;
    }
    
    return n;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;

        // hàm isdigit tìm chữ số
        // trừ cả trường hợp R23
        if (s[0] == 'R' && isdigit(s[1]) && s.find('C') != string::npos){
            int pos = s.find('C');
            int row = stoi(s.substr(1, pos - 1)); // lấy số hàng
            int col = stoi(s.substr(pos + 1)); // lấy số cột
            string str = number_to_string(col) + to_string(row);
            cout << str << endl;
        }
        else{
            int i = 0;

            while (i < s.size() && isalpha(s[i])) i++; // tìm đến số

            string colStr = s.substr(0, i);
            int row = stoi(s.substr(i));
            int col = string_to_number(colStr);
            cout << "R" << row << "C" << col << endl;
        }
    }
}   