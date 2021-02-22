#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0) { data = d, next = nullptr; }
};

class Stack
{
public:
    Node *top;
    Stack(Node *n = nullptr) { top = n; }
    ~Stack()
    {
        while (top != nullptr)
        {
            Node *ptr = top;
            top = top->next;
            delete ptr;
        }
    }

    bool empty() { return top == nullptr; }

    int size()
    {
        Node *ptr = top;
        int count = 0;
        while (ptr != nullptr)
        {
            ++count;
            ptr = ptr->next;
        }
        return count;
    }

    Node *peek() { return top; }

    void push(Node *new_node)
    {
        if (!empty())
            new_node->next = top;
        top = new_node;
    }

    void pop()
    {
        if (!empty())
        {
            Node *ptr = top;
            top = top->next;
            delete ptr;
        }
    }
};

void print(Stack &s)
{
    Node *ptr = s.top;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    Stack s;
    int choice;
    do
    {
        cout << "\n1. Push  2. Pop  3. Display  4. Size  5. Peek  0. Exit\n";
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
            s.push(new_node);
            break;
        }
        case 2:
            if (!s.empty())
            {
                cout << "Value Removed : " << s.peek()->data;
                s.pop();
            }
            else
                cout << "Stack EMPTY !";
            break;
        case 3:
            if (!s.empty())
            {
                cout << "Stack : ";
                print(s);
            }
            else
                cout << "Stack EMPTY !";
            break;
        case 4:
            cout << "Stack Size : " << s.size();
            break;
        case 5:
            s.empty() ? cout << "Stack EMPTY !" : cout << "Top Element : " << s.peek()->data;
            break;
        default:
            cout << "Enter A Valid Input !!!";
            break;
        }
        cout << "\n";
    } while (choice);
    return EXIT_SUCCESS;
}