#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    int degree;
    node* parent;
    node* sibling;
    node* child;
};

map<int,node*> mymap;

node* newNode(int x)
{
    node* temp = new node();
    temp->val = x;
    temp->degree =0;
    temp->parent = temp->sibling = temp->child = NULL;
    return temp;
}

void link(node** a,node** b)
{
    if((*a)->val>(*b)->val)
    {
        (*a)->parent = *b;
        (*a)->sibling = (*b)->child;
        (*b)->child = *a;
        (*b)->degree = (*b)->degree+1;
    }
    else
    {
        (*b)->parent = *a;
        (*b)->sibling = (*a)->child;
        (*a)->child = *b;
        (*a)->degree = (*a)->degree+1;
    }
}

node* Merge(node* root1,node* root2)
{
    if(root1==NULL)
        return root2;
    if(root2==NULL)
        return root1;
    node* head = NULL;
    node* ptr = head;
    while(root1!=NULL&&root2!=NULL)
    {
        if(root1->degree<=root2->degree)
        {
            if(head==NULL)
            {
                head = root1;
                ptr = root1;
            }
            else
            {
                ptr->sibling = root1;
                ptr = root1;
            }
            root1 = root1->sibling;
        }
        else{
            if(head==NULL)
            {
                head = root2;
                ptr = root2;
            }
            else
            {
                ptr->sibling = root2;
                ptr = root2;
            }
            root2 = root2->sibling;
        }
    }
    while(root1!=NULL)
    {
        ptr->sibling = root1;
        ptr = root1;
        root1 = root1->sibling;
    }
    while(root2!=NULL)
    {
        ptr->sibling = root2;
        ptr = root2;
        root2 = root2->sibling;
    }
    ptr->sibling = NULL;
    return head;
}

node* Union(node* root1,node* root2)
{
    node* head = Merge(root1,root2);
    node *prev=NULL,*nxt = head->sibling,*x = head;
    while(nxt!=NULL)
    {
        if(x->degree!=nxt->degree||(nxt->sibling!=NULL&&nxt->degree==nxt->sibling->degree))
        {
            prev = x;
            x = nxt;
        }
        else{
            if(x->val<=nxt->val)
            {
                x->sibling = nxt->sibling;
                link(&x,&nxt);
            }
            else
            {
                if(prev==NULL)
                    head = nxt;
                else
                    prev->sibling = nxt;
                    link(&x,&nxt);
                    x = nxt;
            }
        }
        nxt = x->sibling;
    }
    return head;
}

node* push(node* root,int x)
{
    if(root==NULL)
    {
        root = newNode(x);
        mymap[x] = root;
        return root;
    }
    node* newnode = newNode(x);
    mymap[x] = newnode;
    root = Union(newnode,root);
    return root;
}

node* getChild(node* root)
{
    if(root==NULL)
            return root;
    node* cur = root->child;
    node* prev = NULL;
    node* nxt;
    while(cur!=NULL)
    {
        nxt = cur->sibling;
        cur->parent = NULL;
        cur->sibling = prev;
        prev=cur;
        cur = nxt;
    }
    return prev;
}

node* Extract_Min(node** root)
{
    if(*root==NULL)
        return NULL;
    node *prev,*ptr,*mptr,*Min;
    ptr = *root;
    mptr = NULL;
    prev = NULL;
    Min = *root;
    while(ptr!=NULL)
    {
        if(ptr->val<Min->val)
        {
            mptr = prev;
            Min = ptr;
        }
        prev = ptr;
        ptr = ptr->sibling;
    }
    if(mptr==NULL)
    {
        *root = Min->sibling;
        Min->sibling = NULL;
    }
    else
    {
        mptr->sibling = Min->sibling;
        Min->sibling = NULL;
    }

    node* exRoot = getChild(Min);
    *root = Union(*root,exRoot);
    Min->child = NULL;
    mymap.erase(Min->val);
    return Min;
}

void exchange(node** c,node** p)
{
    node* temp = mymap[(*c)->val];
    mymap[(*c)->val]=mymap[(*p)->val];
    mymap[(*p)->val]=temp;

    int t = (*c)->val;
    (*c)->val = (*p)->val;
    (*p)->val = t;
}

node* decrease_key(node* root,int x,int k)
{
    if(k>x)
        return root;
    node* temp = mymap[x];
    mymap.erase(x);
    mymap[k] = temp;
    temp->val = k;
    node* p = temp->parent;
    bool flag=false;
    while(p!=NULL&&temp->val<p->val)
    {
        exchange(&temp,&p);
        temp = p;
        p = temp->parent;
        if(p==root&&temp->val<p->val)
        {
            flag = true;
        }
    }
    if(flag)
    {
        root = temp;
    }
    return root;
}

node* Delete(node* root,int x)
{
    node* ptr = mymap[x];
    if(ptr==NULL)
    {
        cout << "No node with given value exist\n";
        return root;
    }
    root = decrease_key(root,x,INT_MIN);
    ptr = Extract_Min(&root);
    return root;
}

void print(node* root)
{
    if(root==NULL)
        return;
    cout << root->val << " ";
    print(root->child);
    print(root->sibling);
}

int main()
{
    node* root = NULL;
    while(true){
    cout << "1. INSERT\n2. EXTRACT MIN\n3. DELETE\n4. DECREASE KEY\n5. PRINT\n";
    int option;
    cin >> option;
    if(option>5)
        break;
    if(option==1){
        int x;
        cout << "enter value ";
        cin >> x;
        root = push(root,x);
    }
    else if(option==2){
        node* m = Extract_Min(&root);
        if(m==NULL)
            cout<<"heap is empty"<<endl;
        else
            cout << m->val <<endl;
    }
    else if(option==3){
        int x;
        cout << "enter node to be deleted ";
        cin >> x;
        root = Delete(root,x);
    }
    else if(option==4){
        int x,y;
        cout << "enter node value whose value to decreased ";
        cin >> x;
        cout << "enter new value ";
        cin >> y;
        root = decrease_key(root,x,y);
    }
    else{
        print(root);
        cout << endl;
    }
    }
    return 0;
}
