#include <iostream>
using namespace std;
unsigned long long f(unsigned long long n)
{
    if (n < 20190001) return n + 2018;
    return 20192018;
}
int main()
{
    unsigned long long n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}