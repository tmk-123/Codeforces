#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_map<string, int> database;

    while (n--){
        string name;
        cin >> name;

        if (database.count(name) == 0){
            cout << "OK" << endl;
            database[name] = 1;
        }
        else{
            cout << name << database[name] << endl;
            database[name] += 1;
        }
    }

    return 0;
}