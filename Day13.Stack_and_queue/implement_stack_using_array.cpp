#include<iostream>
#include <stack>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int size;
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top ++;
            arr[top] = element;
        }
        else  
            cout<<"Stack overflow\n";
    }
    void pop(){
        if(top >= 0){
            top = top-1;
        }
        else    
            cout<<"Stack Underflow\n";
    }
    int peek(){
        if(top >=0 )
            return arr[top];
        else    {
            cout<<"Stack is empty\n";
            return -1;}
    }
    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.peek()<<endl;
    /*
    // creation of stack
    stack<int> s;

    // push operation
    s.push(2);
    s.push(3);
    s.pop();
    cout<<"Printing top element "<<s.top()<<endl;

    if(s.empty()){
        cout<<"Stack is empty "<<endl;
    }
    else{
        cout<<"Stack is not empty\n";
    }
    */
    return 0;
}