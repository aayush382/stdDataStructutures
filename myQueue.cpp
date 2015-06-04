class myqueue
{
 public:    
 myqueue() :_tail(0) {}
 void push(int elem)
 {
     if(_tail<_table.size())
        _table[_tail]=elem;
     else    
        _table.push_back(elem);
    ++_tail;    
 }
 void pop()
 {
     if(!_tail)
     {
        cout << " Error can't pop empty queue" << endl;
        return;
     }    
     _table.erase(_table.begin());    
     _tail--;
     
 }
 bool isEmpty()
 {
     return _tail==0;
 }
 int front()
 {
     if(_tail)
        return _table[0];
     else 
        return -1;
 }
 
 private:
 vector<int> _table;
 int _tail;
};
