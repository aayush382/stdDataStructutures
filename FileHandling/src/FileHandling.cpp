
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Parser.hpp"

using namespace std;

int main() {
 vector <vector <string> > data;
 ifstream infile( "stations.csv" );

 while (infile)
 {
   string s;
   if (!getline( infile, s )) break;

   istringstream ss( s );
   vector <string> record;

   while (ss)
   {
     string s;
     if (!getline( ss, s, ',' )) break;
     record.push_back( s );
   }

   data.push_back( record );
 }
 if (!infile.eof())
 {
   cerr << "Whaaat!\n";
 }

 parseToDistanceMatrix * parser = new parseToDistanceMatrix();
 vector<vector<int> > result = parser->generateMatrix(data);

return 0;
}
