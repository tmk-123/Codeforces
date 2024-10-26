#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Hàm hỗ trợ để tách các phần của đường dẫn
vector<string> splitPath(const string& path) {
    vector<string> parts;
    stringstream ss(path);
    string part;
    while (getline(ss, part, '/')) {
        if (!part.empty()) {
            parts.push_back(part);
        }
    }
    return parts;
}

int main() {
    int n;
    cin >> n;
    vector<string> current_path;
    string command;
    
    while (n--) {
        cin >> command;
        
        if (command == "cd") {
            string path;
            cin >> path;
            // Kiểm tra đường dẫn tuyệt đối
            if (path[0] == '/') {
                current_path.clear();  // Reset về thư mục gốc
            }
            
            // Tách đường dẫn và xử lý từng phần
            vector<string> parts = splitPath(path);
            for (string& p : parts) {
                // ".." là quay về thư mục cha(thư mục trước)
                if (p == "..") {
                    if (!current_path.empty()) {
                        current_path.pop_back();
                    }
                } else {
                    current_path.push_back(p);
                }
            }
            
        } else if (command == "pwd") {
            cout << "/";

            // dir : directory
            for (const string& dir : current_path) {
                cout << dir << "/";
            }
            cout << endl;
        }
    }
    
    return 0;
}
