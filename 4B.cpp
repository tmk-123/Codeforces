#include<bits/stdc++.h>

using namespace std;
 
int main(){
    int d, sumTime;
    cin >> d >> sumTime;
 
    vector<int> minTime(d), maxTime(d);
    int minTotal = 0, maxTotal = 0;
 
    for (int i = 0; i < d; i++){
        cin >> minTime[i] >> maxTime[i];
        minTotal += minTime[i];
        maxTotal += maxTime[i];
    }
 
    if (sumTime < minTotal || sumTime > maxTotal){
        cout << "NO";
        return 0;
    }
 
    vector<int> schedule = minTime;
    int remainingTime = sumTime - minTotal;
 
    for (int i = 0; i < d; i++){
        int addTime = min(remainingTime, maxTime[i] - minTime[i]);
        schedule[i] += addTime;
        remainingTime -= addTime;
        if (remainingTime == 0) break;
    }
 
    cout << "YES" << endl;
    for (int i = 0; i < d; i++){
        cout << schedule[i] << " ";
    }
 
    return 0;
}