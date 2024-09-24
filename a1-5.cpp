#include <iostream>

using namespace std;

// We have defined a Stack class with the required functions to be used in the problem
class Stack {
    
    int* arr;
    int top;
    int capacity;

    public:
    
        Stack(int size) { // The constructor has been defined for you
            arr = new int[size];
            capacity = size;
            top = -1;
        }

        ~Stack() {
            delete[] arr;
        }

        // Function to add an element to the stack
        void push(int x) {
            if (isFull()) {
                cout << "Stack overflow!" << endl;
                return;
            }
            arr[++top] = x;
        
        }

        // Function to pop the top element
        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow!" << endl;
                return -1;
            }
            return arr[top--];
        }

        // Function to display the elements of the stack
        void display() const {
            if (isEmpty()) {
                cout << "Empty";
            } else {
                for (int i = 0; i <= top; i++) {
                    cout << arr[i] << " ";
                }
            }
            cout << endl;
        }

    private:
    
        // Function to check if the stack is full
        bool isFull() const {
            return top == capacity - 1;
        }

        // Function to check if the stack is empty
        bool isEmpty() const {
            return top == -1;
        }

};

// Stacks have been defined globally for the towers A, B, and C for printing the towers at each step
Stack* A;
Stack* B;
Stack* C;

// Function to display the contents of the towers
void displayTowers() {
    cout << "Tower A: ";
    A->display();
    cout << "Tower B: ";
    B->display();
    cout << "Tower C: ";
    C->display();
    cout << "\n";
}
// Function to move disks between towers
void moveDisk(Stack& from, Stack& to, char fromTower, char toTower) {
    int disk = from.pop();
    if (disk != -1) {
        to.push(disk);
        cout << "Move disk " << disk << " from " << fromTower << " to " << toTower << endl;
        displayTowers();
    }
void rearrangeDisks(int n, Stack& A, Stack& B, Stack& C, char from, char to, char aux) {
    if (n == 1) {
        moveDisk(A,B, from, to);
        return;
    }

    rearrangeDisks(n - 1, A,C,B, from, aux, to);
    moveDisk(source, target, from, to);
    rearrangeDisks(n - 1, C,B,A, aux, to, from);
}

int main() { // The main function has been defined for you, do not edit anything here.
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    A = new Stack(n);
    B = new Stack(n);
    C = new Stack(n);

    for (int i = n; i >= 1; i--) {
        A->push(i);
    }

    displayTowers();

    rearrangeDisks(n, *A, *B, *C, 'A', 'C', 'B');

    delete A;
    delete B;
    delete C;

    return 0;
}
