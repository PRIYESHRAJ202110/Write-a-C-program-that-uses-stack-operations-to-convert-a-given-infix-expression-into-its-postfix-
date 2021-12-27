#include<iostream>
#include<string>
#define MAX 20
using namespace std;

char stk[20];
int top=-1;

void pus(char oper)
{
    if(top==MAX-1)
    {
        cout<<"stackfull!!!!";
    }
   
    else
    {
        top++;
        stk[top]=oper;
    }
}

char pop()
{
    char ch;
    if(top==-1)
    {
        cout<<"stackempty!!!!";
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
int priority ( char alpha )
{
    if(alpha == '+' || alpha =='-')
    {
        return(1);
    }
 
    if(alpha == '*' || alpha =='/')
    {
        return(2);
    }
 
    if(alpha == '$')
    {
        return(3);
    }
 
    return 0;
}
string convert(string inx)
{
    int i=0;
    string postx = "";   
    while(inx[i]!='\0')
    {       
        if(inx[i]>='a' && inx[i]<='z'|| inx[i]>='A'&& inx[i]<='Z')          
        {
            postx.insert(postx.end(),inx[i]);
            i++;
        }       
        else if(inx[i]=='(' || inx[i]=='{'  || inx[i]=='[')
        {
            pus(inx[i]);
            i++;
        }        
        else if(inx[i]==')' || inx[i]=='}'  || inx[i]==']')
        {
            if(inx[i]==')')
            {
                while(stk[top]!='(')
                {               postx.insert(postx.end(),pop());
                }
                pop();
                i++;
            }
            if(inx[i]==']')
            {
                while(stk[top]!='[')
                {
                    postx.insert(postx.end(),pop());
                }
                pop();
                i++;
            }
 
            if(inx[i]=='}')
            {
                while(stk[top]!='{')
                {
                    postx.insert(postx.end(),pop());
                }
                pop();
                i++;
            }
        }
        else            
        {
            if(top==-1)
            {
                pus(inx[i]);
                i++;
            }
 
            else if( priority(inx[i]) <= priority(stk[top])) {
                postx.insert(postx.end(),pop());
               
                while(priority(stk[top]) == priority(inx[i])){
                    postx.insert(postx.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                pus(inx[i]);
                i++;
            }
            else if(priority(inx[i]) > priority(stk[top])) {
                pus(inx[i]);
                i++;
            }
        }
    }
    while(top!=-1)
    {
        postx.insert(postx.end(),pop());
    }
    cout<<"The converted postx string is : "<<postx; //it will print postx conversion  
    return postx;
}

int main()
{
    int cont;
    string inx, postx;
    cout<<"\nEnter the inx expression : "; //enter the expression
    cin>>inx;
    postx = convert(inx);
    return 0;
}

