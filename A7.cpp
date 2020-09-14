//============================================================================
// Name        : Assignment_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Symbol
{
	string name,type,value;
public :
	Symbol()
{
		name=type=value="\0";
}
	friend class SymbolTable;
};

class SymbolTable
{
	Symbol ST[50];
	int chain[50];
public :
	SymbolTable()
{
	for(int i=0;i<50;i++)
		chain[i]=-1;
}
	int hashfun(string key);
	void insertwr(string, string, string);
	int searchwr(string, int &);
	void modifywr(string);
	void deletewr(string);
	void insertwor(string, string, string);
	int searchwor(string, int &);
	void modifywor(string);
	void deletewor(string);
	void adjust(int);
	void display();
};

int SymbolTable :: hashfun(string key)
{
	int i=0,c=0;
	while(key[i]!='\0')
	{
		c=c+int(key[i]);
		i++;
	}
	return (c%50);
}

void SymbolTable :: insertwr(string n, string t, string v)
{
	int index,idx,temp;
	index=hashfun(n);
	temp=index;
	if(ST[index].name=="\0")
	{
		ST[index].name=n;
		ST[index].type=t;
		ST[index].value=v;
	}
	else
	{
		idx=hashfun(ST[index].name);
		if(idx!=index)
		{
			while(ST[temp].name!="\0")
				temp=(temp+1)%50;
			ST[temp].name=ST[index].name;
			ST[temp].type=ST[index].type;
			ST[temp].value=ST[index].value;
			chain[temp]=chain[index];
			ST[index].name=n;
			ST[index].type=t;
			ST[index].value=v;
			chain[index]=-1;
			while(chain[idx]!=index)
				idx=chain[idx];
			chain[idx]=temp;
		}
		else
		{
			while(ST[index].name!="\0")
				index=(index+1)%50;
			ST[index].name=n;
			ST[index].type=t;
			ST[index].value=v;
			if(chain[idx]==-1)
				chain[idx]=index;
			else
			{
				while(chain[idx]!=-1)
					idx=chain[idx];
				chain[idx]=index;
			}
		}
	}
	display();
}

