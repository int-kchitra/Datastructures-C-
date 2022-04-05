#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class node{
  public:
    int data;
    node* next;
    node(int val){
    data=val;
    next=NULL;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////   INSERT END


  void insertatend( node* &head,int p){
     node* node1=new node(p);//created a new node and return its address to node1 of type node*
     if(head==NULL)
    	{
	head=node1;
        return;
	}

     else	{
        node* temp=head;
	while(temp->next!=NULL){
	  temp=temp->next;
 	 }
     temp->next=node1;
     }
  
     display(head);
 }

//////////////////////////////////////////////////////////////////////////////////////////////////////////   INSERT BEGIN

  void insertatbegin(node* &head,int p){
	node* node1=new node(p);
	if(head==NULL){
	    head=node1;
	    return;
	}
	else{
	     node* temp=head;
	     node1->next=head;
 	    head=node1;
        }
          display(head);
  }


//////////////////////////////////////////////////////////////////////////////////////////////////////////   INSERT AT ANY POSITION


  void insertany(node* &head,int p,int posi){
	node* node1=new node(p);	
	node* temp=head;
	for(int i=1;i<posi-1;i++)
	  {
	    temp=temp->next;
          }
       node1->next=temp->next;
       temp->next=node1;
     display(head);
  }

//////////////////////////////////////////////////////////////// ////////////////////////////////////////   DISPLAY


  void display(node* head){
	node* temp=head;
	if(temp==NULL){
	    cout<<"link list is empty";
	    return;
	}
	else{
 	    while(temp!=NULL)
           {
	      cout<<temp->data<<"->";
 	      temp=temp->next;
	     
	   }
	cout<<"NULL";
        }

  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////   deleteBEGIN

  void deletebegin(node* &head){
 	node* temp=head;
        head=head->next;
 	delete(temp);
        display(head);
  }


//////////////////////////////////////////////////////////////////////////////////////////////////////////   deleteBEGIN  

    void deleteend(node* &head){
   	node* temp=head;
   	node* temp1;
	while(temp->next->next!=NULL){
	temp=temp->next;
	}
  	delete(temp->next);
  	temp->next=NULL;
        display(head);
  
    }

///////////////////////////////////////////////////////////////////////////////////////////////////    delete AT any position

  void deleteanyposi(node* &head,int posi){
	if(posi==1){
	 deletebegin(head);
	 return;
	}
	else{
          node* temp=head;
	  node* temp1;
          for(int i=1;i<posi-1;i++){
	  temp=temp->next;
          }
  	temp->next=temp->next->next;
        } 
      display(head);
   }


///////////////////////////////////////////////////////////////////////////////////////////////////    SEARCH

   void search(node* &head,int p){
	node* temp=head;
	int flag=0;
	int i=0;
	while(temp!=NULL){
	i++;
	if(temp->data==p){
	   flag=1;
	   break;
	 }
	temp=temp->next;
       }
      if(flag==1){
	cout<<"element present at"<<i<<"th node"<<endl;
      }
      else{
       cout<<"element not found"<<endl;
     }
  }

///////////////////////////////////////////////////////////////////////////////////////////////    LENGTH

  void lengt(node* &head){
	int n=0;
	node* temp=head;
	while(temp!=NULL){
	  n++;
	  temp=temp->next;
	 }
	cout<<"length is"<<n<<endl;
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////   reverse

  void reverse(node* &head){
	node* current = head;
        node* prev = NULL; node* nex = NULL;
        while (current != NULL) 
	{
            nex = current->next;
            current->next = prev;
            prev = current;
            current = nex;
        }
        head = prev;
       display(head);
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////   sort

  void sort(node* &head){
	int n=0;
	node* temp1=head;
	while(temp1!=NULL)
       {
	  n++;
	  temp1=temp1->next;
	}
	//cout<<"length is"<<n;
	int count=1;
	node*temp=head;
	int p;
	while(count<n&&temp!=NULL)
	{
           if(temp->data>temp->next->data){
           p=temp->data;
           temp->data=temp->next->data;
           temp->next->data=p;
        } 
 	temp=temp->next;
 	count++;
      }
    display(head);
    }
  
};

int main()
{
	int c,f;
	node q(0);
	node* head;
	head=NULL;
	while(1){
	 cout<<endl<<"1.insert at end"<<endl;
	cout<<"2.insert at begin"<<endl;
	cout<<"3.insert @ any position other than end and begin"<<endl;
	cout<<"4.display "<<endl;
	cout<<"5.deletebegin"<<endl;
	cout<<"6.deleteend"<<endl;
	cout<<"7.delete any position"<<endl;
	cout<<"8.search"<<endl;
	cout<<"9.find length"<<endl;
	cout<<"10.reverse"<<endl;
        cout<<"11.sort"<<endl;
        cout<<"enter option"<<endl;
	cin>>c;
	int p;
	int posi;
	switch(c)
	{
  	case 1: cout<<"enter data";
     		cin>>p;
    		q.insertatend(head,p);
    		cout<<endl;
    		break;

	case 2: cout<<"enter data";
     		cin>>p;
    		q.insertatbegin(head,p);
     		cout<<endl;
  		break;

	case 3: cout<<"enter position";
     		cin>>posi;
     		cout<<"enter data";
    		cin>>p;
     		q.insertany(head,p,posi);
     		cout<<endl;
  		break;

        case 4: cout<<"ll is"<<endl;
 	      q.display(head);
              break;

        case 5: q.deletebegin(head);
             break;

        case 6: q.deleteend(head);
             break;

        case 7:  cout<<"enter position";
              cin>>posi;
              q.deleteanyposi(head,posi);
              break;

        case 8:  cout<<"enter element to be searched"<<endl;
                 cin>>p;
                q.search(head,p);
                break;

        case 9:  q.lengt(head);
                 break;

       case 10: q.reverse(head);
                break;

       case 11:  cout<<"sort"<<endl;
                 q.sort(head);
                 break;

      default:    exit(0);
                break;
  }
}
return 0;
  

}
