#include <iostream>
#include <cmath>
using namespace std;

bool armstrong_number(int n)
{
    int result = 0;
    int temp = n;
    int cnt = 0;
    while(temp)
    {
        temp /= 10;
        ++cnt;
    }
    temp = n;

    while(temp)
    {
        int digit = temp%10;
        result += pow(digit,cnt);
        temp /= 10;
    }

    return (n==result);
}

int main()
{
    int num;
    cin >> num;

    int result;
    result = armstrong_number(num);

    if(result==1)
        cout << "It is a Armstrong number" << endl;
    else 
        cout << "It is not a Armstrong number" << endl;

    return 0;
}