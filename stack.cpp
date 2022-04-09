#include<iostream>
using namespace std;
#define n 100

class stack{
char* arr;
int top;
public:
stack() {
arr= new int[n];
top=-1;
}
 
void push(s x)

{
if(top==n-1)
{
cout<<"stack is full";
}
else
 top++;
arr[top]=x;
}

void pop()

{
if(top==-1)
cout<<"stack underflow";
else{
cout<<arr[top]<<endl;
top--;
}
}
};

int main(){
stack st;
st.push("soumya");
/*st.push(13);
st.push(33);
st.push(36);
st.pop();
st.pop();
*/
st.pop();
return 0;
}
