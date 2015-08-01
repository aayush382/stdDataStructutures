#include "DirectedGraph.hpp"
#include<iostream>
#include <queue>
#include <climits>
#include <set>

using namespace std;

class Dijkstra{
private:
	vector<int> pathTo;
	dirGraph * dGraph;


public:
	vector<int> distTo;
	Dijkstra(vector<vector<int> > &graph, int n)
	{
		dGraph=new dirGraph(graph,n);
		distTo.reserve(n);
		pathTo.reserve(n);
	}

	int extractMin(set<int> &Q)
	{
		set<int>::iterator it=Q.begin();
		int vertex=*it;
		for(;it!=Q.end();it++)
			if(distTo[*it]<distTo[vertex])
				vertex=*it;

		return vertex;
	}
	void initialize(int source, set<int> &Q)
	{
		for(int i=0;i<dGraph->getNumVertex();i++)
		{
			distTo[i]=INT_MAX;
			pathTo[i]=-1;
			Q.insert(i);
		}
		distTo[source]=0;
	}


	void findShortestPath(int source)
	{
		set<int> Q;
		while(!Q.empty())
		{
			int vertex = extractMin(Q);
			Q.erase(vertex);
			for(int i=0;i<dGraph->Adj[vertex].size();i++)
				relax(dGraph->Adj[vertex][i]);
		}
	}

	void showShortestPaths()
	{
		cout << "Distances "<< endl;
		for(int i=0;i<distTo.size();i++)
			cout<<" i " << distTo[i] << endl;
	}
	void relax(dirEdge *e)
	{
		int source=e->getFrom();
		int dest=e->getTo();
		if(distTo[dest] > distTo[source]+e->weight())
		{
			distTo[dest]=distTo[source]+e->weight();
			pathTo[dest]=source;
		}
	}

};

