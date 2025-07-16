#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;    // Value stored in the node
    Node *next; // Pointer to the next node in the list
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class link_list
{
private:
    int size;   // Number of nodes in the list
    Node *head; // Pointer to the first node
    Node *tail; // Pointer to the last node

public:
    // Constructor initializes empty list
    link_list()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    // Destructor to free all nodes and avoid memory leaks
    ~link_list()
    {
        while (head != NULL)
        {
            delete_head();
        }
    }

    // Return current size of the list
    int get_size()
    {
        return size;
    }

    // Read integers from standard input until -1 is entered, and insert at tail
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

    // Insert a new node with value 'val' at the beginning of the list
    void insert_at_head(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        // If list was empty, tail also points to the new head
        if (tail == NULL)
        {
            tail = head;
        }

        size++;
    }

    // Insert a new node with value 'val' at the end of the list
    void insert_at_tail(int val)
    {
        Node *newNode = new Node(val);
        if (head != NULL)
        {
            // Attach new node after tail and update tail pointer
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            // If list empty, new node becomes both head and tail
            head = newNode;
            tail = newNode;
        }
        size++;
    }

    // Insert a node with value 'val' at index 'idx' (0-based)
    // Does nothing if idx is invalid (less than 0 or >= size)
    void insert_at_any_possition(int idx, int val)
    {
        if (idx == 0)
        {
            insert_at_head(val);
            return;
        }
        if (idx == size)
        {
            insert_at_tail(val);
            return;
        }

        if (idx < 0 || idx >= size)
            return;

        Node *newNode = new Node(val);
        Node *temp = head;

        // Traverse to node just before desired position
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }

        // Insert new node by adjusting next pointers
        newNode->next = temp->next;
        newNode->prev = temp;
        newNode->next->prev = newNode;
        temp->next = newNode;
        size++;
    }

    // Delete the head node of the list, if it exists
    void delete_head()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        if (temp == tail)
        {
            tail = head;
        }

        delete temp;
        size--;
    }

    // Delete the node at index 'idx' (0-based)
    void delete_at(int idx)
    {
        if (idx == 0)
        {
            delete_head();
            return;
        }

        // Check if index is valid
        if (idx + 1 > size)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        Node *temp = head;
        // Traverse to node before the one to be deleted
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }

        Node *current = temp->next;         // Node to delete
        Node *next_node = temp->next->next; // Node after the one to delete

        // Adjust next pointer to exclude current node
        next_node->prev = temp;
        temp->next = next_node;
        delete current;
        size--;
    }

    // Delete the last node (tail) of the list
    void delete_tail()
    {
        if (head == tail)
        {
            delete_head();
        }

        Node *temp = tail;
        Node *prev = tail->prev;
        temp->prev->next = NULL;
        tail = prev;
        delete temp;
    }

    // Return the value stored at node index 'idx' (0-based)
    int at(int idx)
    {
        Node *temp = head;

        // Traverse to desired node
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp->val;
    }

    // Return pointer to node at index 'idx'
    Node *get_node_at(int idx)
    {
        Node *temp = head;

        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp;
    };

    // Sort nodes in the range [stinidx, endidx) by their values using simple bubble sort
    void sort(int stinidx, int endidx)
    {
        for (int i = stinidx; i < endidx; i++)
        {
            for (int j = i + 1; j < endidx; j++)
            {
                Node *a = get_node_at(i);
                Node *b = get_node_at(j);

                // Swap values if out of order
                if (a->val > b->val)
                {
                    int tmp = a->val;
                    a->val = b->val;
                    b->val = tmp;
                }
            }
        }
    }

    // Print all elements of the list in order separated by spaces
    void print_list()
    {
        for (Node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->val << " ";
        }
        cout << endl;
    }

    // Recursively print elements from index 'end - 1' down to 'st'
    void reverse_list()
    {
        Node *st = head;
        Node *end = tail;
        while (st <= end)
        {
            swap(st->val, end->val);
            st = st->next;
            end = end->prev;
        }
    }
};

int main()
{
    link_list ls; // Create linked list object

    // Take input until -1 is entered
    ls.take_input();

    // Sort entire list
    // ls.sort(0, ls.get_size());
    // ls.delete_tail();
    // ls.delete_head();
    ls.insert_at_any_possition(2, 10);
    ls.insert_at_any_possition(4, 20);
    ls.delete_at(2);
    // Print sorted list
    ls.print_list();

    // Print list in reverse order
    ls.reverse_list();
    ls.print_list();

    return 0;
}