int SymbolTable :: searchwr(string n, int &c)
{
	int index,idx,flag=0;
	index=hashfun(n);
	idx=hashfun(ST[index].name);
	if(idx!=index)
	{
		c++;
		return -1;
	}
	else if(ST[index].name==n)
	{
		c++;
		return index;
	}
	else
	{
		c++;
		while(chain[index]!=-1)
		{
			index=chain[index];
			c++;
			if(ST[index].name==n)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			return index;
		else
			return -1;
	}
}

void SymbolTable :: modifywr(string n)
{
	int index,c=0;
	string t,v;
	index=searchwr(n,c);
	if(index==-1)
		cout<<"The Name is not found\n";
	else
	{
		cout<<"Enter the new Type and Value\n";
		cin>>t>>v;
		ST[index].type=t;
		ST[index].value=v;
		cout<<"The Type and Value have been modified\n";
	}
	display();
}

void SymbolTable :: deletewr(string n)
{
	int c=0,loc,index,idx;
	loc=searchwr(n,c);
	if(loc==-1)
		cout<<"The Name is not found\n";
	else
	{
		index=hashfun(ST[loc].name);
		ST[loc].name=ST[loc].type=ST[loc].value="\0";
		if(loc==index)
		{
			if(chain[loc]!=-1)
			{
				idx=chain[loc];					//idx points to next element
				ST[loc].name=ST[idx].name;
				ST[loc].type=ST[idx].type;
				ST[loc].value=ST[idx].value;
				chain[loc]=chain[idx];
				ST[idx].name="\0";
				ST[idx].name="\0";
				ST[idx].name="\0";
				chain[idx]=-1;
			}
		}
		else
		{
			idx=index;							//idx points to previous element
			while(chain[idx]!=loc)
				idx=chain[idx];
			if(chain[loc]!=-1)
			{
				chain[idx]=chain[loc];
				chain[loc]=-1;
			}
			else
				chain[idx]=-1;
		}
		display();
	}
}

void SymbolTable :: insertwor(string n, string t, string v)
{
	int index,temp,idx;
	index=hashfun(n);
	temp=index;
	if(ST[index].name=="\0")
	{
		ST[index].name=n;
		ST[index].type=t;
		ST[index].value=v;
	}
	else
	{
		while(ST[temp].name!="\0")
			temp=(temp+1)%50;
		ST[temp].name=n;
		ST[temp].type=t;
		ST[temp].value=v;
		int i=index;
		while(i!=index-1)
		{
			idx=hashfun(ST[i].name);
			if(idx==index && i!=temp)
			{
				while(chain[i]!=-1)
					i=chain[i];
				chain[i]=temp;
				break;
			}
			i=(i+1)%50;
		}
	}
	display();
}

int SymbolTable :: searchwor(string n, int &c)
{
	int index,idx,flag=0;
	index=hashfun(n);
	if(ST[index].name==n)
	{
		c++;
		return index;
	}
	else
	{
		int i=index;
		while(i!=index-1)
		{
			idx=hashfun(ST[i].name);
			if(idx==index)
			{
				while(i!=-1)
				{
					c++;
					if(ST[i].name==n)
					{
						flag=1;
						break;
					}
					i=chain[i];
				}
				break;
			}
			c++;
			i=(i+1)%50;
		}
		if(flag==1)
			return i;
		else
			return -1;
	}
}

void SymbolTable :: modifywor(string n)
{
	int index,c=0;
	string t,v;
	index=searchwor(n,c);
	if(index==-1)
		cout<<"The Name is not found\n";
	else
	{
		cout<<"Enter the new Type and Value\n";
		cin>>t>>v;
		ST[index].type=t;
		ST[index].value=v;
		cout<<"The Type and Value have been modified\n";
	}
	display();
}

void SymbolTable :: deletewor(string n)
{
	int loc,index,idx,prev,c=0;
	loc=searchwor(n,c);
	if(loc==-1)
		cout<<"The Name is not found\n";
	else
	{
		index=hashfun(ST[loc].name);
		ST[loc].name=ST[loc].type=ST[loc].value="\0";
		if(loc==index)
		{
			if(chain[loc]!=-1)
			{
				idx=chain[loc];
				ST[loc].name=ST[idx].name;
				ST[loc].type=ST[idx].type;
				ST[loc].value=ST[idx].value;
				chain[loc]=chain[idx];
			    ST[idx].name="\0";
			    ST[idx].type="\0";
			    ST[idx].value="\0";
			    chain[idx]=-1;
			}
		}
		else
		{
			int i=index;
			while(i!=index-1)
			{
				idx=hashfun(ST[i].name);
				if(idx==index && i!=loc)
				{
					prev=i;
					while(chain[prev]!=loc && chain[prev]!=-1)
						prev=chain[prev];
					if(chain[prev]!=-1)
					{
						if(chain[loc]!=-1)
						{
							chain[prev]=chain[loc];
							chain[loc]=-1;
						}
						else
							chain[prev]=-1;
						break;
					}
				}
				i=(i+1)%50;
			}
		}
		cout<<"The Name has been deleted\n";
		while(ST[loc].name!="\0")
			loc=(loc+1)%50;
		adjust(loc);
	}
	display();
}

void SymbolTable :: adjust(int loc)
{
	int idx,i,j;
	i=loc;
	j=(i+1)%50;
	while(j!=loc-1)
	{
		idx=hashfun(ST[j].name);
		if(idx==i)
		{
			ST[i].name=ST[j].name;
			ST[i].type=ST[j].type;
			ST[i].value=ST[j].value;
			chain[i]=chain[j];
			ST[j].name="\0";
			ST[j].type="\0";
	        ST[j].value="\0";
			chain[j]=-1;	
			i=j;		
		}
		j=(j+1)%50;
	}
}

void SymbolTable :: display()
{
	cout<<"\nIndex\tName\tType\tValue\tChain\n";
	for(int i=0;i<50;i++)
	{
		if(ST[i].name!="\0")
			cout<<i<<"\t"<<ST[i].name<<"\t"<<ST[i].type<<"\t"<<ST[i].value<<"\t"<<chain[i]<<"\n";
	}
	cout<<endl;
}

int main()
{
	SymbolTable s;
	int c,c1,cnt=0,p;
	string n,t,v;
	do
	{
		cout<<"Enter your choice\n1. Without Replacement\n2. With Replacement\n0. Exit\n";
		cin>>c;
		switch(c)
		{
		case 1 : do
		         {
			     	 cout<<"\nSelect for Without Replacement\n1. Insert\n2. Search\n3. Modify\n4. Delete\n0. Main Menu\n";
			     	 cin>>c1;
			     	 switch(c1)
			     	 {
			     	 case 1 : cout<<"Enter the Name\n";
			     	 	 	  cin>>n;
			     	 	 	  cout<<"Enter the Type\n";
			     	 	 	  cin>>t;
			     	 	 	  cout<<"Enter the Value\n";
			     	 	 	  cin>>v;
			     	 	 	  s.insertwor(n,t,v);
			     	 	 	  break;
			     	 case 2 : cout<<"Enter the Name\n";
	 	 	 	 	  	  	  cin>>n;
	 	 	 	 	  	  	  cnt=0;
	 	 	 	 	  	  	  p=s.searchwor(n,cnt);
	 	 	 	 	  	  	  if(p==-1)
	 	 	 	 	  	  		  cout<<"The Name is not found\n";
	 	 	 	 	  	  	  else
	 	 	 	 	  	  	  {
	 	 	 	 	  	  		  cout<<"The Name is found\n";
	 	 	 	 	  	  		  cout<<"The number of collisions is "<<cnt<<"\n";
	 	 	 	 	  	  	  }
	 	 	 	 	  	  	  break;
			     	case 3 : cout<<"Enter the Name\n";
			     		     cin>>n;
			     		     s.modifywor(n);
			     		     break;
			     	case 4 : cout<<"Enter the Name\n";
	     	 	 	 	 	 cin>>n;
	     	 	 	 	 	 s.deletewor(n);
	     	 	 	 	 	 break;
			        case 0 : break;
			     	default : cout<<"Invalid Choice\n";
			     	}
		         }while(c1!=0);
			     break;
		case 2 : do
        		 {
	     	 	 	 cout<<"\nSelect for With Replacement\n1. Insert\n2. Search\n3. Modify\n4. Delete\n0. Main Menu\n";
	     	 	 	 cin>>c1;
	     	 	 	 switch(c1)
	     	 	 	 {
	     	 	 	 case 1 : cout<<"Enter the Name\n";
	     	 	 	  	  	  cin>>n;
	     	 	 	  	  	  cout<<"Enter the Type\n";
	     	 	 	  	  	  cin>>t;
	     	 	 	  	  	  cout<<"Enter the Value\n";
	     	 	 	  	  	  cin>>v;
	     	 	 	  	  	  s.insertwr(n,t,v);
	     	 	 	  	  	  break;
	     	 	 	 case 2 : cout<<"Enter the Name\n";
	     	 	 	 	 	  cin>>n;
	     	 	 	 	 	  cnt=0;
	     	 	 	 	 	  p=s.searchwr(n,cnt);
	     	 	 	 	 	  if(p==-1)
	     	 	 	 	 		  cout<<"The Name is not found\n";
	     	 	 	 	 	  else
	     	 	 	 	 	  {
	     	 	 	 	 		  cout<<"The Name is found\n";
	     	 	 	 	 		  cout<<"The number of collisions is "<<cnt<<"\n";
	     	 	 	 	 	  }
	     	 	 	 	 	  break;
	     	 	 	 case 3 : cout<<"Enter the Name\n";
	     	 	 	 	 	  cin>>n;
	     	 	 	 	 	  s.modifywr(n);
	     	 	 	 	 	  break;
	     	 	 	 case 4 : cout<<"Enter the Name\n";
	     	 	 	 	 	  cin>>n;
	     	 	 	 	 	  s.deletewr(n);
	     	 	 	 	 	  break;
	     	 	 	 case 0 : break;
	     	 	 	 default : cout<<"Invalid Choice\n";
	     	 	 	 }
        		 }while(c1!=0);
	     	 	 break;
		case 0 : break;
		default : cout<<"Invalid choice\n";
		}
	}while(c!=0);
	return 0;
}
