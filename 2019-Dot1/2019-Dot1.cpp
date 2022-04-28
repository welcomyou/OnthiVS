// 2019-Dot1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


bool checkMonge(int m, int n, int** a)
{
    bool flag = true;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[i][j] + a[i + 1][j + 1] > a[i][j + 1] + a[i + 1][j])
                flag = false;
        }
    }
    return flag;
}


void testarr(int** a, int m, int n)
{
    for (int i = 0; i <m; i++)
        for(int j=0; j<n; j++)
            cout << a[i][j];
}


int main()
{
    int a[4][3] = { 12, 2, 6,\
               32, 5, 4,\
               23, 8, 5,\
               32, 14, 10 };

    int a2[4][3] = { 52, 34, 53,\
               22, 1, 10,\
               30, 8, 15,\
               33, 5, 7 };

    int m = 4;
    int n = 3;
    int** b = new int* [m];
    for (int i = 0; i < m; i++)
    {
        b[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            b[i][j] = a[i][j];
    }


    bool kq = checkMonge(4, 3, (int**)b);
    cout << kq <<endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            b[i][j] = a2[i][j];
    }
    kq = checkMonge(4, 3, (int**)b);
    cout << kq << endl;

    for (int i = 0; i < m; i++)
    {
        delete b[i];
    }
    delete b;


    int c[2][3] = { 1,2,3, 4, 5, 6 };
    testarr((int**)c,2, 3);

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
