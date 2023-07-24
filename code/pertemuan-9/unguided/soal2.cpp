#include <iostream>

using namespace std;

struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

void init()
{
    root = NULL;
}

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

void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

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
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
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
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Update Data
void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\nData node: " << node->data << endl;
            cout << "Root: " << root->data << endl;

            if (!node->parent)
            {
                cout << "Parent : {tidak punya parent} " << endl;
            }
            else
            {
                cout << "Parent : " << node->parent->data << endl;
            }

            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
            {
                cout << "Sibling : " << node->parent->left->data << endl;
            }
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
            {
                cout << "Sibling : " << node->parent->right->data << endl;
            }
            else
            {
                cout << "Sibling : {tidak punya sibling}" << endl;
            }

            if (!node->left)
            {
                cout << "Child kiri : {tidak punya child kiri }" << endl;
            }
            else
            {
                cout << "Child kiri : " << node->left->data << endl;
            }

            if (!node->right)
            {
                cout << "Child kanan : {tidak pynya child kanan}" << endl;
            }
            else
            {
                cout << "Child kanan : " << node->right->data << endl;
            }
        }
    }
}

// Penelusuran (Traversal)
// PreOrder
void preOrder(Pohon *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// in Order
void inOrder(Pohon *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
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
        cout << "\nBuat tree terlebih dahulu" << endl;
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

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }

            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree" << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (!root)
    {
        cout << "\nBuat tree terebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (!root)
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);

            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    cout << "\nSize Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}

int main()
{
    init();

    int riyon_221102241;
    char data;
    Pohon *currentNode = NULL;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Buat Node Baru" << endl;
        cout << "2. Tambah Node Kiri" << endl;
        cout << "3. Tambah Node Kanan" << endl;
        cout << "4. Update Data Node" << endl;
        cout << "5. Lihat Isi Data Node" << endl;
        cout << "6. Cari Node" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Hapus SubTree" << endl;
        cout << "11. Clear Tree" << endl;
        cout << "12. Karakteristik Tree" << endl;
        cout << "13. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> riyon_221102241;

        switch (riyon_221102241)
        {
        case 1:
            if (isEmpty() == 1)
            {
                cout << "\nMasukkan data node baru: ";
                cin >> data;
                buatNode(data);
                currentNode = root;
            }
            else
            {
                cout << "\nTree sudah dibuat!" << endl;
            }
            break;
        case 2:
            if (currentNode != NULL)
            {
                cout << "\nMasukkan data node kiri: ";
                cin >> data;
                currentNode = insertLeft(data, currentNode);
            }
            else
            {
                cout << "\nPilih node terlebih dahulu!" << endl;
            }
            break;
        case 3:
            if (currentNode != NULL)
            {
                cout << "\nMasukkan data node kanan: ";
                cin >> data;
                currentNode = insertRight(data, currentNode);
            }
            else
            {
                cout << "\nPilih node terlebih dahulu!" << endl;
            }
            break;
        case 4:
            if (currentNode != NULL)
            {
                cout << "\nMasukkan data node baru: ";
                cin >> data;
                update(data, currentNode);
            }
            else
            {
                cout << "\nPilih node terlebih dahulu!" << endl;
            }
            break;
        case 5:
            if (currentNode != NULL)
            {
                retrieve(currentNode);
            }
            else
            {
                cout << "\nPilih node terlebih dahulu!" << endl;
            }
            break;
        case 6:
            if (currentNode != NULL)
            {
                find(currentNode);
            }
            else
            {
                cout << "\nPilih node terlebih dahulu!" << endl;
            }
            break;
        case 7:
            preOrder();
            break;
        case 8:
            inOrder();
            break;
        case 9:
            postOrder();
            break;
        case 10:
            if (currentNode != NULL)
            {
                deleteSub(currentNode);
                currentNode = root;
            }
            else
            {
                cout << "\nPilih node terlebih dahulu!" << endl;
            }
            break;
        case 11:
            clear();
            currentNode = NULL;
            break;
        case 12:
            characteristic();
            break;
        case 13:
            cout << "\nTerima kasih!" << endl;
            exit(0);
        default:
            cout << "\nPilih menu yang valid!" << endl;
        }
    }

    return 0;
}
