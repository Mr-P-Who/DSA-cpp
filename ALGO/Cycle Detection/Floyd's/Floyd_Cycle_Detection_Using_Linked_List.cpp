#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0) { data = d, next = nullptr; }
};

Node *Floyd_detect_loop(Node *_head)
{
    if (_head == nullptr) // If list is empty
        return nullptr;
    Node *slow = _head, *fast = _head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == nullptr || fast->next == nullptr) // Loop Not Found
        return nullptr;
    else
    {
        slow = _head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast; // Start of the loop
    }
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

    Node *ptr = Floyd_detect_loop(head);
    ptr == nullptr ? cout << "Cycle Not Detected !" : cout << "Cycle Detected ! Cycle Begins At : " << ptr->data;

    return 0;
}