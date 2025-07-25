#include <bits/stdc++.h>
using namespace std;

// Node class represents a single element of the linked list
class Node
{
public:
    int val;    // Value stored in the node
    Node *next; // Pointer to the next node

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// Singly linked list class with various utility methods
class link_list
{
private:
    int size;   // Number of elements in the list
    Node *head; // Points to the first node
    Node *tail; // Points to the last node

public:
    // Constructor initializes empty list
    link_list()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    // Destructor deletes all nodes to prevent memory leaks
    ~link_list()
    {
        while (head != NULL)
        {
            delete_head();
        }
    }

    // Returns current number of nodes
    int get_size()
    {
        return size;
    }

    // Takes input and builds the list until -1 is entered
    void take_input()
    {
        while (true)
        {
            int val;
            cin >> val;
            if (val == -1)
            {
                return;
            }
            insert_at_tail(val);
        }
    }

    // Inserts new node at the beginning
    void insert_at_head(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        if (tail == NULL) // If list was empty
        {
            tail = head;
        }

        size++;
    }

    // Inserts new node at the end
    void insert_at_tail(int val)
    {
        Node *newNode = new Node(val);
        if (head != NULL)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
        size++;
    }

    // Inserts node at a specific position (0-based index)
    void insert_at_any_possition(int idx, int val)
    {
        if (idx < 0 || idx >= size)
            return;

        Node *newNode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    // Deletes the first node
    void delete_head()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // Deletes node at a specific index
    void delete_at(int idx)
    {
        if (idx == 0)
        {
            delete_head();
            return;
        }

        if (idx + 1 > size)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }

        Node *current = temp->next;
        Node *next_node = temp->next->next;

        temp->next = next_node;
        delete current;
        size--;
    }

    // Deletes the last node
    void delete_tail()
    {
        delete_at(size - 1);
    }

    // Returns the value at a given index
    int at(int idx)
    {
        Node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    // Returns a pointer to the node at index 'idx'
    Node *get_node_at(int idx)
    {
        Node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    // Sorts the list in range [stinidx, endidx) using bubble sort
    void sort(int stinidx, int endidx)
    {
        for (int i = stinidx; i < endidx; i++)
        {
            for (int j = i + 1; j < endidx; j++)
            {
                Node *a = get_node_at(i);
                Node *b = get_node_at(j);

                if (a->val > b->val)
                {
                    int tmp = a->val;
                    a->val = b->val;
                    b->val = tmp;
                }
            }
        }
    }

    // Prints the list from head to tail
    void print_list()
    {
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->val << " ";
        }
        cout << endl;
    }

    // Recursively reverses the singly linked list
    void reverse_list(Node *temp)
    {
        // Base case: reached last node
        if (temp->next == NULL)
        {
            head = temp; // Last node becomes new head
            tail = temp; // Also update tail
            return;
        }

        reverse_list(temp->next); // Recurse to the end
        temp->next->next = temp;  // Reverse the link
        temp->next = NULL;        // Break the original link
    }
};

int main()
{
    link_list ls;

    // Input format: elements followed by -1
    ls.take_input();

    // Sort the list
    ls.sort(0, ls.get_size());

    // Print sorted list
    ls.print_list();

    // Reverse the list recursively
    ls.reverse_list(ls.get_node_at(0));

    // Print reversed list
    ls.print_list();

    return 0;
}
