// 2020-Dot1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Lưu ý bắt đầu từ số siêu bé, nếu lớn hơn update
int MaxBelow(int a[], int n, int k)
{
    int maxbelow = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i]<a[k] && a[i]>maxbelow)
            maxbelow = a[i];
    }
    return maxbelow;
}
//Lưu ý bắt đầu từ số siêu lớn, nếu nhỏ hơn update
int MinAbove(int a[], int n, int k)
{
    int minabove = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i]>a[k] && a[i]<minabove)
            minabove = a[i];
    }
    return minabove;
}

int Search(int a[], int n, int value)
{
    int mid, l = 0, r = n - 1;
    while (l <= r) //Lưu ý <= nhé
    {
        mid = (l + r) / 2;
        if (a[mid] == value)
            return mid;
        if (a[mid] < value)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int LongestHill (int a[], int n)
{
    if(n<3)
        return -1;

    int base_max = -1;
    int len_max = -1;
    int base = -1, end = -1, peak = -1, len = 0;

    for (int i=0;i<n;i++)
    {
        //tìm base
        if(a[i]<a[i+1] && i<n-1)
        {
            base = i;
            while (a[i]<a[i+1] && i<n-1)
                i++;
            peak = i;//Tìm peak
            while (a[i]>a[i+1] && i<n-1)
                i++;
            end = i;//Tìm end
            if(end == peak)
                continue;
            else
            {
                len = end - base + 1;
                if(len > len_max)
                {
                    len_max = len;
                    base_max = base;
                }
            }
            i--;//chú ý trừ 1, vì giá trị cuối này có thể là chân của núi tiếp theo
        }

    }
    return len_max;
}

int main()
{
    int a[] = {2,3,5,6,8,10,13,17,20,23,32,35,38,45,47,50};
    //int b[] = {2,3,4,5,3,2,4,5,6,7,8,9,3,2,3,4,3,2,1,0,1,2,3,4,5,3,2};
    //int b[] = { 9,8,7,6,5,6,7,4,3,2,1,0,3,4,5,6,6};
    int b[] = {1,2,1};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);
    cout << "Max below a[2] = 8 -> " << MaxBelow(a, n, 2) << endl;
    cout << "Min above a[3] = 2 -> " << MinAbove(a, n, 3) << endl;
    cout << "Vi tri cua so 2: " << Search(a,n, 2) << endl;
    cout << "Vi tri cua so 10: " << Search(a, n, 10) << endl;
    cout << "Vi tri cua so 13: " << Search(a, n, 13) << endl;
    cout << "Vi tri cua so 17: " << Search(a, n, 17) << endl;
    cout << "Vi tri cua so 20: " << Search(a, n, 20) << endl;
    cout << "Vi tri cua so 50: " << Search(a, n, 50) << endl;
    cout << "Chuoi dang Moutain dai nhat: "<< LongestHill(b,m) <<endl;


    int iNum1 = 92342309;
    int iNum2 = iNum1 / 10;
    int iNum3 = iNum2 / 10;
    int iNum4 = iNum3 / 10;
    int iNum5 = iNum1 / 1000;
    cout << iNum2 << endl;
    cout << iNum3 << endl;
    cout << iNum4 << endl;
    cout << iNum5 << endl;

    int x = iNum1 % 10;
    int x10 = iNum2 % 10;
    int x100 = iNum3 % 10;
    int x1000 = iNum4 % 10;
    cout << x << endl;
    cout << x10 << endl;
    cout << x100 << endl;
    cout << x1000 << endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
