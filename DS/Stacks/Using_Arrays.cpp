#include <iostream>
using namespace std;

template <typename T, int SIZE>
class Stack
{
private:
    T arr[SIZE];
    int Top;

public:
    Stack() { Top = -1; }
    bool empty() { return Top == -1; }
    int size() { return Top + 1; }
    T top() { return arr[Top]; }
    void push(T val)
    {
        if (size() < SIZE)
            arr[++Top] = val;
    }
    void pop()
    {
        if (!empty())
            Top--;
    }
};

template <class U, int S>
void display(Stack<U, S> x)
{
    while (x.size())
    {
        cout << x.top() << " ", x.pop();
    }
}

int main()
{
    const int size = 5;
    Stack<int, size> s;

    int choice;
    do
    {
        cout << "1. Stack     2. Push     3. Pop      4. Top      5. Size\nChoice : ", cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Stack : ", display(s);
            break;
        case 2:
            if (s.size() < size)
            {
                cout << "Enter Element : ";
                int t;
                cin >> t;
                s.push(t);
            }
            else
                cout << "OverFlow";
            break;
        case 3:
            s.size() ? s.pop(), cout << "Element Removed" : cout << "UnderFlow";
            break;
        case 4:
            s.empty() ? cout << "Stack Empty" : cout << "Top Element : " << s.top();
            break;
        case 5:
            cout << "Size : " << s.size();
            break;
        default:
            choice = 0;
            break;
        }
        cout << "\n\n";
    } while (choice);
    return EXIT_SUCCESS;
}