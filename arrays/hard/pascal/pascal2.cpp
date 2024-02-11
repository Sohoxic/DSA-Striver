// // generate the row of the pascal triangle
// #include <bits/stdc++.h>
// using namespace std;

// int nCr(int n, int r) {
//     long long res = 1;

//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// void pascalTriangle(int n) {
//     // printing the entire row n:
//     for (int c = 1; c <= n; c++) {
//         cout << nCr(n - 1, c - 1) << " ";
//     }
//     cout << "n";
// }

// int main()
// {
//     int n = 5;
//     pascalTriangle(n);
//     return 0;
// }


// Optimal approach
#include <bits/stdc++.h>
using namespace std;

void pascalTriangle(int n) {
    int ans = 1;
    cout<<ans<<" ";
    for (int i = 1; i <n; i++) {
        ans*= n-i;
        ans/= i;
        cout<<ans<<" ";
    }
    cout << "\n";
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}
