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
