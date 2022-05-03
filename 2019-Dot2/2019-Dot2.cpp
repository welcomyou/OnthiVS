// 2019-Dot2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

/*
Đề 2019 đợt 2 của KHMT (mã đề 02)

Bài này chủ yếu là xây dựng 1 cây nhị phân tìm kiếm trong mỗi node có chứa link đến parent
Do link đến parent nên cách insert sẽ hơi khó một chút so với bình thường
Khi insert thì ko thể để điểm dừng tại NULL (vì cần link đến parent)
Do đó phải dừng ở node lá - Check điều kiện pLeft, pRight rồi thêm vào

Học khai báo template <class T>
Node<int>* tree
Gọi hàm function<int>(a, b)

Có thêm 1 câu của đề 2015 là tìm số lớn nhất bé hơn N mà phải là số chẵn
- Convert tree ra mảng
- Chạy tuần tự check < N và %2==0
- Ôn lại sử dụng vector
Hoặc có thể duyệt mảng RNL để sắp thứ tự cao xuống thấp. Kết quả sẽ là node đầu tiên < N và có %2==0


Xóa node trên cây, theo lý thuyết thì chia 3 TH dừng cho hàm đệ quy
- Node lá
- Node có 1 con
- Node có 2 con
Tuy nhiên khi mình làm thì chỉ cần check các điểm dừng sau
- Node lá
- Node có left thì tìm Max left (ưu tiên chạy nếu có cả left và right)
- Node có Right thì tìm Min right

Ôn lại sử dụng (a!=0?true:false)

Kiểm tra xem cây này có phải cây con hay ko?
Lặp kiếm giá trị key của root cây con trên cây cha xem có những chỗ nào
Với từng chỗ, viết hàm để check so sánh 2 cây. So sánh node, left, right
và dùng toán tử && để tổng hợp kết quả
*/


template<class T>
struct Node
{
    T key;
    Node* pLeft;
    Node* pRight;
    Node* pParent;
};

template<class T>
void traversal(Node<T>* tree)
{
    if (tree == NULL)
        return;
    traversal(tree->pLeft);
    cout << tree->key << "--";
    traversal(tree->pRight);
}

template<class T>
void insertnode(Node<T>* &tree, T value)
{
    if (tree == NULL)//TH cây rỗng
    {
        Node<T>* x = new Node<T>;
        x->pLeft = x->pRight = x->pParent = NULL;
        x->key = value;
        tree = x;
        return;
    }

    if (value < tree->key)
    {
        if (tree->pLeft == NULL)
        {
            Node<T>* x = new Node<T>;
            x->pLeft = x->pRight =  NULL;
            x->key = value;
            x->pParent = tree;
            tree->pLeft = x;
        }
        else//Nếu chưa rỗng đi tiếp
            insertnode(tree->pLeft, value);
    }
    else
    {
        if (tree->pRight == NULL)
        {
            Node<T>* x = new Node<T>;
            x->pLeft = x->pRight = NULL;
            x->key = value;
            x->pParent = tree;
            tree->pRight = x;
        }
        else//Nếu chưa rỗng đi tiếp
            insertnode(tree->pRight, value);
    }

}
template<class T>
Node<T>* convertArrayToTree(int a[], int n)
{
    Node<T>* tree = NULL;
    for (int i = 0; i < n; i++)
        insertnode(tree, a[i]);
    return tree;
}

template<class T>
void convertTreeToArray(Node<T>* tree, vector<Node<T>*> &v)
{
    //Đổ hết ra mảng
    if (tree == NULL)
        return;
    convertTreeToArray(tree->pLeft, v);
    v.push_back(tree);
    convertTreeToArray(tree->pRight, v);
}


template<class T>
Node<T>* findMaxEvenBelow(Node<T>* tree, int N)
{
    //Đổ hết ra mảng
    vector<Node<T>*> v;
    convertTreeToArray(tree, v);

    //Search tuần tự
    Node<T>* kq = NULL;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->key > N)
            break;
        if (v[i]->key % 2 == 0)
            kq = v[i];
    }
    return kq;
}



template<class T>
Node<T>* searchTreeRecursive(Node<T>* tree, T value)
{
    if (tree == NULL)
        return NULL;

    if (value == tree->key)
        return tree;

    if (value < tree->key)
        searchTreeRecursive(tree->pLeft, value);
    else
        searchTreeRecursive(tree->pRight, value);
}


template<class T>
Node<T>* searchTree(Node<T>* tree, T value)
{
    if (tree == NULL)
        return NULL;

    Node<T>* node = tree;

    while (node != NULL)
    {
        if (value == node->key)
            return node;
        if (value < node->key)
            node = node->pLeft;
        else
            node = node->pRight;
    }
    return NULL;
}


template<class T>
Node<T>* findMaxBelow(Node<T>*& tree, int N)
{
    if (tree == NULL)
        return NULL;

    if (tree->key == N)
        return tree;
    else
    {
        if (tree->key < N)
        {
            Node<T>* k = findMaxBelow(tree->pRight, N);

            if (k == NULL)
                return tree;
            else
                return k;
        }
        else
            return findMaxBelow(tree->pLeft, N);
    }
}

