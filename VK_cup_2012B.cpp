    #include <bits/stdc++.h>

    using namespace std;

    int main() {
        int n;
        cin >> n;
        
        int a[5] = {0};
        for (int i = 0; i < n; i++){
            int size;
            cin >> size;
            a[size]++;
        }

        // tính bằng cách ưu tiên từ nhóm 4, nhóm (3, 1), (2, 1, 1) rồi (2, 2) 
        // bởi nếu (2, 1, 1) trước thì số 3 sẽ bị thừa, chọn hết 3 mới đến hết số 1 để tối ưu (2, 1, 1)
        // cuối cùng xét 2 2 sau khi hết 3 và 1

        int cnt = a[4];
        
        int temp = min(a[3], a[1]);
        cnt += temp;
        a[3] -= temp;
        a[1] -= temp;

        temp = min(a[2], a[1] / 2);
        cnt += temp;
        a[1] -= 2 * temp;
        a[2] -= temp;

        temp = a[2] / 2;
        cnt += temp;
        a[2] -= 2 * temp;

        // cộng phần còn lại
        // phần còn lại có thể còn (3, 2) (2, 1) hoặc còn 3 lẻ hoặc 1 lẻ
        if (a[2] > 0){
            cnt++;
            if (a[1] > 0) a[1]--;
        }
        cnt += a[3];
        cnt += (a[1] + 3) / 4;

        cout << cnt;

        return 0;
    }
