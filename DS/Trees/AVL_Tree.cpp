#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

public:
    Node(int d = 0) : data(d), left(nullptr), right(nullptr)
    {
    }
};

class AVL
{
public:
    Node *root;

public:
    AVL() : root(nullptr)
    {
    }

    bool empty() { return root == nullptr; }

    int height(Node *_root)
    {
        if (_root == nullptr)
            return -1;
        else
        {
            int left_height = height(_root->left);
            int right_height = height(_root->right);
            return left_height > right_height ? left_height + 1 : right_height + 1;
        }
    }

    Node *minimum_node(Node *_root)
    {
        Node *temp = _root;
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    Node *maximum_node(Node *_root)
    {
        Node *temp = _root;
        while (temp->right != nullptr)
            temp = temp->right;
        return temp;
    }

    void print_preorder(Node *_root)
    {
        if (_root != nullptr)
        {
            cout << _root->data << " ";
            print_preorder(_root->left);
            print_preorder(_root->right);
        }
    }

    void print_inorder(Node *_root)
    {
        if (_root != nullptr)
        {
            print_inorder(_root->left);
            cout << _root->data << " ";
            print_inorder(_root->right);
        }
    }

    void print_postorder(Node *_root)
    {
        if (_root != nullptr)
        {
            print_postorder(_root->left);
            print_postorder(_root->right);
            cout << _root->data << " ";
        }
    }

    void print_givenlevel(Node *_root, int level)
    {
        if (_root != nullptr)
        {
            if (level == 0)
                cout << _root->data << " ";
            else
            {
                print_givenlevel(_root->left, level - 1);
                print_givenlevel(_root->right, level - 1);
            }
        }
    }

    void print_levelorder(Node *_root)
    {
        int h = height(_root);
        for (int i = 0; i <= h; i++)
        {
            print_givenlevel(_root, i);
        }
    }

    Node *search(const int &val)
    {
        Node *temp = root;
        while (temp != nullptr)
        {
            if (val == temp->data)
                break;
            else if (val < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return temp;
    }

    int balance_factor(Node *_root)
    {
        return _root == nullptr ? -1 : height(_root->left) - height(_root->right);
    }

    Node *right_rotate(Node *_root)
    {
        Node *x = _root->left;
        Node *y = x->right;
        x->right = _root;
        _root->left = y;
        return x;
    }

    Node *left_rotate(Node *_root)
    {
        Node *x = _root->right;
        Node *y = x->left;
        x->left = _root;
        _root->right = y;
        return x;
    }

    Node *insert(Node *new_node, Node *_root)
    {
        if (_root == nullptr)
            return new_node;
        else if (new_node->data == _root->data)
            cout << "Duplicates Not Allowed !\n";
        else if (new_node->data < _root->data)
            _root->left = insert(new_node, _root->left);
        else
            _root->right = insert(new_node, _root->right);
        int bf = balance_factor(_root);
        if (bf > 1)
        {
            if (new_node->data < _root->left->data) // Left Left Imbalance
                return right_rotate(_root);
            else if (new_node->data > _root->left->data) // Left Right Imbalance
            {
                _root->left = left_rotate(_root->left);
                return right_rotate(_root);
            }
        }
        else if (bf < -1)
        {
            if (new_node->data > _root->right->data) // Right Right Imbalance
                return left_rotate(_root);
            else if (new_node->data < _root->right->data) // Right Left Imbalance
            {
                _root->right = right_rotate(_root->right);
                return left_rotate(_root);
            }
        }
        return _root;
    }

    Node *delete_node(Node *_root, const int &val)
    {
        if (_root == nullptr)
            return _root;
        else if (val < _root->data)
            _root->left = delete_node(_root->left, val);
        else if (val > _root->data)
            _root->right = delete_node(_root->right, val);
        else
        {
            Node *temp = nullptr;
            if (_root->left == nullptr) // Node with only right child OR No child
            {
                temp = _root->right;
                delete _root;
                return temp;
            }
            else if (_root->right == nullptr) // Node with only left child
            {
                temp = _root->left;
                delete _root;
                return temp;
            }
            else // Node with two children
            {
                temp = minimum_node(_root->right);
                _root->data = temp->data;
                _root->right = delete_node(_root->right, temp->data);
            }
        }
        int bf = balance_factor(_root);
        if (bf == 2)
        {
            int temp_bf = balance_factor(_root->left);
            if (temp_bf >= 0) // Left Left Imbalance
                return right_rotate(_root);
            else if (temp_bf == -1) // Left Right Imbalance
            {
                _root->left = left_rotate(_root->left);
                return right_rotate(_root);
            }
        }
        else if (bf == -2)
        {
            int temp_bf = balance_factor(_root->right);
            if (temp_bf <= 0) // Right Right Imbalance
                return left_rotate(_root);
            else if (temp_bf == 1) // Right Left Imbalance
            {
                _root->right = right_rotate(_root->right);
                return left_rotate(_root);
            }
        }
        return _root;
    }
};

int main()
{
    AVL t1;
    int choice;
    do
    {
        cout << "\n";
        cout << "1. Insert   2. Search   3. Delete   4. Print   5. Height   6. Minimum & Maximum   0. Exit\nChoice : ";
        cin >> choice;
        Node *new_node = new Node();
        switch (choice)
        {
        case 0:
            // Exit
            break;
        case 1:
            int val_1;
            cout << "Enter Value To Be Inserted : ";
            cin >> val_1;
            new_node->data = val_1;
            t1.root = t1.insert(new_node, t1.root);
            break;

        case 2:
            int val_2;
            cout << "Enter Value To Be Searched : ";
            cin >> val_2;
            if (!t1.empty() && t1.search(val_2) != nullptr)
                cout << "Search Found ! ";
            else
                cout << "Search Not Found !";
            break;
        case 3:
            int val_3;
            cout << "Enter Value To Be Deleted : ";
            cin >> val_3;
            if (t1.search(val_3) != nullptr)
            {
                t1.root = t1.delete_node(t1.root, val_3);
                cout << "Search Found ! Value Deleted !";
            }
            else
                cout << "Search Not Found !";
            break;
        case 4:
            cout << "1. PreOrder  2. InOrder  3. PostOrder  4. LevelOrder\nChoice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                t1.print_preorder(t1.root);
                break;
            case 2:
                t1.print_inorder(t1.root);
                break;
            case 3:
                t1.print_postorder(t1.root);
                break;
            case 4:
                t1.print_levelorder(t1.root);
                break;
            default:
                cout << "Enter A Valid Choice !!!";
                break;
            }
            cout << "\n";
            break;
        case 5:
            cout << "Height Of Tree : " << t1.height(t1.root);
            break;
        case 6:
            cout << "Minimum Value : " << t1.minimum_node(t1.root)->data << "\n";
            cout << "Maximum Value : " << t1.maximum_node(t1.root)->data;
            break;
        default:
            cout << "Enter A Valid Choice !!!";
            break;
        }
        cout << "\n";
    } while (choice);

    return 0;
}