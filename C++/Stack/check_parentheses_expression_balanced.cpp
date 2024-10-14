#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    Node *next;
    Node(){
        data=' ';
        next = nullptr;
    }
    Node(char m){
        data = m;
        next=nullptr;
    }
};


class Stack{
private:
    Node *head=nullptr;
    Node *top=nullptr;
public:
    bool isEmpty(){
        return (top==nullptr);
    }
    void pushing(char n){
        Node *newNode = new Node(n);
        if(isEmpty()){
            top = newNode;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }

    char popping(){
        if(isEmpty()){
            cout<<endl<<"The Stack is Empty"<<endl;
            return ' ';
        }
        else{
            int nums = top->data;
            top = top->next;
            return nums;
        }
    }

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
    string s;
    Stack S1;
    cout<<"Enter the expression:";
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            S1.pushing(s[i]);
        }
        else if(s[i]==')'){
            S1.popping();
        }
        else if(s[i]==' '){

        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='%'){

        }
        else if(isalpha(s[i])){

        }
        else{
            cout<<endl<<"Invalid Input"<<endl;
            return -1;
        }
    }
    if(S1.isEmpty()){
        cout<<endl<<"The result is:"<<"true"<<endl;
    }
    else{
        cout<<endl<<"The result is:"<<"false"<<endl;
    }

    return 0;
}
