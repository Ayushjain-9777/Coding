#include <iostream>
using namespace std;

// Brute force Approach or Better Approach
// int gcd(int n1, int n2)
// {
//     if(n1<=0 || n2<=0) return -1;
//     if(n1 == 1 || n2  == 1) return 1;

//     int result = 1;
    
//     if(max(n1,n2)%min(n1,n2)==0) //if min divides max or n1 and n2 are equal 
//         return min(n1,n2); 
//     else {
//         for(int i=2; i<=min(n1,n2)/2; ++i)
//         {
//             if(n1%i==0 && n2%i==0)
//                 result = i;
//         }
//     }

//     return result;
// }


// Optimal Approach: Euclidean Algorithm - The Euclidean Algorithm is a method for finding the greatest common divisor (GCD)
// of two numbers. It operates on the principle that the GCD of two numbers remains
// the same even if the smaller number is subtracted from the larger number.
// To find the GCD of n1 and n2 where n1 > n2:
// 1. Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
// 2. Once one becomes 0, the other is the GCD of the original numbers.

int gcd(int n1, int n2)
{
    if(n1<=0 || n2<=0) return 0;
    
    int a = max(n1,n2);
    int b = min(n1,n2);

    while(b!=a)
    {
        a = a%b;    //a = a - b;
        if(a>b) continue;
        else {
            a = a + b;
            b = a - b;
            a = a - b;
        }
    }

    return a;
}

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    int ans;
    ans = gcd(num1,num2);

    cout << "GCD of " << num1 << " and " << num2 << " is: " << ans;

    return 0;
}