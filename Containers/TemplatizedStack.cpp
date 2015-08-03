#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class mystack
{
 public:    
 mystack() :_top(0) {}
 void push(T elem)
 {
     if(_top<_table.size())
        _table[_top]=elem;
     else    
        _table.push_back(elem);
        
    ++_top;    
 }
 void pop()
 {
     if(isEmpty())
        throw " can't remove element, stack is empty";
        
     _top--;
     
 }
 bool isEmpty()
 {
     return _top==0;
 }
 T peek()
 {
 	if(isEmpty())
 		throw "can't peek! stack is empty ";
 		
     return _table[_top-1];
 }
 private:
  vector<T> _table;
  int _top;
    
};

int main() {
	// your code goes here
	mystack<int> what;
	
	what.push(2);
	what.push(3);
	cout << what.peek();
	
	mystack<string> what1;
	string s1("hero");
	string s2("zero");
	
	what1.push(s1);
	what1.push(s2);
	what1.pop();

	cout << what1.peek();
	return 0;
}
