#include<bits/stdc++.h>
using namespace std;

int findSecondLargestElement(int a[]){
    int largest = INT_MIN, secondLargest = INT_MIN;
    int size = sizeof(a);
    for(int i = 0; i<size; i++){

         if(a[i] > largest){
             secondLargest = largest;
             largest = a[i]; 
         }
         else if(a[i] > secondLargest && a[i] < largest){
            secondLargest = a[i];
         }
     }

    return secondLargest;
}

int   main(){
    int a[] = {1,2,3,4,5,6,7,8};
    cout<<findSecondLargestElement(a);
}