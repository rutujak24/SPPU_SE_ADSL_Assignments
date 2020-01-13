//============================================================================
// Name        : TBT3.cpp
// Author      : Rutuja Kawade
// Version     :
// Copyright   : Your copyright notice
// Description : TBST
//============================================================================

#include <iostream>
using namespace std;

class Node{
	int lbit, rbit;
	int value;
	Node *lc, *rc;
public:
	Node(){
		lbit=rbit=0;
		value=0;
		lc=rc=NULL;
	}
	friend class TBT;
};
class TBT{
	Node *root;
public:
	TBT(){
		root=new Node();
		root->value=9999;
		root->rbit=1;
		root->lbit=0;
		root->lc=root;
		root->rc=root;
	}
	void create();
	void insert(int value);
	void preorder();
	Node *preorder_suc(Node *);
	void inorder();
	Node *inorder_suc(Node *);

};
void TBT::create(){
	int n,x;
	cout<<"Enter the no.of values to be inserted\n";
	cin>>n;
	for(int i=0; i<n;i++){
		cout<<"Enter the value to be inserted\n";
		cin>>x;
		this->insert (x);
	}
}
void TBT::insert(int data)
{

	if(root->lc==root&&root->rc==root) //no Node in tree
	{
		Node *p=new Node();
		p->value=data;
		p->lc=root->lc;
		p->lbit=root->lbit; //0
		p->rbit=0;
		p->rc=root->rc;
		root->lc=p;
		root->lbit=1;
		cout<<"Data Inserted at start"<<data<<endl;
		return;
	}
	Node *cur=new Node;
	cur=root->lc;
	while(1)
	{

		if(cur->value<data)   //insert rc
		{
			Node *p=new Node();
			p->value=data;
			if(cur->rbit==0)
			{
				p->rc=cur->rc;
				p->rbit=cur->rbit;
				p->lbit=0;
				p->lc=cur;
				cur->rbit=1;
				cur->rc=p;
				cout<<"Data Inserted to the rc of "<<cur->value<<endl;
				return;
			}
			else
				cur=cur->rc;
		}
		if(cur->value>data)   //insert lc
		{
			Node *p=new Node();
			p->value=data;
			if(cur->lbit==0)
			{
				p->lc=cur->lc;
				p->lbit=cur->lbit;
				p->rbit=0;
				p->rc=cur; //successor
				cur->lbit=1;
				cur->lc=p;
				cout<<"Data Inserted to the lc of "<<cur->value<<endl;
				return;
			}
			else
				cur=cur->lc;
		}
	}

}
void TBT::preorder()
{
	Node *c=root->lc;
	while(c!=root)
	{
		cout<<" "<<c->value;
		c=preorder_suc(c);
	}
}
Node *TBT::preorder_suc(Node *c)
{
	if(c->lbit==1)
	{
		return c->lc;
	}
	while(c->rbit==0)
	{
		c=c->rc;
	}
	return c->rc;
}
void TBT::inorder()
{
	Node *c ;
	c=root->lc;
	while(c->lbit==1)
		c=c->lc;
	while(c!=root)
	{
		cout<<" "<<c->value;
		c=inorder_suc(c);
	}
}
Node* TBT::inorder_suc(Node *c)
{
	if(c->rbit==0)
		return c->rc;
	else
		c=c->rc;
	while(c->lbit==1)
	{
		c=c->lc;
	}
	return c;
}
int main() {
	TBT t1;
	t1.create();

	return 0;
}
