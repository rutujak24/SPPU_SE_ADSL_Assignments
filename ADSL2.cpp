//============================================================================
// Name        : Assignment2.cpp
// Author      : Rutuja Kawade
// Version     :
// Copyright   : Your copyright notice
// Description : BST
//============================================================================
/*A Dictionary stores keywords & its meanings. Provide facility for adding new
keywords, deleting keywords, updating values of any entry, assign a given tree
into another tree (=). Provide facility to display whole data sorted in ascending/
Descending order. Also find how many maximum comparisons may require for
finding any keyword. Use Binary Search Tree for implementation.*/


#include <iostream>
using namespace std;
#include <string.h>

int count=0;

class Bst;
class Entry{
	char key[20];
	char mean[100];
	Entry *lc;
	Entry *rc;
public:
	Entry(){

		lc=rc=NULL;
	}
	Entry(char *key, char *mean){
		strcpy(this->key,key);
		strcpy(this->mean,mean);
		lc=rc=NULL;
		}
	friend class Bst;
};

class Bst{
	Entry *root;
public:
	void create();
	void asc(Entry *);
	void des(Entry *);
	void search(Entry *t,char*);
	void searchd(char *);
    void delete_node(Entry *, Entry *);
	Bst(){
		root=NULL;
	}
	Entry * getRoot(){
	   return root;
	}
};
void Bst::searchd(char * t){
	Entry *p, *q;
	p=root;
	q=NULL;
	int found=0;
	int n;

	while(p!=NULL && found==0){
		n=strcmp(p->key,t);
		if(n==0){
			found=1;
			cout<<"gkj";
			delete_node(q,p);
		}
		else if(n<0){
			q=p;
			p=p->rc;
		}
		else{
			q=p;
			p=p->lc;
		}
	}
}
void Bst::delete_node(Entry *p,Entry *c){
	if(c!=NULL && c->lc!=NULL && c->rc!=NULL){
		p=c;
		Entry *cs=c->rc;
		while(cs->lc!=NULL){
			p=cs;
			cs=cs->lc;
			strcpy(c->key,cs->key);
			c=cs;
		}
	}
	if(c!=NULL && c->lc!=NULL && c->rc==NULL){
		if(c==p->lc){
			p->lc=c->lc;
			cout<<c->key<<" deleted\n";
			//p->lc=NULL;
			delete c;
		}
		if(c==p->rc){
			p->rc=c->lc;
			cout<<c<<" deleted\n";
			//p->rc=NULL;
			delete c;
		}
	}
	if(c!=NULL && c->rc!=NULL && c->lc!=NULL){
			if(c==p->lc){
				p->lc=c->rc;
				cout<<c<<" deleted\n";
				//p->lc=NULL;
				delete c;
			}
			if(c==p->rc){
				p->rc=c->rc;
				cout<<c<<" deleted\n";
				//p->rc=NULL;
				delete c;
			}
		}
	if(c!=NULL && c->rc==NULL && c->lc==NULL){
		if(p->rc==c)
			p->rc=NULL;
		if(p->lc==c)
			p->lc=NULL;
		cout<<c->key<<" deleted\n";
		delete c;
	}

}
void Bst::search(Entry *t,char*word){
	count=count+1;
	int n=5;
	if(t!=NULL){
	n= strcmp(t->key,word);
	if(n>0){
		search(t->lc,word);
	}
	else if(n<0){
		search(t->rc,word);
	}
	else{
		if(n==0)
		cout<<"Word found\n";
		cout<<t->key<<" : "<<t->mean<<endl;
		cout<<"No of comparisons required are "<<count<<endl;
	}
	}
	else
		cout<<"Word Not found\n";
}
void Bst:: create(){
	Entry *curr=NULL;
	Entry *par=NULL;
	int c=0;
Entry *n= new Entry;
cout<<"Enter the word \n";
cin>>n->key;
cout<<"Enter its meaning\n";
cin>>n->mean;
if(root==NULL){
	root=n;
	return;
}
else
{
curr=root;
while(1){
	par=curr;
	c=strcmp(curr->key,n->key);
	if(c>0){
		curr=curr->lc;
		if(curr==NULL){
			par->lc=n;
			return;
		}
	}
	if(c<0){
			//par=curr;
			curr=curr->rc;
			if(curr==NULL){
				par->rc=n;
				return;
			}

		}
	if(c==0)
	{
		cout<<"SAME KEYWORD\n";
		break;
	}

	}
}
}
void Bst::asc(Entry *t){
	if(t!=NULL){
		asc(t->lc);
		cout<<t->key<<" : "<<t->mean<<endl;
		asc(t->rc);

	}
}
void Bst::des(Entry *t){
	if(t!=NULL){
		des(t->rc);
		cout<<t->key<<" : "<<t->mean<<endl;
		des(t->lc);

	}
}

int main() {
	Bst b1;
	int n, choice;
	Entry *t;
	char word[20], w[20];
	do{
	cout<<"Enter the operation\n1.Insert\n2.Ascending\n3.Descending\n4.Search\n5.Delete\n0.Exit\n";
	cin>>choice;
	switch(choice){
	case 1:{
	cout<<"Enter no of keywords you want to insert\n";

	cin>>n;
	for(int i=0;i<n;i++){
	b1.create();
	}
	break;
	}
	case 2:{
	t=b1.getRoot();
	cout<<"Ascending order of Alphabets\n";
	b1.asc(t);
	break;
	}
	case 3:{
		t=b1.getRoot();
	cout<<"Descending order of Alphabets\n";
	b1.des(t);
	break;
	}
	case 4:{
		cout<<"Enter the Keyword to be searched\n";
		cin>>word;
	b1.search(t,word);
	break;
	}
	case 5:{
		cout<<"Enter the keyword to be deleted\n";
		cin>>w;
		b1.searchd(w);
		cout<<"\n After deletion\n";
		t=b1.getRoot();
		b1.asc(t);
		break;
	}
	}
	}while(choice!=0);
	return 0;
}
