#include <iostream>
using namespace std;

#define SIZE 5

class Stack
{
private:
    int arr[SIZE], top;

public:
    Stack() { top = -1; }

    bool empty() { return top == -1; }

    bool full() { return top == SIZE - 1; }

    int size() { return top + 1; }

    int peek() { return arr[top]; }

    void push(int val)
    {
        if (!full())
            arr[++top] = val;
    }

    void pop()
    {
        if (!empty())
            top--;
    }
};

void print(Stack s)
{
    while (!s.empty())
    {
        cout << s.peek() << " ";
        s.pop();
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
            if (!s.full())
            {
                cout << "Enter Value : ";
                cin >> choice;
                s.push(choice);
            }
            else
                cout << "Stack FULL !";
            break;
        case 2:
            if (!s.empty())
            {
                cout << "Value Removed : " << s.peek();
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
            s.empty() ? cout << "Stack EMPTY !" : cout << "Top Element : " << s.peek();
            break;
        default:
            cout << "Enter A Valid Input !!!";
            break;
        }
        cout << "\n";
    } while (choice);
    return EXIT_SUCCESS;
}