#include<iostream>
using namespace std;

class node
{
    public:
    string keyword;
    string meaning;
    node * left;
    node * right;
};

class avl
{
    node * root;
    public:
    avl()
    {
        root=NULL;
    }

    void create();
    node *insert(node *curr,node *temp);
    node *balance(node *temp);
    int diff(node *temp);
    int height(node *temp);
    node *LL(node *p);
    node *LR(node *p);
    node *RR(node *p);
    node *RL(node *p);
    void ascending(node *temp);
    void display();
    bool search(node *curr,string key);
    void searche();
    node *deleten(node *root,string key);
    node * min(node *temp);
    void deletee();
};

void avl::create()
{
    node *temp;
    char c;
    do
    {
        temp=new node();
        cout<<"enter keyword:";
        cin>>temp->keyword;
        cout<<"enter its meaning:";
        cin>>temp->meaning;
        temp->left=NULL;
        temp->right=NULL;

        root=insert(root,temp);
        cout<<"do you want to add more(y||Y):";
        cin>>c;
    } while (c=='y'|| c=='Y');
    
}

node * avl::insert(node *curr,node *temp)
{
   if(curr==NULL)
   {
     return temp;          //it means if root node is null then make temp as a root node
   }
   
   if(temp->keyword<curr->keyword)
   {
    curr->left=insert(curr->left,temp);
    curr=balance(curr);
   }
   else if(temp->keyword>curr->keyword)
   {
    curr->right=insert(curr->right,temp);
    curr=balance(curr);
   }
   return curr;
}

node *avl::balance(node * temp)
{
    int bal=diff(temp);

    if(bal>=2)
    {
        if(diff(temp->left)<0)
        {
            temp=LR(temp);
        }
        temp=LL(temp);
    }

    else if(bal<=2)
    {
        if(diff(temp->right)<0)
        {
            temp=RR(temp);
        }
        temp=RL(temp);
    }
        return temp;
    
}

int avl::diff(node * temp)
{
   int l=height(temp->left);
   int r=height(temp->right);
   return (l-r);
}

int avl::height(node * temp)
{
    if(temp==NULL)
    {
        return -1;
    }
    else
    {
        return (max(height(temp->left),height(temp->right))+1);
    }
}

node * avl::LL(node *p)
{
    node *temp,*temp1;
    temp=p->left;
    temp1=temp->right;

    temp->right=p;
    p->left=temp1;
    return temp;
}

node *avl::RR(node *p)
{
    node *temp,*temp1;
    temp=p->right;
    temp1=temp->left;

    temp->left=p;
    p->right=temp1;
    return temp;
}

node *avl::LR(node *p)
{
    p->left=RR(p->left);
    return LL(p);
}

node *avl::RL(node *p)
{
    p->right=LL(p->right);
    return RR(p);
}

void avl::ascending(node *temp)
{
    if(temp!=NULL)
    {
        ascending(temp->left);
        cout<<temp->keyword<<"-"<<temp->meaning<<endl;
        ascending(temp->right);
    }
}

void avl::display()
{
   cout<<"keywords in ascending order:"<<endl;
   ascending(root);
}

bool avl::search(node *curr,string key)
{
   if(curr)
   {
    if(curr->keyword==key)
       return true;

    else if(curr->keyword>key)
    return search(curr->left,key);
    
    else if(curr->keyword<key)
    return search(curr->right,key);
    
   }
   return false;
}

void avl::searche()
{
    string key;
    cout<<"enter a keyword which you want to search:";
    cin>>key;
    if(search(root,key))
    {
        cout<<"key found";
    }
    else{
       cout<<"key not found";
    }
}

node *avl::deleten(node *root,string key)
{
     if (!root)
        return NULL;
    if (key < root->keyword)
    {
        root->left = deleten(root->left, key);
    }
    else if (key > root->keyword)
    {
        root->right = deleten(root->right, key);
    }

    else if(key==root->keyword)
    {
        node *l=root->left;
        node *r=root->right;
        delete root;

        if(!r)
        {
            return l;
        }

        node * m=r;

        while (m->left==0)
        m=m->left;
        m->right=min(r);
        m->left=l;
        return balance(m);
    }
    return balance(root);
}
node *avl::min(node *t)
{
   if(!t->left)
   return t->right;

   t->left=min(t->left);
   return balance(t);
}


void avl::deletee()
{ 
    string key;
    cout<<"enter a keyword to delete:";
    cin>>key;
    deleten(root,key);
}

int main()
{
    char c;
    int ch;
    avl a;

    do
    {
       cout<<"1.insert"<<endl;
       cout<<"2.display"<<endl;
       cout<<"3.search"<<endl;
       cout<<"4.delete"<<endl;
       cout<<"enter your choice:";
       cin>>ch;

       switch(ch)
       {
        case 1: a.create();
                break;
        case 2: a.display();
                break;
        case 3: a.searche();
                break;
        case 4: a.deletee();
                break;
       }

       cout<<"do you want to continue:";
       cin>>c;
    } while (c=='y'||c=='Y');
    
}
