#include <iostream>
using namespace std;

#define SIZE 5

class Queue
{
private:
    int arr[SIZE], head, rear;

public:
    Queue() { head = rear = -1; }

    bool empty() { return head == -1; }

    bool full() { return rear == SIZE - 1; }

    int size() { return empty() ? 0 : rear - head + 1; }

    int front() { return arr[head]; }

    int back() { return arr[rear]; }

    void enqueue(int val)
    {
        if (!full())
        {
            arr[++rear] = val;
            if (empty())
                ++head;
        }
    }

    void dequeue()
    {
        if (!empty())
            head == rear ? head = rear = -1 : head++;
    }
};

void print(Queue q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.dequeue();
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
            if (!q.full())
            {
                cout << "Enter Value : ";
                cin >> choice;
                q.enqueue(choice);
            }
            else
                cout << "Queue FULL !";
            break;
        case 2:
            if (!q.empty())
            {
                cout << "Value Removed : " << q.front();
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
            q.empty() ? cout << "Queue EMPTY !" : cout << "Front Element : " << q.front();
            break;
        case 6:
            q.empty() ? cout << "Queue EMPTY !" : cout << "Back Element : " << q.back();
            break;
        default:
            cout << "Enter A Valid Input !!!";
            break;
        }
        cout << "\n";
    } while (choice);
    return EXIT_SUCCESS;
}
