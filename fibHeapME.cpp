#include<bits/stdc++.h>
using namespace std;
struct Node
{
	bool mark;
	int val,degree;
	Node *left,*right,*parent,*child;
	Node(int x)
	{
		val=x;degree=0;mark=0;left=right=parent=child=0;
	}
};
class Heap{
public:
	int n;Node *minRoot;map<int,Node*> m;
	Heap(Node* x){
		x->right=x;x->left=x;
		minRoot=x;n=1;//n is wrong if more elements in x 
	}
	Heap(){
		n=0;minRoot=0;
	}
    	void Union(Heap h2)
    	{   
		n=n+h2.n;
		Node *min1=this->minRoot,*min2=h2.minRoot;
		if(!min1){minRoot=min2;return;}
		if(!min2){return;}
		Node *x=min1->left,*y=min2->left;
		x->right=min2; min2->left=x;
		y->right=min1; min1->left=y;
		min1->val<min2->val?minRoot=min1:minRoot=min2;
	}
    	void insert(int a)
    	{
		Node* x=new Node(a);
		m[a]=x;
		x->left=x;x->right=x;
		Heap h2(x);
		Union(h2);
    	}	
    void printHeap(Node* x)
    {
	if(!x)return;
	Node* it=x;
	do
	{
		cout<<it->val<<" ";
            	printHeap(it->child);
	    	it=it->right;
	}while(it!=x);
	//cout<<"\n";
    }
    void printRootList()
    {
        Node* x=minRoot;
        if(!x)return;
	Node* it=x;
	do{
		cout<<it->val<<" ";
	    	it=it->right;
	}while(it!=x);
	cout<<"\n";
    }
    Node* extract_min()
    {
        if(!minRoot){cout<<"ERROR:Heap is EMPTY\n";return 0;}
	Node* z=minRoot;
	Node* it=z->child;//just concatenate
	while(it!=0)
	{
		Node* next=DeleteRoot(it);n--;// a work-around
            	Heap h2(it);Union(h2);it->parent=0;
            	it=next;
	}
	minRoot=DeleteRoot(z);
	consolidate();n--;
        //m.erase(m.find(z->val));//keep every element distinct
        //it is undesirable and programme work
        //unepected if confronted with manipulative tests
        return z;
    }
    void consolidate()
    {
	Node* a[100];
	for(int i=0;i<100;i++)a[i]=0;
	Node* it=minRoot;
	while(it!=0)
	{
		Node* x=it;int d=x->degree;
            	it=minRoot=DeleteRoot(x);
            	while(a[d]!=0)
            	{
           		Node* y=a[d];
                	if(x->val>y->val)swap(x,y);
                	//cout<<"x="<<x->val<<" y="<<y->val<<endl;
                	Link(x,y);a[d]=0;d+=1;
            	}
            	a[d]=x;
            	//cout<<"d="<<d<<" x="<<x->val<<endl;
        }
        this->minRoot=NULL;
        for(int i=0;i<100;i++)
        {
            if(a[i])
            {
                Heap h2(a[i]);Union(h2);
            }
        }
    }
    void Link(Node* x,Node* y)
    {
        Node* temp=x->child;x->child=y;y->parent=x;
        if(temp){
            y->right=temp;y->left=temp->left;
            temp->left->right=y;temp->left=y;
        }
        else {y->right=y;y->left=y;}
        x->degree++;
        y->mark=false;
    }
    Node* DeleteRoot(Node* x)
    {
        if(x->right==x)return 0;
        else
        {
            x->left->right=x->right;x->right->left=x->left;
            return x->right;
        }
    }
    void decrease_key(Node* x,int k)
    {
        if(k>x->val)
        {
            cout<<"ERROR\n";
            return;
        }
        x->val=k;
        Node* y=x->parent;
        if(y&&x->val<y->val)
        {
            cut(x,y);
            cascading_cut(y);
        }
        if(x->val<minRoot->val)
        minRoot=x;
    }
    void cut(Node* x,Node* y)
    {
        Node* temp=DeleteRoot(x);
        y->child=temp;
        y->degree--;
        n--;//work_around
        Heap h2(x);Union(h2);
        x->parent=0;x->mark=false;
    }
    void cascading_cut(Node* y)
    {
        Node* z=y->parent;
        if(z)
        {
            if(!y->mark)
            {
                y->mark=true;
            }
            else 
            {
                cut(y,z);
                cascading_cut(z);
            }
        }
    }
    void Delete(Node* x)
    {
        if(!x)
        {
            cout<<"no such element\n";
            return;
        }
        decrease_key(x,INT_MIN);
        Node* z=extract_min();
    }
};
void print(Heap heap)
{
    cout<<"Heap is: ";
    if(!heap.minRoot)cout<<"EMPTY\n";
    else {heap.printHeap(heap.minRoot);cout<<"\n";}
}
int main()
{
    Heap heap;
    cout<<"1.insert 2.Extract_min 3.Decrease-key 4.Delete\n";
	while(1)
	{
		int x;
		cin>>x;
		switch(x)
		{
			case 1:
			{
				cout<<"enter no: ";
				int n;cin>>n;
				heap.insert(n);
				cout<<"Root list is: ";heap.printRootList();
				break;
			}
			case 2:
			{
                		Node* x=heap.extract_min();
                		if(x)cout<<"Min extracted is: "<<x->val<<endl;
                		print(heap);
				cout<<"Root list is: ";heap.printRootList();
				break;
			}
            		case 3:
            		{
                		int n,k;
                		cout<<"enter current and final value\n";
                		cin>>n>>k;
                		heap.decrease_key(heap.m[n],k);
                		print(heap);
                		cout<<"Root list is: ";heap.printRootList();
                		break;
            		}	
            		case 4:
            		{
                		int n;
                		cout<<"enter val to be deleted\n";
                		cin>>n;
                		heap.Delete(heap.m[n]);
                		print(heap);
                		cout<<"Root list is: ";heap.printRootList();
                		break;
            		}
			default:
			cout<<"nothing matched\n";
		}
	}
}

