#include <iostream>
#include <iomanip>
using namespace std;

//Tìm x bằng đệ quy
double timx_recursive(double a, double b, double c, int k)
{
    if (k == 0)
        return a;
    double bonus = 0;
    if (k % 3 == 0)
        bonus += c;
    return bonus + timx_recursive(a, b, c, k - 1) * (1 + b);
}

//Tìm x không đệ quy
double timx(double a, double b, double c, int k)
{
    double x = a;
    for (int i = 1; i <= k; i++)
    {
        double delta = x * b;
        if (i % 3 == 0)
            delta += c;
        x += delta;
    }
    return x;
}

//Tìm a theo cách thông thường O(n)
double tima(double m, double b, double c, int k)
{
    double a = m;
    for (int i = k; i >= 1; i--)
    {
        double bonus = 0;
        if (i % 3 == 0)
            bonus += c;
        a = (a - bonus) / ( 1 + b);
    }
    return a;
}

//Tìm a theo cách tìm kiếm binary search O(nlogn)
double tima_bs(double m, double b, double c, int k)
{
    double l = 1;
    double r = m;
    double mid;
    double xk;

    while (l <= r)
    {
        mid = (l + r) / 2;
        xk = timx(mid, b, c, k);

        if (abs(xk - m) < 1) //sai số chấp nhận
            return mid;

        if (xk > m)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    cout.precision(15);
    double a = 100000000;
    double b = 0.01;
    double c = 50000;
    double x = timx(a, b, c, 4);
    cout << "A) So tien dau tu sau 4 nam: " << x << endl;
    x = timx_recursive(a, b, c, 12);
    cout << "B) So tien dau tu sau 12 nam (dung ham de quy): " << x << endl;
    x = timx(a, b, c, 12);
    cout << "C) So tien dau tu sau 12 nam (Khong dung ham de quy): " << x << endl;
    double y = tima(112891778, b, c, 12);
    cout << "D) So tien dau tu ban dau toi thieu de co 112.891.778VND sau 12 nam O(n): " << y << endl;
    y = tima_bs(112891778, b, c, 12);
    cout << "D) So tien dau tu ban dau toi thieu de co 112.891.778VND sau 12 nam O(nlogn): " << y << endl;

    return 0;
}