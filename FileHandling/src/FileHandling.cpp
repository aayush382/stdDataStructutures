
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
 for (int i=0;i<data.size();i++)
  for(int j=0;j<data[i].size();j++)
      cout << i << " " << j << "  and data : " << data[i][j] << endl;

return 0;
}
