#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0) { data = d, next = nullptr; }
};

class Queue
{
public:
    Node *head = nullptr, *rear = nullptr;
    Queue(Node *n = nullptr) { head = n, rear = n; }
    ~Queue()
    {
        while (head != nullptr)
        {
            Node *ptr = head;
            head = head->next;
            delete ptr;
        }
    }

    bool empty() { return head == nullptr; }

    int size()
    {
        Node *ptr = head;
        int count = 0;
        while (ptr != nullptr)
        {
            ++count;
            ptr = ptr->next;
        }
        return count;
    }

    Node *front() { return head; }

    Node *back() { return rear; }

    void enqueue(Node *new_node)
    {
        empty() ? head = new_node : rear->next = new_node;
        rear = new_node;
    }

    void dequeue()
    {
        if (!empty())
        {
            Node *ptr = head;
            head == rear ? head = rear = nullptr : head = head->next;
            delete ptr;
        }
    }
};

void print(Queue &q)
{
    Node *ptr = q.head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    Queue q;
    int choice;
    do
    {
        cout << "\n1. Enqueue  2. Dequeue  3. Display  4. Size  5. Front  6. Back  0. Exit\n";
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            // Do Nothing
            break;
        case 1:
        {
            int val1;
            cout << "Enter Value : ";
            cin >> val1;
            Node *new_node = new Node(val1);
            q.enqueue(new_node);
            break;
        }
        case 2:
            if (!q.empty())
            {
                cout << "Value Removed : " << q.front()->data;
                q.dequeue();
            }
            else
                cout << "Queue EMPTY !";
            break;
        case 3:
            if (!q.empty())
            {
                cout << "Queue : ";
                print(q);
            }
            else
                cout << "Queue EMPTY !";
            break;
        case 4:
            cout << "Queue Size : " << q.size();
            break;
        case 5:
            q.empty() ? cout << "Queue EMPTY !" : cout << "Front Element : " << q.front()->data;
            break;
        case 6:
            q.empty() ? cout << "Queue EMPTY !" : cout << "Back Element : " << q.back()->data;
            break;
        default:
            cout << "Enter A Valid Input !!!";
            break;
        }
        cout << "\n";
    } while (choice);
    return EXIT_SUCCESS;
}
