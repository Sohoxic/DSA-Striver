


#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> a, int x){
    for(int i=0; i<a.size(); i++){
        if(x == a[i]){
            return 1;
        }
    }
    return 0;
}

int longestSuccessiveElements(vector<int> &a, int n){
    int longest = 1;

    for(int i=0; i<n; i++){
        int x = a[i];
        int count=1;
        while(linearSearch(a, x+1)){
            x++;
            count++;
        }
        longest = max(longest, count);
    }

    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int n = a.size();
    int ans = longestSuccessiveElements(a, n);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
