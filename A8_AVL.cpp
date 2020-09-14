

#include <bits/stdc++.h>
using namespace std;
class node{
	string key,meaning;
	node *left,*right;
public:
	node(string x,string y)
{
		key=x;
		meaning=y;
		left=right=NULL;
}
	friend class AVL;
};
class AVL{
	node* root;
public:
	AVL()
{
		root=NULL;
}
	void create();
	node* insert(node* t,string x,string y);
	int height(node* t);
	int balance(node* t);
	node* Leftrotate(node* t);
	node* Rightrotate(node* t);
	node* LR(node* t);
	node* RL(node* t);
	void display();
	void inorder(node* t);
	void insertnode();
	void update();
	void updaterec(node* t,string s,string s1);
	void deletenode();
	node* deleterec(node* t,string s);
	node* findmin(node* t);
	node* checkrotate(node* t);
};
void AVL::create()
{
	string s,s1;
	while(1)
	{
		cout<<"Enter key or -1 to stop: ";
		cin>>s;
		if(s=="-1")
			break;
		transform(s.begin(),s.end(),s.begin(),::toupper);
		cout<<"Enter meaning:";
		cin>>s1;
		transform(s1.begin(),s1.end(),s1.begin(),::toupper);
		root=insert(root,s,s1);
	}
}
node* AVL::insert(node* t,string s,string s1)
{
	if(t==NULL)
	{
		t=new node(s,s1);
		return t;
	}
	if(t->key>s)
	{
		t->left=insert(t->left,s,s1);
		t=checkrotate(t);
		return t;
	}
	else if(t->key<s)
	{
		t->right=insert(t->right,s,s1);
		t=checkrotate(t);
		return t;
	}
	else
	{
		cout<<"Cannot insert\n";
		return t;
	}
}
int AVL::height(node* t)
{
	if(t==NULL)
	{
		return 0;
	}
	int lh=0,hr=0;
	lh=height(t->left);
	hr=height(t->right);
	if(lh>hr)
		return 1+lh;
	else
		return 1+hr;
}
int AVL::balance(node* t){
	int lh=0,hr=0;
	if(t==NULL)
		return 0;
	lh=height(t->left);
	hr=height(t->right);
	return (lh-hr);
}
node* AVL::Rightrotate(node* t)
{
	node* p=t->left;
	t->left=p->right;
	p->right=t;
	return p;
}
node* AVL::Leftrotate(node* t)
{
	node* p=t->right;
	t->right=p->left;
	p->left=t;
	return p;
}
node* AVL::LR(node* t)
{
	t->left=Leftrotate(t->left);
	t=Rightrotate(t);
	return t;
}
node* AVL::RL(node* t)
{
	t->right=Rightrotate(t->right);
	t=Leftrotate(t);
	return t;
}
node* AVL::checkrotate(node* t)
{
	if(balance(t)==2)
	{
		if(balance(t->left)==1||balance(t->left)==0)
			t=Rightrotate(t);
		else
			t=LR(t);
	}
	if(balance(t)==-2)
	{
		if(balance(t->right)==-1||balance(t->right)==0)
		{
			t=Leftrotate(t);
		}
		else
			t=RL(t);
	}
	return t;
}
void AVL::display()
{
	inorder(root);
}
void AVL::inorder(node* t)
{
	if(t)
	{
		inorder(t->left);
		cout<<t->key<<" "<<t->meaning<<endl;
		cout<<"Balance Factor: "<<balance(t)<<"\tHeight: "<<height(t)<<endl;
		inorder(t->right);
	}
}
void AVL::insertnode()
{
	string s,s1;
	cout<<"Enter key to insert:";
	cin>>s;
	cout<<"Enter meaning:";
	cin>>s1;
	transform(s1.begin(),s1.end(),s1.begin(),::toupper);
	transform(s.begin(),s.end(),s.begin(),::toupper);
	root=insert(root,s,s1);
}
void AVL::update()
{
	string s,s1;
	cout<<"Enter key to update:";
	cin>>s;
	transform(s.begin(),s.end(),s.begin(),::toupper);
	cout<<"Enter new meaning:";
	cin>>s1;
	transform(s1.begin(),s1.end(),s1.begin(),::toupper);
	updaterec(root,s,s1);
}
void AVL::updaterec(node* t,string s,string s1)
{
	if(t==NULL)
		return;
	if(t->key>s)
	{
		updaterec(t->left,s,s1);
	}
	else if(t->key<s)
	{
		updaterec(t->right,s,s1);
	}
	cout<<"Key found "<<s<<endl;
	t->meaning=s1;
	return;
}
void AVL::deletenode()
{
	string s;
	cout<<"Enter key to delete\n";
	cin>>s;
	transform(s.begin(),s.end(),s.begin(),::toupper);
	root=deleterec(root,s);
}
node* AVL::findmin(node* t)
{
	while(t->left!=NULL)
		t=t->left;
	return t;
}
node* AVL::deleterec(node* t,string s)
{
	if(t==NULL)
	{
		cout<<"Key not present\n";
		return NULL;
	}
	if(t->key>s)
	{
		t->left=deleterec(t->left,s);
		t=checkrotate(t);
		return t;
	}
	else if(t->key<s)
	{
		t->right=deleterec(t->right,s);
		t=checkrotate(t);
		return t;
	}
	if(t->right==NULL&&t->left==NULL)
	{
		delete t;
		return NULL;
	}
	if(t->right==NULL)
	{
		node* p=t->left;
		delete t;
		return p;
	}
	if(t->left==NULL)
	{
		node* p=t->right;
		delete t;
		return p;
	}
	node* p=findmin(t->right);
	t->key=p->key;
	t->meaning=p->meaning;
	t->right=deleterec(t->right,p->key);
	t=checkrotate(t);
	return t;
}
int main() {
	AVL a;
	int choice;
	do{
		cout<<"Menu\n1.Create\n2.Insert\n3.Delete\n4.Update\n5.Display\n";
		cin>>choice;
		switch(choice){
		case 1:
			a.create();
			break;
		case 2:
			a.insertnode();
			break;
		case 3:
			a.deletenode();
			break;
		case 4:
			a.update();
			break;
		case 5:
			a.display();
			break;
		}
	}while(choice!=0);
	return 0;
}

