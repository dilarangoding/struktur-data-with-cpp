#include <iostream>

using namespace std;

// Program Binary Tree

// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init()
{
    root = NULL;
}

// Cek Node
int isEmpty()
{
    if (root == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Buat Node Baru
void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\nNode " << node->data << " sudah ada di child kiri!" << endl;
        }
        else
        {
            // Kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            return baru;
        }
    }
}

// Tambah kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (root == NULL)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\nNode " << node->data << " sudah ada di child kanan!" << endl;
        }
        else
        {
            // Kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            return baru;
        }
    }
}


// in Order
void inOrder(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// Post Order
void postOrder(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}


int main()
{
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeZ;

    nodeB = insertLeft('B', root);
    nodeF = insertRight('F', root);
    nodeC = insertLeft('C', nodeB);
    nodeE = insertRight('E', nodeF);
    nodeH = insertRight('H', nodeC);
    nodeD = insertLeft('D', nodeE);
    nodeG = insertRight('G', nodeE);
    nodeZ = insertLeft('Z', nodeH);

    cout << "\n InOrder :" << endl;
    inOrder(root);

    cout << "\n PostOrder :" << endl;
    postOrder(root);
}
