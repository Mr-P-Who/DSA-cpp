#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0) { data = d, next = nullptr; }
};

Node *Brent_detect_loop(Node *_head)
{
    if (_head == nullptr)
        return nullptr;
    int length = 1, power = 1;
    Node *slow = _head, *fast = _head->next;
    while (fast != nullptr && fast != slow)
    {
        if (length == power)
        {
            power *= 2;
            length = 0;
            slow = fast;
        }
        fast = fast->next;
        ++length;
    }
    if (fast == nullptr) // Loop Not Found
        return nullptr;
    slow = fast = _head;
    while (length > 0)
    {
        fast = fast->next;
        --length;
    }
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // Start of the loop
}

int main()
{
    Node n1(10), n2(20), n3(30), n4(40), n5(50); // Creating Nodes
    Node *head = &n1;                            // Creating head
    // Creating the links
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n2; // Creating Loop
    //

    Node *ptr = Brent_detect_loop(head);
    ptr == nullptr ? cout << "Cycle Not Detected !" : cout << "Cycle Detected ! Cycle Begins At : " << ptr->data;

    return 0;
}