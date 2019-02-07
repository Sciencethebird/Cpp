#include<iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;   ///create a pointer with type "Node", which points to next node
};

template <class T>
class ListStack
{
public:

    ListStack()   ///constructor
    {
        size = 0;
        top = nullptr; /// point to nothing when start
    }
    T Top()
    {
        return top -> data;
    }
    void printstack()
    {
        if(top == nullptr)
        {
            cout <<"Stack is empty" << endl;
        }
        Node<T> *current = top;
        while(current != 0)
        {
            cout << current-> data << " ";
            current = current->next;
        }

    }
    void pop()
    {
        if(isEmpty())
        {

        }
        top = top->next;
        size--;
    }
    void push(T data)
    {
        Node<T> *newNode = new Node<T>;
        newNode-> data = data;
        (*newNode).next = top;
        top  = newNode;
        size++;
    }
    bool isEmpty()
    {
        if(top == 0)
            return true;
        else
            return false;
    }
    int getSize()
    {
        return size;
    }
private:
    Node<T> *top;     // pointer to top element
    int size;     //  number of allocated nodes
};
int main()
{
    ListStack<int> stack;
    cout << "Is Stack Empty? "<< stack.isEmpty() << endl;
    for(int i = 0; i<100; i++)
    {

        stack.push(i);
    }
    cout << "Is Stack Empty? "<< stack.isEmpty() << endl;
    stack.push(0);
    stack.push(4);
    stack.pop();
    stack.push(4);
    stack.push(4);
    stack.push(4);
    stack.push(7);
    stack.pop();
    stack.printstack();
    cout << "size = " << stack.getSize()<< endl;


    return 0 ;
}


