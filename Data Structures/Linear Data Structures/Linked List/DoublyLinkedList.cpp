#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    // Traversal

    // Forward Traversal
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }

    // Backward Traversal
    void rdisplay()
    {
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->prev != nullptr)
            {
                cout << " <-> ";
            }
            temp = temp->prev;
        }
        cout << " <-> NULL" << endl;
    }

    /*
        TODO: Add Operations:
        1. Searching
        2. Count
        3. Insertion
            > At The Beginning
            > At The End
            > At A Specific Position
        4. Deletion
            > At The Beginning
            > At The End
            > At A Specific Position
        5. Clear
        6. Get
        7. Set
        8. Reverse
        9. Middle
    */
};

int main()
{
}
