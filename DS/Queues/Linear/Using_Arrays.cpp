#include <iostream>
using namespace std;

template <typename T, int SIZE>
class Queue
{
private:
    T arr[SIZE];
    int Front, Back;

public:
    Queue() { Front = Back = -1; }
    bool empty() { return Front == -1; }
    int size() { return empty() ? 0 : Back - Front + 1; }
    T front() { return empty() ? NULL : arr[Front]; }
    T back() { return empty() ? NULL : arr[Back]; }
    void push(T val)
    {
        if (empty())
            Front++;
        if (Back != SIZE - 1)
            arr[++Back] = val;
    }
    void pop()
    {
        if (!empty())
        {
            Front == Back ? Front = Back = -1 : Front++;
        }
    }
};

template <typename U, int S>
void display(Queue<U, S> x)
{
    while (x.size())
    {
        cout << x.front() << " ", x.pop();
    }
}

int main()
{
    const int size = 5;
    Queue<int, size> q;

    int choice;
    do
    {
        cout << "1. Queue     2. Push     3. Pop      4. Front      5. Back     6. Size\nChoice : ", cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Queue : ", display(q);
            break;
        case 2:
            if (q.size() < size)
            {
                cout << "Enter Element : ";
                int t;
                cin >> t;
                q.push(t);
            }
            else
                cout << "OverFlow";
            break;
        case 3:
            q.size() ? q.pop(), cout << "Element Removed" : cout << "UnderFlow";
            break;
        case 4:
            q.empty() ? cout << "Queue Empty" : cout << "Front Element : " << q.front();
            break;
        case 5:
            q.empty() ? cout << "Queue Empty" : cout << "Back Element : " << q.back();
            break;
        case 6:
            cout << "Size : " << q.size();
            break;
        default:
            choice = 0;
            break;
        }
        cout << "\n\n";
    } while (choice);
    return EXIT_SUCCESS;
}