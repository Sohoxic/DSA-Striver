// #include<bits/stdc++.h>
// using namespace std;

// void fib(int n){
//     int i=0, j =1, cur;
//     n-=2;
//     cout<<i<<" "<< j<<" "; 
//     while(n){
//         cur = i+j;
//         i = j;
//         j = cur;
//         n--;
//         cout<<cur<<" ";
//     }
// }

// int main(){
//     fib(5);
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int fib(int n){
   if(n<=1){
    return n; 
   }
   return fib(n-1)+fib(n-2);
}

int main(){
 
  int N = 4;
  cout<<fib(N)<<endl;
  return 0;

}