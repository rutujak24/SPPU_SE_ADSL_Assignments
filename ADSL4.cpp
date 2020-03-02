//============================================================================
// Name        : assignment4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*There are flight paths between cities. If there is a flight between city A and city B 
then there is an edge between the cities. The cost of the edge can be the time that 
flight takes to reach city B from A, or the amount of fuel used for the journey. 
Represent this as a graph. The node can be represented by airport name or name 
of the city. Use adjacency list representation of the graph. (Operation to be 
performed adding and deleting edge, adding and deleting vertices, calculated indegree and 
out-degree for directed graph. Use any traversal to traverse graph)*/


#include <iostream>
using namespace std;

class node
{
	string dest;
	int cost;
	node* next;
public:
	node()
	{
		cost = 0;
		next = NULL;
	}
	node(string d,int c)
	{
		dest = d;
		cost = c;
		next = NULL;
	}
	friend class Graph;
	friend class queue;
	friend class stack;
};
class stack
{
	int arr[50] ;
	int top;
public:
	stack()
	{
		top = -1;
		for(int i=0; i<50;i++){
			arr[i]=0;
		}
	}
	void push(int i);
	void pop();
	int givetop();
	bool isempty();
};
void stack :: push(int i)
{
	if(top == 49)
	{
		cout<<"ERROR! STACK OVERFLOW"<<endl;
		return;
	}
	arr[++top] = i;
}
void stack :: pop()
{
	if(top == -1)
	{
		cout<<"ERROR! STACK UNDERFLOW"<<endl;
		return;
	}
	top--;
}
int stack :: givetop()
{
	if(top == -1)
	{
		cout<<"UNDEEFLOW!"<<endl;
		return -1;
	}
	return arr[top];
}
bool stack :: isempty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}
class queue
{
	int arr[50] ;
	int beg;
	int rear;
public:
	queue()
	{
		beg = -1;
		rear = -1;
		for(int i=0; i<50;i++){
			arr[i]=0;
		}
	}
	void push(int i);
	void pop();
	int front();
	bool isempty();

};
void queue :: push(int i)
{
	if(rear == 49)
	{
		cout<<"ERROR! QUEUE OVERFLOW!"<<endl;
		return;
	}
	if(rear == -1)
	{
		beg = 0;
		rear = 0;
		arr[rear] = i;
	}
	else
	{
		arr[++rear] = i;
	}
}
void queue :: pop()
{
	if(beg > rear)
	{
		beg = -1;
		rear = -1;
		cout<<"ERROR!QUEUE UNDERFLOW"<<endl;
		return;
	}
	else
	{
		beg++;
	}
}
int queue :: front()
{
	return arr[beg];
}
bool queue :: isempty()
{
	if(beg == -1 || rear == -1)
			return 1;
	if(beg>rear)
			return 1;
	return 0;
}
class Graph
{
	int vertex;
	string cityname[20];
	int edges;
	node* list[20];
public:
	Graph()
	{
		vertex = 0;
		edges = 0;
		for(int i = 0; i < 20; i++)
		{
			list[i] = NULL;
		}
	}
	void create();
	int give_index(string);
	void add_edge();
	void show_graph();
	void delete_edge();
	void delete_vertex();
	void indegree();
	void outdegree();
	void bfs();
	void dfs();
};
void Graph :: dfs()
{
	cout<<"DFS :"<<endl;
	label1:
	cout<<"ENTER START CITY :";
	string city;
	cin>>city;
	if(give_index(city) == -1)
	{
		cout<<"NOT POSSIBLE CHOOSE ANY OTHER CITY !"<<endl;
		goto label1;
	}
	int visited[vertex] = {0};
	stack s;
	s.push(give_index(city));
	visited[give_index(city)]= 1;
	while(!s.isempty())
	{
		cout<<cityname[s.givetop()]<<endl;
		node* current = list[s.givetop()];
		while(!s.isempty())
		{				
			while(current == NULL)
			{
				s.pop();
				if(s.isempty() == 0)
					current = list[s.givetop()];
				else
					return;
			}
			if(visited[give_index(current -> dest)] == 0)
			{
				s.push(give_index(current -> dest));
				visited[give_index(current -> dest)] = 1;
				break;
			}
			current = current -> next;
		}
	}
}
void Graph :: bfs()
{
	cout<<"BFS :"<<endl;
	label:
	cout<<"ENTER START CITY :";
	string city;
	cin>>city;
	if(give_index(city) == -1)
	{
		cout<<"NOT POSSIBLE CHOOSE ANY OTHER CITY !"<<endl;
		goto label;
	}
	int visited[vertex] = {0};
	queue q;
	q.push(give_index(city));
	visited[give_index(city)]= 1;
	while(!q.isempty())
	{
		cout<<cityname[q.front()]<<endl;
		node* current = list[q.front()];
		q.pop();
		while(current != NULL)
		{
			if(visited[give_index(current -> dest)] == 0)
			{
				q.push(give_index(current -> dest));
				visited[give_index(current -> dest)] = 1;
			}
			current = current -> next;
		}
	}
	while(!q.isempty())
	{
		cout<<cityname[q.front()]<<endl;
		q.pop();
	}
}
void Graph::outdegree(){
	string s;
	int count=0;
	cout<<"Enter the city name whose out degree to be found\n";
	cin>>s;
	int d=give_index(s);
	node *curr=list[d];
	while(curr !=NULL){
		curr=curr->next;
		count++;
	}
	cout<<"Outdegree is "<<count;
}
void Graph::indegree(){
	string s;
	int count=0;
	cout<<"Enter the city name whose indegree to be found\n";
	cin>>s;
	for(int i=0; i<vertex;i++){
		node *curr=list[i];
		while(curr !=NULL){
		if(cityname[i]==s){
			count++;
		}
		curr=curr->next;
	   }
	}
	cout<<"Indegree is "<<count;
}
void Graph :: create()
{
	cout<<"ENTER NUMBER OF VERTICES :";
	cin>>vertex;
	cout<<"ENTER NUMBER OF EDGES :";
	cin>>edges;
	for(int i = 0; i < vertex; i++)
	{
		cout<<"Enter the cityname\n";
		cin>>cityname[i];
	}
	for(int i = 0; i < edges;i++)
	{
		add_edge();
	}

}
void Graph :: add_edge()
{
	string city_source;
	string city_dest;
	int wt = 0;
	cout<<"ENTER SOURCE CITY :";
	cin>>city_source;
	cout<<"ENTER THE DESTINATION :";
	cin>>city_dest;
	cout<<"ENTER THE DISTANCE :";
	cin>>wt;
	int source = give_index(city_source);
	if(source == -1) return;
	int dest = give_index(city_dest);
	if(dest == -1) return;
	if(list[source] == NULL)
	{
		list[source] = new node(cityname[dest],wt);
		return;
	}
	node* current = list[source];
	while(current->next != NULL)
	{
		current = current -> next;
	}
	current -> next = new node(cityname[dest],wt);
}
int Graph :: give_index(string s)
{
	for(int i = 0; i < vertex; i++)
	{
		if(s == cityname[i])
		{
			return i;
		}
	}
	cout<<"CITY NOT FOUND!"<<endl;
	return -1;
}
void Graph :: show_graph()
{
	cout<<"GRAPH :"<<endl;
	for(int i = 0; i < vertex; i++)
	{
		node* current = list[i];
		//cout<<cityname[i];
		while(current != NULL)
		{
			cout<<"\n"<<cityname[i];
			cout<<" "<<current -> dest<<" "<<current -> cost;
			current = current -> next;
		}
		cout<<endl;
	}
}
void Graph :: delete_edge()
{
	char s[20],d[20];
	cout<<"THE EDGE TO BE DELETED :"<<endl;
	cout<<"ENTER THE SOURCE OF THE EDGE:";
	cin>>s;
	cout<<"ENTER THE DESTINATION OF THE EDGE:";
	cin>>d;
	int source = give_index(s);
	int dest = give_index(d);
	if(source != -1)
	{
		node* current = list[source];
		if(current == NULL) goto del;
		if(current -> dest == cityname[dest])
		{
			node* tmp = current -> next;
			delete list[source];
			list[source] = tmp;
			cout<<"EDGE DELETED!"<<endl;
			return;
		}
		while(current -> next)
		{
			if(current -> next -> dest ==  cityname[dest])
			{
				node* tmp = current -> next;
				current -> next = current -> next -> next;
				delete tmp;
				cout<<"EDGE DELETED!"<<endl;
				return;
			}
			current = current -> next;
		}
	}
	del:
	cout<<"EDGE NOT FOUND!"<<endl;
}
void Graph :: delete_vertex()		//
{
	string s;
	cout<<"ENTER VERTEX TO DELETE :";
	cin>>s;
	int v = give_index(s);
	if(v == -1)
	{
		cout<<"VERTEX NOT FOUND!"<<endl;
		return;
	}
	node* current = list[v];
	list[v] = NULL;
	node* current_next;
	while(current !=NULL)
	{
		current_next = current -> next;
		delete current;
		current = current_next;
	}
	for(int i = 0; i < vertex ; i++)
	{
		label:
		current = list[i];
		if(current) continue;
		if(current -> dest == cityname[v])
		{
			node* tmp = current -> next;
			delete list[v];
			list[v] = tmp;
		}
		goto label;
		while(current -> next)
		{
			if(current -> next -> dest ==  cityname[v])
			{
				node* tmp = current -> next;
				current -> next = current -> next -> next;
				delete tmp;
			}
			else
				current = current -> next;
		}
	}
	cout<<list[v]<<" VERTEX DELETED !"<<endl;
}
int main()
{
	Graph g;
	int c;
	cout<<"Enter Choice\n1.Create Graph\n2.Delete Edge\n3.Delete Vertex\n4.Outdegree\n5.Indegree\n6.BFS\n7.DFS\n";
	cin>>c;
	do{
	switch(c){
	case 1:{
		g.create();
		g.show_graph();
		break;
	}
	case 2:{
		g.delete_edge();
	g.show_graph();
		break;
	}	
	case 3:{
		g.delete_vertex();
	g.show_graph();
		break;
	}
	case 4:
	g.outdegree();
	break;
	case 5:
	g.indegree();
	break;
	case 6:{
		g.bfs();
	cout<<endl;
		break;
	}
	case 7:
	g.dfs();
	break;
}
}while(0<c<8);
	return 0;
}
