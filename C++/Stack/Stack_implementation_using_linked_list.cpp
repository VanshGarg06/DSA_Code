#include<bits/stdc++.h>
using namespace std;

//Creating the Structure for a node of a linked list taking two components one is data and the other is link to next node
class Node{
public:
    int data;
    Node *next;
    Node(){
        data=0;
        next = nullptr;
    }
    Node(int m){
        data = m;
        next=nullptr;
    }
};

//Creating Stack Structure with a top Stack pointer to avail the top element
class Stack{
private:
    Node *top=nullptr;
public:
    //This will check whether the Stack is Empty or not
    bool isEmpty(){
        return (top==nullptr)?true:false;
    }

    //This function enables push operation in the Stack
    void pushing(int n){
        Node *newNode = new Node(n);
        if(isEmpty()){
            top = newNode;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }

    //This function enables pop operation in the Stack
    int popping(){
        if(isEmpty()){
            cout<<endl<<"The Stack is Empty"<<endl;
            return -1;
        }
        else{
            int nums = top->data;
            top = top->next;
            return nums;
        }
    }

    //This function will print the data available in the stack
    void printStack(){
        if(isEmpty()){
            cout<<endl<<"The Stack is Empty"<<endl;
        }
        else{
            cout<<endl;
            Node *temp2 = top;
            while(temp2!=nullptr){
                cout<<temp2->data<<" ";
                temp2 = temp2->next;
            }
            cout<<endl;
        }
    }
};


int main(){
    int option,val;
    Stack S;
    //This is a menu driven program to Create a Stack and perform several operations on it
    while(1){
        cout<<endl<<"1. Push an element"<<endl;
        cout<<"2. Pop an element"<<endl;
        cout<<"3. Is Stack Empty"<<endl;
        cout<<"4. Printing the Stack"<<endl;
        cout<<"5. Exit the System"<<endl;
        cin>>option;
        switch(option){
        case 1:
            cout<<endl<<"Enter the value you want to enter into Stack:";
            cin>>val;
            S.pushing(val);
            break;
        case 2:
            val = S.popping();
            cout<<endl<<"The popped Element is:"<<val<<endl;
            break;
        case 3:
            (S.isEmpty())?cout<<endl<<"The Stack is Empty"<<endl:cout<<endl<<"The Stack has some data"<<endl;
            break;
        case 4:
            cout<<endl<<"The Elements are:"<<endl;
            S.printStack();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout<<endl<<"Invalid Input"<<endl;
            break;
        }
    }
    return 0;
}
