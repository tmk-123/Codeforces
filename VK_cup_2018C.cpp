#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> current_path;
    string command;

    while(n--){
        cin >> command;

        if (command == "cd"){
            string path;
            cin >> path;

            // nếu ký tự đầu là / thì về đường dẫn tuyệt đối, tức xóa hết đường dẫn cũ về đường dẫn này
            if (path[0] == '/'){
                current_path.clear();
            }

            stringstream ss(path);
            string p;
            while (getline(ss, p, '/')){
                if (p == ".."){
                    if (!current_path.empty()){
                        current_path.pop_back();
                    }
                } 
                // chuỗi rỗng vẫn có thể push vào vector nhưng không hiển thị giá trị
                else if(p != "") {
                    current_path.push_back(p);
                }
            }
        }
        else{
            cout << "/";
            for (string p : current_path){
                cout << p << "/";
            }
            cout << endl;
        }
    }
}