// USE the stl library for next_permutation(arr.begin(), arr.end());


#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &a) {
    int n = a.size();
    int index = -1;
    for(int i=n-2; i>=0; i--){
        if(a[i]<a[i+1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(a.begin(), a.end());
        return a;
    }

    for(int j=n-1; j>index; j--){
        if(a[j]>a[index]){
            swap(a[j], a[index]);
            break;
        }
    }
    
    reverse(a.begin()+index+1, a.end());

    return a;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}
