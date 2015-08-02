#include <iostream>
#include <vector>


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
   bool isCyclicUtil(int vertex,vector<bool> &isVisited, vector<bool> inRecPath)
   {
      if(!isVisited[vertex])
      {
         inRecPath[vertex]=true;
         isVisited[vertex]=true;
         for(int i=0;i<Adj[vertex].size();i++)
         {
            if(!isVisited[Adj[vertex][i]] && isCyclicUtil(Adj[vertex][i],isVisited,inRecPath))
               return true;
            if(inRecPath[Adj[vertex][i]])
               return true;
         }
      }
      inRecPath[vertex]=false;
      return false;
   }

   bool isCyclic()
   {
      vector<bool> isVisited(numVertex,false);
      vector<bool> inRecPath(numVertex,false);
      for(int i=0;i<numVertex;i++)
      {
         if(!isVisited[i] && isCyclicUtil(i,isVisited,inRecPath))
            return true;
      }

   return false;
   }

};
