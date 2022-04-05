#include<iostream>
#include<queue>
using namespace std;

class node{
  public:
   int data;
   node* left;
   node* right;
   node(int value){
    data=value;
    left=NULL;
    right=NULL;
   }
 node* inorsuc(node* root){
node* curr=root;
 while(curr&&curr->left!=NULL){
 curr=curr->left;
}
return curr;
}

/////////////////////////////////////////////////////////////////////////// BST INSERTION
   node* insert(node* &root,int n){
  
     if(root==NULL){
      return new node(n);
     }
 
     if(root->data==n){
     return root;
     }

     if(n<root->data){
      root->left=insert(root->left,n); 
     }
     else{
       root->right=insert(root->right,n);
      }
     return root;
   }

/////////////////////////////////////////////////////////////////////////// BST INORDER
  void inorder(node* &root)
  { 
     if(root==NULL){
      return ;
     }
    else{
    
     inorder(root->left);
     cout<<root->data;
     cout<<endl;
    inorder(root->right);
     }
   }

/////////////////////////////////////////////////////////////////////////// BST PREORDER
 void preorder(node* &root)
 {
   if(root==NULL){
  return;
  }
  else
   {
    cout<<root->data;cout<<endl;
    preorder(root->left);
    preorder(root->right);
  }
  }

/////////////////////////////////////////////////////////////////////////BST POSTORDER

void postorder(node* root){
 if(root==NULL){
 return;
 }
 else{
    preorder(root->left);
    preorder(root->right);
   cout<<root->data;cout<<endl;
    
  }
}  

////////////////////////////////////////////////////////////////////////////////BST SEARCH

node* search(node* root,int n){
  if(root==NULL)
{
  return NULL;
  }
if(root->data==n){
   return root;
 }
if(root->data<n){
   return search(root->right,n);
 }
else{
return search(root->left,n);
 }
}

/////////////////////////////////////////////////////////////////////////// BST BFS

void bfs(node* root){
queue <node* >q;
 q.push(root);
 while(q.empty()==false){
   node* temp;
  temp=q.front();
   cout<<temp->data;   cout<<endl;
   q.pop();
   if(temp->left!=NULL){ q.push(temp->left);}  
   if(temp->right!=NULL){q.push(temp->right);}
 }
 
}

/////////////////////////////////////////////////////////////////////////// BST DFS

void dfs(node* root){
if(root==NULL){
 return ;
}
 cout<<root->data<<endl;
 dfs(root->left);
 dfs(root->right);
}


/////////////////////////////////////////////////////////////////////////// BST HEIGHT

int calcheight(node* root){
if(root==NULL){
return 0;
}
int het=calcheight(root->left);
int het1=calcheight(root->right);

int p=max(het,het1);
p=p+1;
return p;
}

/////////////////////////////////////////////////////////////////////////// BST DELETION

node* del(node* root,int key){
 if(root==NULL){
 return NULL;
 }
 if(key<root->data){
   root->left=del(root->left,key);
  }
else if(key>root->data){
   root->right=del(root->right,key);
  }
//root need to delete fin inorder pred
else{

    if(root->left==NULL){
     node* temp=root->right;
     free(root);
      return temp;
    }
     else if(root->right==NULL){
     node* temp=root->left;
     free(root);
      return temp;
   }
 node* temp=inorsuc(root->right);
   root->data=temp->data;
   root->right=del(root->right,temp->data);
 }
return root;
}

/////////////////////////////////////////////////////////////////////////// BST NUMBER OF LEAVES

int leaf(node* root){
int n; 
if(root==NULL){
//cout<<"leaf=0";
return 0;
}
if(root->right==NULL&&root->left==NULL){
return 1;
}
else
{

n=leaf(root->left)+leaf(root->right);
}
return n;
}
};
int main()
{
 node t(0);
  node* root=NULL;
int c,n,u;
while(1){
cout<<"1.insert";cout<<endl;
cout<<"2.inorder";cout<<endl;
cout<<"3.preorder";cout<<endl;
cout<<"4.postorder";cout<<endl;
cout<<"5.bfs";cout<<endl;
cout<<"6.dfs";cout<<endl;
cout<<"7.search";cout<<endl;
cout<<"8.height"<<endl;
cout<<"9.delete"<<endl;
cout<<"10.leaf nodes"<<endl;
cout<<"enter option";cout<<endl;
cin>>c;
switch(c)
  {
   case 1:cout<<"enter element to be inserted";
          cin>>n;
         root=t.insert(root,n);
          
         cout<<endl;
          break;
   case 2:cout<<"inorder";
          t.inorder(root);
          cout<<endl;
           break;
  case 3:cout<<"preorder";
          t.preorder(root);
          cout<<endl;
           break;
    case 4:cout<<"postorder";
          t.postorder(root);
          cout<<endl;
           break;
case 5:cout<<"bfs";   cout<<endl;
       t.bfs(root);
       break;
case 6:cout<<"dfs"<<endl;
       t.dfs(root);
       break;
 case 7:cout<<"enter the elment to be searched";
        cin>>n;
       if( t.search(root,n)==NULL)
        {cout<<"no element";
         }
       else{cout<<"found";}
            break;
case 8:cout<<"height";
       u=t.calcheight(root);
       cout<<u;
       break;
case 9:cout<<"delete";
       cout<<"key gto delete";
        int key;
       cin>>key;
       root=t.del(root,key);
       break;
case 10:cout<<"leaf";
       int lef; 
       lef=t.leaf(root);
       cout<<lef;
       break;
   default:exit(0);
}
}
return 0;
}
