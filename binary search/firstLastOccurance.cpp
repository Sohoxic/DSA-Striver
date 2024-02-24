#include<bits/stdc++.h>
using namespace std;

int findFirst(vector<int> a, int n, int target){
    int first = -1;
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(target == a[mid]){
            first = mid;
            high = mid - 1;
        }
        else if(a[mid]<target){
            low = mid + 1;
        }
        else if(a[mid]>target){
            high = mid - 1;
        }
    }


    return first;
}

int findLast(vector<int> a, int n, int target){
    int last = -1;
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(target == a[mid]){
            last = mid;
            low = mid + 1;
        }
        else if(a[mid]<target){
            low = mid + 1;
        }
        else if(a[mid]>target){
            high = mid - 1;
        }
    }

    return last;
}

vector<int> findFirstAndLastOccurance(vector<int> a, int target){
    int n = a.size();
    int first = findFirst(a, n, target);
    if(first == -1) return {-1,-1};
    int last = findLast(a, n, target);

    return {first, last};
}

int main(){
    vector<int> a = {1,2,3,4,5,8,8,8,9,10,11,12,13,14};
    int target = 8;
    vector<int> ans = findFirstAndLastOccurance(a, target);
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}