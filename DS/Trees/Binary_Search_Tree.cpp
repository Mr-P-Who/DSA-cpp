#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d = 0)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST() { root = NULL; }

    bool empty() { return root == NULL; }

    // Iterative insert
    void insert(Node *new_node)
    {
        if (root == NULL)
            root = new_node;
        else
        {
            Node *temp = root;
            while (temp != NULL)
            {
                if (new_node->data == temp->data)
                {
                    cout << "Duplicates Not Allowed !\n";
                    break;
                }
                else if (new_node->data < temp->data)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new_node;
                        break;
                    }
                    temp = temp->left;
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = new_node;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
    }

    // Recursive Insert // Method 1
    Node *insert(Node *new_node, Node *_root)
    {
        if (_root == NULL)
            return new_node;
        else if (new_node->data == _root->data)
            cout << "Duplicates Not Allowed !\n";
        else if (new_node->data < _root->data)
            _root->left = insert(new_node, _root->left);
        else
            _root->right = insert(new_node, _root->right);
        return _root;
    }

    /*
    // Recursive Insert // Method 2
    void insert(Node *new_node, Node *&_root)
    {
        if (_root == NULL)
            _root = new_node;
        else if (new_node->data == _root->data)
            cout << "Duplicates Not Allowed !\n";
        else if (new_node->data < _root->data)
            insert(new_node, _root->left);
        else
            insert(new_node, _root->right);
    }
    */

    void print_preorder(Node *_root)
    {
        if (_root != NULL)
        {
            cout << _root->data << " ";
            print_preorder(_root->left);
            print_preorder(_root->right);
        }
    }

    void print_inorder(Node *_root)
    {
        if (_root != NULL)
        {
            print_inorder(_root->left);
            cout << _root->data << " ";
            print_inorder(_root->right);
        }
    }

    void print_postorder(Node *_root)
    {
        if (_root != NULL)
        {
            print_postorder(_root->left);
            print_postorder(_root->right);
            cout << _root->data << " ";
        }
    }

    int height(Node *_root)
    {
        if (_root == NULL)
        {
            return -1;
        }
        else
        {
            int left_height = height(_root->left), right_height = height(_root->right);
            return left_height > right_height ? left_height + 1 : right_height + 1;
        }
    }

    void print_givenlevel(Node *_root, int level)
    {
        if (_root != NULL)
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

    Node *search(int val)
    {
        Node *temp = root;
        while (temp != NULL)
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

    Node *minimum_node(Node *_root)
    {
        Node *temp = _root;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }

    Node *maximum_node(Node *_root)
    {
        Node *temp = _root;
        while (temp->right != NULL)
            temp = temp->right;
        return temp;
    }

    Node *delete_node(Node *_root, int val)
    {
        if (_root == NULL) //Base Condition
            return _root;
        else if (val < _root->data) // Value smaller then goto left subtree
            _root->left = delete_node(_root->left, val);
        else if (val > _root->data) // Value larger then goto right subtree
            _root->right = delete_node(_root->right, val);
        else // Value Matches
        {
            Node *temp = NULL;
            if (_root->left == NULL) // Node with only right child OR No child
            {
                temp = _root->right;
                delete _root;
                return temp;
            }
            else if (_root->right == NULL) // Node with only left child
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
        return _root;
    }
};

int main()
{
    BST t1;
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
            t1.insert(new_node); // Iterative Insert
            // t1.root = t1.insert(new_node, t1.root); // Recursive Insert
            break;

        case 2:
            int val_2;
            cout << "Enter Value To Be Searched : ";
            cin >> val_2;
            new_node = t1.search(val_2);
            if (new_node != NULL)
                cout << "Search Found ! ";
            else
                cout << "Search Not Found !";
            break;
        case 3:
            int val_3;
            cout << "Enter Value To Be Deleted : ";
            cin >> val_3;
            new_node = t1.search(val_3);
            if (new_node != NULL)
            {
                t1.delete_node(t1.root, val_3);
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