#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = 0) { data = d, next = nullptr; }
};

bool Floyd_detect_loop(Node *_head)
{
    Node *slow = _head, *fast = _head;
    while (slow != nullptr && fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
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

    Floyd_detect_loop(head) ? cout << "Cycle Detected !" : cout << "Cycle Not Detected !";

    return 0;
}