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

int main()
{
    int n, result;
    cin >> n;
    result = reverse(n);
    cout << result;
    return 0;
}