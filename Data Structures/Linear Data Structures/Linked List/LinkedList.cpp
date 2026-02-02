#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()
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
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search
    int search(int value)
    {
        int index = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return index;
            }
            index++;
            temp = temp->next;
        }
        return -1;
    }

    // Count
    int count()
    {
        return length;
    }

    // Insertion

    // Insert At The Beginning (Prepend)
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Insert At The End (Append)
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (tail != nullptr)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
        length++;
    }

    // Insert At A Given Position
    void insert(int index, int value)
    {
        if (index < 0 || index > length)
        {
            std::cout << "Invalid Index" << std::endl;
            return;
        }

        if (index == 0)
        {
            prepend(value);
            return;
        }

        Node *newNode = new Node(value);
        Node *temp = head;
        int current = 0;

        while (current < index - 1)
        {
            temp = temp->next;
            current++;
        }
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr)
        {
            tail = newNode;
        }

        length++;
    }

    // Deletion

    // Delete From The Beginning
    void shift()
    {
        if (head == nullptr)
        {
            cout << "List Is Empty!" << endl;
            return;
        }
        Node *temp = head;
        if (head->next == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }

        delete temp;
        temp = nullptr;
        length--;
    }

    // Delete From The End
    void pop()
    {
        if (head == nullptr)
        {
            cout << "List Is Empty" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        length--;
    }

    // Delete At A Specific Position
    void removeAtIndex(int index)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Invalid Index" << std::endl;
            return;
        }

        if (index == 0)
        {
            shift();
            return;
        }

        Node *temp = head;
        int current = 0;
        while (current < index - 1)
        {
            temp = temp->next;
            current++;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;

        if (temp->next == nullptr)
        {
            tail = temp;
        }

        delete toDelete;
        length--;
    }

    // Clear
    void clear()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        tail = nullptr;
        length = 0;
    }

    // Checking If Empty
    void empty()
    {
        if (length == 0)
        {
            std::cout << "Empty" << std::endl;
        }
        else
        {
            std::cout << "Not Empty" << std::endl;
        }
    }

    // Get
    int get(int index)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Invalid Index" << std::endl;
            return -1;
        }

        int current = 0;
        Node *temp = head;

        while (current < index)
        {
            temp = temp->next;
            current++;
        }

        return temp->data;
    }

    // Set
    void set(int index, int value)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Invalid Index" << std::endl;
            return;
        }

        int current = 0;
        Node *temp = head;

        while (current < index)
        {
            temp = temp->next;
            current++;
        }

        temp->data = value;
        std::cout << "Value At Index " << index << " Updated To " << value << std::endl;
    }

    // Reverse
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Middle
    Node *middle()
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node *fast = head;
        Node *slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {}
