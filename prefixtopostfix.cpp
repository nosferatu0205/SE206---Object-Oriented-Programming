#include<bits/stdc++.h>
using namespace std;
//author bsse 1227 mohammad momenuzzaman
char shtack[20];
int top = -1;

void push(char x)
{
    shtack[++top]=x;
}

char pop()
{
    if(top==-1) return -1;
    else return shtack[top--];

}

int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 2;
    return 0;
}

int main()
{
   // char exp[20];

    char exp[20];
    char *p, x;
    cout<<"Enter expression------";

    cin>>exp;
    p = exp;
    while(*p!='\0')
    {
        if(isalnum(*p))
        cout<<*p<<" ";
        else if(*p == '(')
        push(*p);
        
        else if(*p==')')
        {
            while((x=pop())!='(')
            cout<<x<<" ";
        }
        else
        {
            while(priority(shtack[top])>=priority(*p))
            cout<<pop()<<" ";
            push(*p);
        }
        p++;
    }

    while(top!=-1)
    {
        cout<<pop()<<" ";
    }return 0;
}