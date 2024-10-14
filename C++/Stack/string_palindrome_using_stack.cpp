#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

class Stack{
private:
    char arr[MAX];
    int top;
public:
    Stack(){
        top=-1;
    }
    bool isEmpty(){
        return (top==-1)?true:false;
    }
    bool isFull(){
        return (top==MAX-1)?true:false;
    }
    void pushing(char n){
        if(isFull()){
            cout <<endl<<"The Stack is Full!!"<<endl;
        }
        else{
            top++;
            arr[top] = n;
        }
    }
    char popping(){
        if(isEmpty()){
            cout<<endl<<"The Stack is Empty!"<<endl;
        }
        else{
            return arr[top--];
        }
    }
    void printStack(){
        if(isEmpty()){
            cout<<endl<<"The Stack is Empty nothing to print"<<endl;
        }
        else{
            cout<<endl;
            for(int i=0;i<=top;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    string s1;
    cout<<"Enter any String:";
    cin>>s1;
    string s2="";
    Stack S;
    cout<<endl<<"The Original String is:"<<s1<<endl;
    const char *charArray = s1.c_str();
    for(int i=0;i<s1.length();i++){
        S.pushing(charArray[i]);
    }
    for(int i=0;i<s1.length();i++){
        string str(1,S.popping());
        s2 = s2+str;
    }
    cout<<endl<<"The Reversed String is:"<<s2<<endl;
    if(s1==s2){
        cout<<endl<<"Yes! The String is palindrome."<<endl;
    }
    else{
        cout<<endl<<"No! The String is not a palindrome."<<endl;
    }
    return 0;
}