template<class T>
Node<T>* findMax(Node<T>* tree)
{
	if (tree == NULL)
		return NULL;
	Node<T>* k = findMax(tree->pRight);
	if (k == NULL)
		return tree;
	else
		return k;
}

template<class T>
Node<T>* findMin(Node<T>* tree)
{
    if (tree == NULL)
        return NULL;
    Node<T>* k = findMin(tree->pLeft);
    if (k == NULL)
        return tree;
    else
        return k;
}


template<class T>
int removenode(Node<T>*& tree, int k)
{
    Node<T>* f = searchTree(tree, k);
    if (f == NULL)
        return 0;
    //là nút lá
    if (f->pLeft == NULL && f->pRight == NULL)
    {
        if (f->pParent == NULL) // 1 node duy nhất
            tree = NULL;
        else
        {
            //node lá trái
            if (f->pParent->pLeft == f)
                f->pParent->pLeft = NULL;
            else//node lá phải
                f->pParent->pRight = NULL;
        }
        delete f;
        return 1;
    }
    else
    {
        if (f->pLeft != NULL)
        {
            //Tìm con max trái từ vị trí của node đó
            Node<T>* max = findMax(f->pLeft);
            //Đổi giá trị
            f->key = max->key;
            //xóa max
            removenode(max, max->key);

        }
		else if (f->pRight != NULL)
		{
            //Tìm con min phải từ vị trí của node đó
            Node<T>* min = findMin(f->pRight);
            //Đổi giá trị
            f->key = min->key;
            //xóa min
            removenode(min, min->key);
		}
    }
    return -1;
}
// max must be NULL
template <class T>
Node<T>* Max_even_X(Node<T>* pRoot, int x, Node<T>*& max)
{
    if (max != NULL) //Đã tìm đc
        return max;

    if (pRoot == NULL) //Tìm ko thấy
        return NULL;

    Max_even_X(pRoot->pRight, x, max);

    if (pRoot->key < x && pRoot->key % 2 == 0 && max == NULL)
    {
        max = pRoot;
        return max;
    }

    Max_even_X(pRoot->pLeft, x, max);
}


template<class T>
bool IsMatch(Node<T>* root, Node<T>* child)
{
    if (root == child)
        return true;

    bool kq = true, kql = true, kqr = true;

    if (root->key != child->key)
        kq = false;

    if (root->pLeft != NULL && child->pLeft != NULL)
        kql = IsMatch(root->pLeft, child->pLeft);

    if (root->pRight != NULL && child->pRight != NULL)
        kqr = IsMatch(root->pRight, child->pRight);

    return kq && kql && kqr;

}

template<class T>
bool IsChild(Node<T>* root, Node<T>* child)
{
    bool kq = false;
    Node<T>* f = searchTree(root, child->key);
    while (f != NULL)
    {
        kq = IsMatch(f, child);
        if(child->key < f->key)
            f = searchTree(f->pLeft, child->key);
        else//check th trùng
            f = searchTree(f->pRight, child->key);
    }
    return kq;
}

int main()
{
    //Khai báo Tree bằng NULL
    Node<int>* tree = NULL;
    Node<int>* child = NULL;

    insertnode(tree, 7);
    insertnode(tree, 4);
    insertnode(tree, 12);
    insertnode(tree, 3);
    insertnode(tree, 5);
    insertnode(tree, 5);
    insertnode(tree, 9);
    insertnode(tree, 9);
    insertnode(tree, 13);
    insertnode(tree, 1);
    traversal(tree);
    cout << endl;

    insertnode(child, 4);
    insertnode(child, 3);
    insertnode(child, 1);
    insertnode(child, 5);
    insertnode(child, 6);
    traversal(child);

    cout << "Kiem tra cay con:" << IsChild<int>(tree, child)<<endl;

    int a[10] = { 7,4,12,3,5,5,9,9,13,1 };
    //Chú ý cách khai báo hàm template
    Node<int>* tree2 = convertArrayToTree<int>(a, 10);
    traversal(tree2);
    cout << endl;

    Node<int>* nodesearch = searchTreeRecursive<int>(tree, 4);
    //Chú ý phải có dấu ()
    cout << (nodesearch?nodesearch->key:0) <<endl;
    nodesearch = searchTree<int>(tree, 4);
    cout << (nodesearch?nodesearch->key:0) << endl;
    nodesearch = findMaxEvenBelow<int>(tree, 13);
    cout << (nodesearch ? nodesearch->key : -1) << endl;

    Node<int>* max = NULL;
    nodesearch = Max_even_X<int>(tree, 13, max);
    cout << (nodesearch ? nodesearch->key : -1) << endl;

    //xóa
    removenode(tree, 5);
    traversal(tree);




    Node<int>* pTree = NULL;
    insertnode(pTree, 8);
    insertnode(pTree, 3);
    insertnode(pTree, 10);
    insertnode(pTree, 2);
    insertnode(pTree, 6);
    insertnode(pTree, 14);
    insertnode(pTree, 4);
    insertnode(pTree, 7);
    insertnode(pTree, 13);
    max = NULL;
    nodesearch = Max_even_X<int>(pTree, 14, max);
    cout << endl<< endl<< (nodesearch ? nodesearch->key : -1) << endl;

    return 0;
}

