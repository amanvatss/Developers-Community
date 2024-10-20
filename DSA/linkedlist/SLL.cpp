/*
    A Singly Linked List (SLL) is a linear data structure consisting of nodes, where each node holds data and a pointer to the next node in the sequence, allowing unidirectional traversal from the head to the end (NULL). 
    This implementation supports key operations such as insertion at the head, tail, or a specific position, deletion at a given position with proper tail management, and list reversal by rearranging pointers.
     Additionally, it includes concatenation functionality to merge two lists by linking the tail of one to the head of another. A menu-driven interface provides user-friendly interaction, enabling efficient management and traversal of two linked lists.
*/

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~node() {
        this->next = NULL;  // Prevent dangling pointers
    }
};

// Function to insert at the head
void insertathead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

// Function to insert at the tail
void insertattail(node*& tail, int d) {
    node* temp = new node(d);
    tail->next = temp;
    tail = temp;
}

// Function to insert at a specific position
void insertatposition(node*& head, node*& tail, int position, int d) {
    if (position == 1) {
        insertathead(head, d);
        return;
    }

    node* temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertattail(tail, d);
    } else {
        node* nodetoinsert = new node(d);
        nodetoinsert->next = temp->next;
        temp->next = nodetoinsert;
    }
}

// Function to delete at a specific position
void deleteatposition(int position, node*& head, node*& tail) {
    if (position == 1) {
        node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    } else {
        node* curr = head;
        node* prev = NULL;
        int count = 1;

        while (count < position && curr != NULL) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }

        prev->next = curr->next;
        if (curr->next == NULL) {
            tail = prev;
        }
        delete curr;
    }
}

// Function to reverse the linked list
node* reverse(node*& head) {
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Function to display the linked list
void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to concatenate two linked lists
void concatenate(node*& head1, node*& tail1, node* head2) {
    if (head1 == NULL) {
        head1 = head2;  // If first list is empty, assign second list to it
    } else {
        tail1->next = head2;  // Link the two lists
    }

    // Update the tail of the first list
    if (head2 != NULL) {
        node* temp = head2;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        tail1 = temp;
    }
}

// Main function with menu
int main() {
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    int choice, n, value, position;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head (List 1)\n";
        cout << "2. Insert at Tail (List 1)\n";
        cout << "3. Insert at Position (List 1)\n";
        cout << "4. Delete at Position (List 1)\n";
        cout << "5. Display List 1\n";
        cout << "6. Reverse List 1\n";
        cout << "7. Insert at Head (List 2)\n";
        cout << "8. Display List 2\n";
        cout << "9. Concatenate List 2 into List 1\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the number of values to insert at head (List 1): ";
            cin >> n;
            cout << "Enter the values: ";
            for (int i = 0; i < n; i++) {
                cin >> value;
                if (head1 == NULL) {
                    head1 = new node(value);
                    tail1 = head1;
                } else {
                    insertathead(head1, value);
                }
            }
            break;

        case 2:
            cout << "Enter the number of values to insert at tail (List 1): ";
            cin >> n;
            cout << "Enter the values: ";
            for (int i = 0; i < n; i++) {
                cin >> value;
                if (head1 == NULL) {
                    head1 = new node(value);
                    tail1 = head1;
                } else {
                    insertattail(tail1, value);
                }
            }
            break;

        case 3:
            cout << "Enter the position and value to insert (List 1): ";
            cin >> position >> value;
            insertatposition(head1, tail1, position, value);
            break;

        case 4:
            cout << "Enter the position to delete (List 1): ";
            cin >> position;
            deleteatposition(position, head1, tail1);
            break;

        case 5:
            cout << "List 1: ";
            display(head1);
            break;

        case 6:
            head1 = reverse(head1);
            cout << "List 1 reversed." << endl;
            break;

        case 7:
            cout << "Enter the number of values to insert at head (List 2): ";
            cin >> n;
            cout << "Enter the values: ";
            for (int i = 0; i < n; i++) {
                cin >> value;
                if (head2 == NULL) {
                    head2 = new node(value);
                    tail2 = head2;
                } else {
                    insertathead(head2, value);
                }
            }
            break;

        case 8:
            cout << "List 2: ";
            display(head2);
            break;

        case 9:
            concatenate(head1, tail1, head2);
            cout << "List 2 concatenated into List 1." << endl;
            break;

        case 10:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
