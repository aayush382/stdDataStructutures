/*
 * TestDijkshtra.cpp
 *
 *  Created on: Jul 28, 2015
 *      Author: aayush
 */
#include "Dijkstra.hpp"
#include <iostream>
#include <vector>


// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */

   vector<vector<int> > graphV(9,vector<int>(9,0));

   int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

   for(int i=0;i<graphV.size();i++)
   {
	   for(int j=0;j<graphV[i].size();j++)
	   {
		   graphV[i][j]=graph[i][j];
	   }
   }
   Dijkstra * dk = new Dijkstra(graphV, 9);
   dk->findShortestPath(0);
   dk->showShortestPaths();

    return 0;
}
