// 2019-Dot1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


//Đề HTTT 2019
//Viết 1 lớp tên server sao cho chỉ có 10 đối tượng
class server
{
public:
    static const int MaxInstances = 3;
    static int numSer;
    static server* arrSer[MaxInstances];
    static void init()
    {
        numSer = 0;
        for (int i = 0; i < server::MaxInstances; i++)
            server::arrSer[i] = NULL;
    }
    static server* getServer(int k)
    {
        if (k - 1 >= MaxInstances || k - 1 < 0)
            return NULL;
      
        if (arrSer[k - 1] == NULL)
        {
            server* serverk = new server();
            numSer++;
            arrSer[k - 1] = serverk;
            return serverk;
        }
        return arrSer[k - 1];
    }
private:
    server() = default;
};

//Chứng minh ma trận là Monge 
//Bài này học được rằng mảng [][] khai báo tĩnh không ép kiểu về int** được
// Do int ** bao gồm một con trỏ int* ở đầu mỗi row của ma trận
// còn khai báo tĩnh int[][] thì không bao gồm con trỏ int* ở đầu mỗi row (chỉ liền 1 mảng)
// nên tạo 1 mảng cấp phát động sẽ ép kiểu về int** được
// còn với ma trận khai báo tĩnh thì không.
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

//Nhập 1 số nguyên ko âm, trả ra số nghịch đảo
//Đề 2019 - KHMT - mã 02
int reverse(int x)
{
    int r = 0;
    while (x != 0)
    {
        r = r * 10; 
        r += (x % 10);
        x = x / 10;
    }
    return r;
}

//Kiểm trùng dãy số nguyên có n phần tử với giá trị từ 0
// đến n-1. Xem giá trị nào bị trùng và trùng bao nhiêu
template <class T>
void checkDuplicate(const vector<T> &arr, vector<T> &dup, vector<T> &times)
{
    //Lưu ý cách khai báo init vector
    vector<T> counting(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        counting[arr[i]]++;
        if (counting[arr[i]] == 2)
        {
            dup.push_back(arr[i]);
            times.push_back(counting[arr[i]]);
        }
    }

    for (int i = 0; i < dup.size(); i++)
    {
        times[i] = counting[dup[i]];
    }
}

//Biến static phải được init ở scope global thế này.
// Không init trong bất kỳ hàm nào (kể cả hàm static)
// Chú ý khi init biến static array thì có thể chỉ cần init 1 giá trị ban đầu
// Sau khi init vẫn phải cho chạy lại hàm để init lại cho chắc
int server::numSer = 0;
server* server::arrSer[] = { NULL };


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

    //Tạo ma trận cấp phát động clone
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

    cout << sizeof(a)/sizeof(int) << endl;

    for (int i = 0; i < m; i++)
    {
        delete b[i];
    }
    delete b;



    server::init();
    server* ser1 = server::getServer(1);
    server* ser2 = server::getServer(2);
    server* ser3 = server::getServer(3);
    server* ser0 = server::getServer(0);
    server* ser4 = server::getServer(4);

    ser1 = server::getServer(1);
    ser2 = server::getServer(2);
    ser3 = server::getServer(3);

    cout << reverse(10000099) <<endl;
    //Kiểm trùng
    vector<int> numarr = {0,1,2,2,4,2,6,2,4,9};
    vector<int> dup, times;
    checkDuplicate(numarr, dup, times);
    for (int i = 0; i < dup.size(); i++)
    {
        cout << dup[i] << "-:-" << times[i] << endl;
    }

    return 0;

}
