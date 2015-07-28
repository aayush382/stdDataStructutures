#include "DirectedGraph.hpp"
#include<iostream>
#include <queue>
#include <climits>
using namespace std;

class Dijkstra{
private:
	vector<int> pathTo;
	vector<int> distTo;
	dirGraph * dGraph;


public:
	Dijkstra(int graph[][],int n)
	{
		dGraph=new dirGraph(graph,n);
	}
	void initialize(int source)
	{
		for(int i=0;i<dGraph->getNumVertex();i++)
		{
			distTo[i]=INT_MAX;
			pathTo[i]=-1;
		}
		distTo[source]=0;
	}
	struct compare
	 {
	   bool operator()(const int& lhs, const int& rhs)
	   {
		   return distTo[lhs]<distTo[rhs];
	   }
	 };

	void findShortestPath(int source)
	{
		initialize(source);
		priority_queue<int, vector<int>, compare> Q;
		Q.push(source);
		while(!Q.empty())
		{
			int vertex = Q.top();
			Q.pop();
			for(int i=0;i<dGraph->Adj[vertex].size();i++)
				relax(dGraph->Adj[vertex][i]);
		}
	}

	void relax(dirEdge *e)
	{
		int source=e->getFrom();
		int dest=e->getTo();
		if(distTo(dest)>distTo(source)+e->weight())
		{
			distTo[dest]=distTo(source)+e->weight();
			pathTo[dest]=source;
		}
	}

};

