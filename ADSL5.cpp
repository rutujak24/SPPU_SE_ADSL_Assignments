//============================================================================
// Name        : ass5.cpp
// Author      : Rutuja Kawade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <bits/stdc++.h>
#include<iomanip>
#define max 100
using namespace std;
class Graph{
	int** mat;
	int vertex;
	int edges;
public:
	Graph(int v,int e){
		mat = NULL;
		vertex = v;
		edges = e;
		mat = new int*[vertex];
		for(int i = 0;i< vertex;i++){
			mat[i] = new int [vertex];
		}
		for(int i =0; i < vertex;i++){
			for(int j = 0; j< vertex;j++){
				mat[i][j] = 0;
			}
		}
	}
	void create();
	void display();
	void MST_Prims();
	void MST_Krushkal();
};
void Graph :: create(){
	cout<<"ENTER CONNECTED OFFICES :"<<endl;
	int e = edges;
	while(e--){
		int f1,f2,wt;
		cout<<"OFFICE 1 :";
		cin>>f1;
		cout<<"OFFICE 2 :";
		cin>>f2;
		cout<<"ENTER COST :";
		cin>>wt;
		mat[f1][f2] = wt;
		mat[f2][f1] = wt;
	}
}
void Graph :: display(){
	cout<<"GRAPH :"<<endl;
	for(int i =0; i < vertex;i++){
		for(int j = 0; j < vertex;j++){
			cout<<setw(2)<<left<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
class edge{
public:
	int s,d,wt;
	edge(){
		s = 0;
		d =  0;
		wt = 0;
	}
};
void sort(edge *e,int edges){
	for(int i = 0; i < edges; i++){
		for(int j = 0; j < edges-1; j++){
			if(e[j].wt > e[j+1].wt){
				edge tmp = e[j];
				e[j] = e[j+1];
				e[j+1] = tmp;
			}
		}
	}
}
void Graph :: MST_Krushkal()
{
	cout<<"MST KRUSHKAL:"<<endl;
	int a = 0;
	edge e[edges];
	for(int i = 0; i < vertex; i++){
		for(int j = i+1; j < vertex; j++){
			if(mat[i][j]  != 0){
				e[a].s = i;
				e[a].d = j;
				e[a++].wt = mat[i][j];
			}
		}
	}
	sort(e,edges);
	int father[vertex];
	int parent[vertex] = {0};
	for(int i = 0; i < vertex;i++)
		father[i] = i;
	for(int i = 0; i < edges;i++){
		if(father[e[i].s] != father[e[i].d]){
			parent[e[i].d] = e[i].s;
			father[e[i].d] = father[e[i].s];
		}
	}
	cout<<"EDGES :"<<"\t   "<<"WEIGHT :"<<endl;
	int min_wt = 0;
	for(int i = 1; i < vertex;i++){
		cout<<parent[i]<<"\t"<<i<<"\t"<<mat[i][parent[i]]<<endl;
		min_wt = min_wt + mat[i][parent[i]];
	}
	cout<<"MINIMUM WEIGHT :"<<min_wt<<endl;
}

int min_key(int* key, bool* visited,int vertex){
	int min = INT_MAX;
	int min_term = 0;
	for(int i = 0 ; i < vertex; i++)
		if(visited[i] == false && min > key[i])
			min = key[i], min_term = i;
	return min_term;
}
void Graph :: MST_Prims(){
	cout<<"MST PRIMS"<<endl;
	int parent[vertex] = {0};
	int key[vertex];
	bool visited[vertex] = {0};
	for(int i= 0; i  < vertex; i ++)
		key[i] = INT_MAX;
	key[0] = 0;
	for(int i = 0; i < vertex-1;i++){
		 int u = min_key(key,visited,vertex);
		 visited[u] = 1;
		 for(int v = 0; v < vertex; v++)
			 if(visited[v] == false && mat[u][v] && key[v] > mat[u][v])
				 key[v] = mat[u][v], parent[v] = u;
	}
	cout<<"EDGES :"<<"\t   "<<"WEIGHT :"<<endl;
	int min_wt = 0;
	for(int i = 1; i < vertex;i++){
		cout<<parent[i]<<"\t"<<i<<"\t"<<mat[i][parent[i]]<<endl;
		min_wt = min_wt + mat[i][parent[i]];
	}
	cout<<"MINIMUM WEIGHT :"<<min_wt<<endl;
}
int main() {
	int v,e;
	cout<<"ENTER NUMBER OF VERTICES AND EDGES :";
	cin>>v>>e;
	Graph g(v,e);
	g.create();
	g.display();
	g.MST_Krushkal();
	g.MST_Prims();
	return 0;
}
