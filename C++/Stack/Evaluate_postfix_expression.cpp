#include<bits/stdc++.h>
using namespace std;

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


class Stack{
private:
    Node *head=nullptr;
    Node *top=nullptr;
public:
    bool isEmpty(){
        return (top==nullptr);
    }
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

    int popping(){
        if(isEmpty()){
            cout<<endl<<"The Stack is Empty"<<endl;
            return -1;
        }
        else{
            int nums = top->data;
            top = top->next;
                /*
            Node *temp1=top;
            while(temp1->next!=nullptr){
                temp1 = temp1->next;
            }
            Node *temps = top;
            while(temps->next!=temp1){
                temps = temps->next;
            }
            temps->next = nullptr;
            top = temps;*/
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

int precedence(char ch){
    if(ch=='*'){
        return 3;
    }
    else if(ch=='/'){
        return 3;
    }
    else if(ch=='%'){
        return 3;
    }
    else if(ch=='+'){
        return 2;
    }
    else if(ch=='-'){
        return 2;
    }
    else{
        return -1;
    }
}

int main(){
    string s;
    cout<<"Enter the postfix expression:";
    getline(cin,s);
    Stack S1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            S1.pushing(s[i] - '0');
        }
        else if(s[i]=='+'){
            int num1 = S1.popping();
            int num2 = S1.popping();
            int ans = num1+num2;
            S1.pushing(ans);
        }
        else if(s[i]=='-'){
            int num1 = S1.popping();
            int num2 = S1.popping();
            int ans = abs(num2-num1);
            S1.pushing(ans);
        }
        else if(s[i]=='*'){
            int num1 = S1.popping();
            int num2 = S1.popping();
            int ans = num1*num2;
            S1.pushing(ans);
        }
        else if(s[i]=='/'){
            int num1 = S1.popping();
            int num2 = S1.popping();

            if(num1!=0){
                int ans = max(num1,num2)/min(num1,num2);
                S1.pushing(ans);

            }
            else{
                cout<<endl<<"Error: Division by zero."<<endl;
                return 1;
            }
        }
        else if(s[i]=='%'){
            int num1 = S1.popping();
            int num2 = S1.popping();
            if(num1!=0){
                int ans = max(num1,num2)%min(num1,num2);
                S1.pushing(ans);

            }
            else{
                cout<<endl<<"Error: Division by zero."<<endl;
                return 1;
            }
            S1.printStack();
        }
        else if(s[i]==' '){

        }
        else{
            cout<<endl<<"Invalid Input"<<endl;
            return -1;
        }
    }

    cout<<endl<<"The resultant evaluation is:"<<S1.popping()<<endl;
    return 0;
}
