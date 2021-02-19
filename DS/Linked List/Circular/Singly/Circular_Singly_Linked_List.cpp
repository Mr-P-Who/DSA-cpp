#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0) { data = d, next = nullptr; }
};

class Singly_Linked_List
{
public:
    Node *head, *tail;
    Singly_Linked_List(Node *n = nullptr)
    {
        head = n, tail = n;
        if (n != nullptr)
            n->next = head;
    }
    ~Singly_Linked_List()
    {
        if (head != nullptr)
        {
            while (head != tail)
            {
                Node *ptr = head;
                head = head->next;
                delete ptr;
            }
            delete head;
            head = tail = nullptr;
        }
    }

    bool empty() { return head == nullptr; }

    int size()
    {
        int count = 0;
        if (head != nullptr)
        {
            Node *ptr = head;
            do
            {
                count++;
                ptr = ptr->next;
            } while (ptr != head);
        }
        return count;
    }

    void push_front(Node *new_node)
    {
        if (!empty())
        {
            new_node->next = head;
            head = new_node;
            tail->next = head;
        }
        else
        {
            head = new_node, tail = new_node;
            new_node->next = head;
        }
    }

    void push_back(Node *new_node)
    {
        if (!empty())
        {
            tail->next = new_node;
            tail = new_node;
            new_node->next = head;
        }
        else
        {
            head = new_node, tail = new_node;
            new_node->next = head;
        }
    }

    void insert_at(Node *new_node, int pos)
    {
        if (pos == 0 || pos > size()) // Not Valid
            return;
        else if (pos == 1)
            push_front(new_node);
        else
        {
            int count = 1;
            Node *ptr = head;
            while (count < pos - 1)
            {
                count++;
                ptr = ptr->next;
            }
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }

    void pop_front()
    {
        if (!empty())
        {
            if (head->next == head) // For 1 Node
            {
                delete head;
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
                delete tail->next;
                tail->next = head;
            }
        }
    }

    void pop_back()
    {
        if (!empty())
        {
            if (head->next == head) // For 1 Node
            {
                delete head;
                head = tail = nullptr;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != tail)
                    ptr = ptr->next;
                delete tail;
                tail = ptr;
                tail->next = head;
            }
        }
    }

    void delete_at(int pos)
    {
        int s = size();
        if (pos == 0 || pos > s) //Not Valid
            return;
        else if (pos == 1)
            pop_front();
        else if (pos == s)
            pop_back();
        else
        {
            int count = 1;
            Node *ptr = head;
            while (count < pos - 1)
            {
                count++;
                ptr = ptr->next;
            }
            Node *temp = ptr->next; //Node To Be Deleted
            ptr->next = temp->next;
            delete temp;
        }
    }
};

void print(Singly_Linked_List &s)
{
    if (s.head != nullptr)
    {
        Node *ptr = s.head;
        do
        {
            cout << " -> " << ptr->data;
            ptr = ptr->next;
        } while (ptr != s.head);
        cout << " -> ";
    }
}

int main()
{
    Singly_Linked_List s1;
    int choice;
    do
    {
        cout << "\n1. Insert Node   2. Delete Node   3. Size   4. Print   0. Exit\nChoice : ";
        cin >> choice;
        switch (choice)
        {
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
            case 0:
                break;
            case 1:
                s1.push_front(new_node);
                break;
            case 2:
                int pos;
                cout << "Enter Position : ";
                cin >> pos;
                s1.insert_at(new_node, pos);
                break;
            case 3:
                s1.push_back(new_node);
                break;
            default:
                cout << "Enter Valid Choice !";
                break;
            }
            print(s1);
            break;
        }
        case 2:
            if (s1.empty())
                cout << "List Empty !";
            else
            {
                cout << "1. At Begin   2. At Position   3. At End\nChoice : ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    s1.pop_front();
                    cout << "Deleted Successfully !";
                    break;
                case 2:
                    int pos;
                    cout << "Enter Position : ";
                    cin >> pos;
                    s1.delete_at(pos);
                    cout << "Deleted Successfully !";
                    break;
                case 3:
                    s1.pop_back();
                    cout << "Deleted Successfully !";
                    break;
                default:
                    cout << "Enter Valid Choice !";
                    break;
                }
                cout << endl;
                print(s1);
            }
            break;
        case 3:
            cout << "Size Of List : " << s1.size();
            break;
        case 4:
            if (s1.empty())
                cout << "List Empty !";
            else
                print(s1);
            break;
        default:
            cout << "Enter Valid Choice !";
            break;
        }
        cout << "\n";
    } while (choice);

    return 0;
}
