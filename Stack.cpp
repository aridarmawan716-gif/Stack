#include <iostream>
using namespace std;

// Struktur node untuk menampung data
struct node {
    int data;
    node* next;
};

class Stack {
public:
    node *top;

    // Constructor
    Stack() {
        top = NULL;
    }

    // Fungsi Push: Menambah elemen ke tumpukan paling atas
    void push(node *n) {
        n->next = top;
        top = n;
    }

    // Fungsi Pop: Mengambil/menghapus elemen paling atas
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow! (Stack kosong)" << endl;
            return;
        }
        node* n = top;
        top = top->next;
        delete(n);
    }

    // Fungsi Print: Menampilkan isi stack dari atas ke bawah
    void print() {
        if (top == NULL) {
            cout << "Stack kosong." << endl;
            return;
        }
        node* ptr = top;
        while(ptr != NULL) {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};

// Fungsi pembantu untuk membuat node baru
node* createNode(int val) {
    node* newNode = new node();
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Stack s;

    cout << "--- Memasukkan data (Push) ---" << endl;
    s.push(createNode(10));
    s.push(createNode(20));
    s.push(createNode(30));
    s.print(); // Output: 30, 20, 10

    cout << "\n--- Menghapus data teratas (Pop) ---" << endl;
    s.pop();
    s.print(); // Output: 20, 10

    cout << "\n--- Push data baru (40) ---" << endl;
    s.push(createNode(40));
    s.print(); // Output: 40, 20, 10

    return 0;
}
