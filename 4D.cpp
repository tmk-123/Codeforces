#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 5001

// Russian Doll Envelopes 

int w[MAX], h[MAX]; // chiều rộng và chiều cao
int s[MAX]; // mảng lưu chỉ số để sắp xếp phong bì, s[i] = i
int dp[MAX]; // mảng lưu độ dài chuỗi chồng lên nhau dài nhất, phong bì đè lên có chiều rộng và chiều cao nhỏ hơn phong bì trước và phải to hơn cả tấm thiệp (W, H)
int path[MAX]; // lưu chỉ số phong bì trước đó

int cmp(int a, int b){
    if (w[a] == w[b]) return h[a] > h[b];
    return w[a] > w[b];
}

int main(){
    int n, W, H;
    cin >> n >> W >> H;

    for (int i = 0; i < n; i++){
        dp[i] = 1;
        path[i] = -1;
        s[i] = i;
        cin >> w[i] >> h[i];
    }

    sort(s, s + n, cmp);

    int maxCount = 0, bestIndex = -1;

    // lấy từ 0 để ra maxCount
    for (int i = 0; i < n; i++){
        // phong bì phải lớn hơn tấm thiệp
        if (h[s[i]] > H && w[s[i]] > W){
            for (int j = 0; j < i; j++){
                // Nếu đồ vật i có chiều rộng và chiều cao nhỏ hơn đồ vật j, kiểm tra xem có thể tăng chuỗi đồ vật xếp chồng lên i hay không.
                if (h[s[i]] < h[s[j]] && w[s[i]] < w[s[j]]){
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        path[i] = j; // chỉ số mà đồ vật i được xếp chồng lên hay chỉ số trước đó
                    }
                }
            }

            if (dp[i] > maxCount){
                maxCount = dp[i];
                bestIndex = i;
            }
        }
    }

    cout << maxCount << endl;

    if (bestIndex != -1){
        int yes = 0;
        while (bestIndex != -1){
            if (yes) cout << " ";
            cout <<  s[bestIndex] + 1; // thêm chỉ số vào res, đánh số từ 1 nên cộng 1
            bestIndex = path[bestIndex]; // lấy phong bì trước đó
            yes = 1;
        }        
        
        cout << endl;
    }

}