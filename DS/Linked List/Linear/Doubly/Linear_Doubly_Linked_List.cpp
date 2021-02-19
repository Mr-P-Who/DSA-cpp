#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int d = 0) { data = d, next = prev = NULL; }
};

class Doubly_Linked_List
{
public:
    Node *head;
    Doubly_Linked_List(Node *n = NULL) { head = n; }
    ~Doubly_Linked_List()
    {
        while (head)
        {
            Node *ptr = head;
            head = head->next;
            delete ptr;
        }
    }

    bool empty() { return head == NULL; }

    int size()
    {
        Node *ptr = head;
        int count = 0;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }

    void push_front(Node *new_node)
    {
        if (!empty())
        {
            new_node->next = head;
            head->prev = new_node;
        }
        head = new_node;
    }

    void insert_at(Node *new_node, int pos)
    {
        if (pos == 0) // Not Valid
            return;
        else if (pos == 1)
            push_front(new_node);
        else if (pos <= size())
        {
            Node *ptr = head;
            int count = 1;
            while (count < pos - 1)
            {
                count++;
                ptr = ptr->next;
            }
            new_node->next = ptr->next;
            new_node->prev = ptr;
            ptr->next->prev = new_node;
            ptr->next = new_node;
        }
    }

    void push_back(Node *new_node)
    {
        if (!empty())
        {
            Node *ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
        }
        else
            head = new_node;
    }

    void pop_front()
    {
        if (!empty())
        {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
    }

    void delete_at(int pos)
    {
        if (pos == 0) // Not Valid
            return;
        else if (pos == 1)
            pop_front();
        else if (pos <= size())
        {
            Node *ptr = head;
            int count = 1;
            while (count < pos - 1)
            {
                count++;
                ptr = ptr->next;
            }
            Node *temp = ptr->next; // Node To Be Deleted
            ptr->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    void pop_back()
    {
        if (!empty())
        {
            Node *ptr = head;
            if (ptr->next == NULL) // For 1 Node
            {
                delete ptr;
                head = NULL;
            }
            else
            {
                while (ptr->next->next != NULL)
                    ptr = ptr->next;
                delete ptr->next;
                ptr->next = NULL;
            }
        }
    }
};

void print(Doubly_Linked_List &d)
{
    Node *ptr = d.head;
    cout << "X <--> ";
    while (ptr != NULL)
    {
        cout << ptr->data << " <--> ";
        ptr = ptr->next;
    }
    cout << "X";
}

int main()
{
    Doubly_Linked_List d1;
    int choice;
    do
    {
        cout << "\n1. Insert Node   2. Delete Node   3. Size   4. Print   0. Exit\nChoice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
        {
            int val1;
            cout << "Enter Value : ";
            cin >> val1;
            Node *new_node = new Node(val1);
            cout << "1. At Begin   2. At Position   3. At End\nChoice : ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                d1.push_front(new_node);
                break;
            case 2:
                int pos;
                cout << "Enter Position : ";
                cin >> pos;
                d1.insert_at(new_node, pos);
                break;
            case 3:
                d1.push_back(new_node);
                break;
            default:
                cout << "Enter Valid Choice !";
                break;
            }
            print(d1);
            break;
        }
        case 2:
            if (d1.empty())
                cout << "List Empty !";
            else
            {
                cout << "1. At Begin   2. At Position   3. At End\nChoice : ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    d1.pop_front();
                    cout << "Deleted Successfully !";
                    break;
                case 2:
                    int pos;
                    cout << "Enter Position : ";
                    cin >> pos;
                    d1.delete_at(pos);
                    cout << "Deleted Successfully !";
                    break;
                case 3:
                    d1.pop_back();
                    cout << "Deleted Successfully !";
                    break;
                default:
                    cout << "Enter Valid Choice !";
                    break;
                }
                cout << endl;
                print(d1);
            }
            break;
        case 3:
            cout << "Size Of List : " << d1.size();
            break;
        case 4:
            if (d1.empty())
                cout << "List Empty !";
            else
                print(d1);
            break;
        default:
            cout << "Enter Valid Choice !";
            break;
        }
        cout << "\n";
    } while (choice);

    return 0;
}