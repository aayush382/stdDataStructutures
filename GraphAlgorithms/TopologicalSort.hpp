#include <iostream>
#include <vector>
#include <stack>


using namespace std;

class Graph{
private:
   int numVertex;
public:
   vector<vector<int> > Adj;
   Graph(int size): numVertex(size)
   {
      Adj.resize(size);
   }
   void addEdge(int src, int dest)
   {
      Adj[src].push_back(dest);
   }
   void topologicalSortUtil(int vertex,vector<bool> &isVisited, stack<int> &sortStack)
   {
      if(!isVisited[vertex])
      {
         isVisited[vertex]=true;
         for(int i=0;i<Adj[vertex].size();i++)
         {
            if(!isVisited[Adj[vertex][i]])
               topologicalSortUtil(Adj[vertex][i],isVisited,sortStack);
         }
      }
      sortStack.push(vertex);

   }

   void topologicalSort()
   {
      vector<bool> isVisited(numVertex,false);
      stack<int> sortStack;
      for(int i=0;i<numVertex;i++)
      {
        if(!isVisited[i])
           topologicalSortUtil(i,isVisited,sortStack);
      }

   while(!sortStack.empty())
   {
      cout << " " << sortStack.top();
      sortStack.pop();
   }

   }

};
