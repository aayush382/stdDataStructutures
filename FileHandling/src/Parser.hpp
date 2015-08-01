/*
 * Parser.hpp

 *
 *  Created on: Jul 30, 2015
 *      Author: aayush
 */
#include <iostream>
#include <vector>
#include<string>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

class parseToDistanceMatrix{
private:
	map<string,int> indexMap;
	int id;

public:
	vector<vector<int> > generateMatrix(vector<vector<string> > &input)
		{
		for(int i=0;i<input.size();i++)
		{
			for(int j=0;j<2;j++)
			{
				string ss = input[i][j];
				map<string,int>::iterator got = indexMap.find(ss);
				if(got==indexMap.end())
				{
					indexMap.insert(pair<string,int>(ss,id++));
				}
			}
		}
		int sizeofMatrix = indexMap.size();
		vector<vector<int> > result(sizeofMatrix,vector<int>(sizeofMatrix,0));

		for(int i=0;i<input.size();i++)
			{
			int row = indexMap.find(input[i][0])->second;
			int col = indexMap.find(input[i][1])->second;
			int value = atoi(input[i][2].c_str());
			result[row][col]=value;
		    }
		return result;
		}

	parseToDistanceMatrix(): id(0)
		{
		}
};
