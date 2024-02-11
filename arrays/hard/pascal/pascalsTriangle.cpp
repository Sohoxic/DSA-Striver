// variation1: given row and column find the element of the pascal triangle
#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    int rem =1;
    for(int i=0; i<r; i++){
        rem*=n-i;
        rem/= i+1;
    }
    return rem;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; 
    int c = 3; 
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "<<element;
    return 0;
}
        