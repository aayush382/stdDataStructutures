/*
 * Graph.hpp
 *
 *  Created on: Jul 27, 2015
 *      Author: aayush
 */
#include<iostream>
#include<vector>

using namespace std;

#ifndef GRAPH_HPP_
#define GRAPH_HPP_


class dirEdge{
private:
	int _src;
	int _dest;
	int _weight;
public:
	dirEdge(int src,int dest, int weight): _src(src), _dest(dest), _weight(weight) {}
	int getFrom() { return _src; }
	int getTo() { return _dest; }
	int weight() { return _weight ;}
};

class dirGraph{
private:
	int numVertex;
	int numEdges;

public:
	vector<vector<dirEdge *>> Adj;
	dirGraph(int graph[][], int n): numVertex(n),numEdges(0)
	{
		Adj.resize(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(graph[i][j])
					addEdge(i,j,graph[i][j]);

	}
	void addEdge(int src,int dest, int weight)
	{
		Adj[src].push_back(new dirEdge(src,dest,weight));
		numEdges++;
	}
	int getNumVertex()
	{
		return numVertex;
	}
};


#endif /* GRAPH_HPP_ */
