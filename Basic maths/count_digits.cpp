#include <iostream>
#include <cmath>
using namespace std;

int count_digits(int n)
{
    int cnt;

    if(n==0) return 1;
    cnt = (int)(log10(abs(n))+1);   //Using absolute for negative values

    return cnt;
}

int main()
{
    int n, count;
    cout << "Enter number: ";
    cin >> n;

    count = count_digits(n);
    cout << endl;
    cout << count << endl;

    return 0;
}