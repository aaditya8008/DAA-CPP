#include <iostream>
#include <queue>
using namespace std;

class BinaryTree
{
public:
    int arr[10];
    int root;

    BinaryTree(int r)
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = -1;
        }
        arr[0] = r;
        root = arr[0];
    }

    void insertLeft(int data, int child)
    {
        int idx = (2 * child) + 1;
        int parent = (child - 1) / 2;
        if (idx < 10)
        {
            if (arr[parent] == -1)
            {
                cout << "Parent is Empty\n";
            }
            else
            {
                arr[idx] = data;
            }
        }
        else
        {
            cout << "Index Out of Bounds\n";
        }
    }

    void insertRight(int data, int child)
    {
        int idx = (2 * child) + 2;
        int parent = (child - 1) / 2;
        if (idx < 10)
        {
            if (arr[parent] == -1)
            {
                cout << "Parent is Empty\n";
            }
            else
            {
                arr[idx] = data;
            }
        }
        else
        {
            cout << "Index Out of Bounds\n";
        }
    }

    void deleteLeft(int idx)
    {
        int i = 2 * idx + 1;
        if (arr[i] != -1)
        {
            while (arr[i] != -1)
            {
                int id = 2 * i + 1;
                if (arr[id] == -1)
                {
                    arr[idx] = arr[i];
                    arr[i] = -1;
                    break;
                }
                i++;
            }
        }
        else
        {
            cout << "It's Empty\n";
        }
    }

    void deleteRight(int idx)
    {
        int i = 2 * idx + 2;
        if (arr[i] != -1)
        {
            while (arr[i] != -1)
            {
                int id = 2 * i + 2;
                if (arr[id] == -1)
                {
                    arr[idx] = arr[i];
                    arr[i] = -1;
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
        else
        {
            cout << "It's Empty\n";
        }
    }

    void levelOrder()
    {
        queue<int> l;
        l.push(0);
        while (!l.empty())
        {
            int idx = l.front();
            l.pop();
            cout << arr[idx] << endl;
            int lidx = 2 * idx + 1;
            int ridx = 2 * idx + 2;
            if (arr[lidx] != -1)
            {
                l.push(lidx);
            }
            if (arr[ridx] != -1)
            {
                l.push(ridx);
            }
        }
    }

    bool search(int value, int idx = 0)
    {
        if (idx < 10 && arr[idx] != -1)
        {
            if (arr[idx] == value)
            {
                return true;
            }
            return search(value, 2 * idx + 1) || search(value, 2 * idx + 2);
        }
        else
        {
            return false;
        }
    }
   void inorder(int idx = 0) {
    if (idx >= 10 || arr[idx] == -1) {
        return;
    }
    inorder(2 * idx + 1);
    cout << arr[idx] << " ";
    inorder(2 * idx + 2);
}
   void preorder(int idx = 0) {
    if (idx >= 10 || arr[idx] == -1) {
        return;
    }
    cout << arr[idx] << " ";
    preorder(2 * idx + 1);
    
    preorder(2 * idx + 2);
}

 void postorder(int idx = 0) {
    if (idx >= 10 || arr[idx] == -1) {
        return;
    }
   
    postorder(2 * idx + 1);
    
    postorder(2 * idx + 2);
     cout << arr[idx] << " ";
}


    void print_tree()
    {
        cout << "\n";
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == -1)
            {
                cout << "-";
            }
            else
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    BinaryTree bt(12);
    bt.insertLeft(13, 0);  // Child of root
    bt.insertRight(17, 0); // Child of root
    bt.insertLeft(19, 1);
    bt.print_tree();
    bt.levelOrder();
    cout << bt.search(15);
    cout << "\nInOrder\n";
    bt.inorder();
    return 0;
}
