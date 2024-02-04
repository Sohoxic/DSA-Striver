
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int min = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<min){
            min = arr[i];
        }
        maxPro = max(maxPro, arr[i]-min);
    }

    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
