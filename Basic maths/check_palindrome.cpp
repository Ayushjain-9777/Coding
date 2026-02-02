#include <iostream>
using namespace std;

int reverse(int x)
{
    int result = 0;
    while(x!=0)
    {
        int digit = x%10;
        x /= 10;

        if (result > INT_MAX / 10 || result < INT_MIN / 10)
            return 0;

        result = result*10 + digit;
    }

    return result;
}

bool isPalindrome(int x)
{
    if(x < 0) return false;
    
    int temp = reverse(x);

    if(x == temp) return true;
    return false;
}
int main()
{
    int n, result;
    cin >> n;
    result = reverse(n);
    cout << result;
    return 0;
}