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


//Linked list representation

class node {
    public:
    int val;
    node *next;
    node(int val) : val(val), next(NULL)  {}
};

class myqueue
{
    //push from tail, pop from head
 public:    
 myqueue():tail(NULL), head(NULL) {}
 void push(int elem)
 {
     
     node * curr= new node(elem);
     if(!head)
        { //This is important and mistakes occurr here: you need to intialize head and tail when queuue has been emptied or for the first time
        head=curr;
        tail=curr;
        }
    else
        {
        tail->next=curr;
        tail=curr;
        }
     
 }
 void pop()
 {
     if(!head)
     {
        cout << " Error can't pop empty queue" << endl;
        return;
     }    
     head=head->next;
     
 }
 bool isEmpty()
 {
     return head==NULL;
 }
 int front()
 {
     if(head)
        return head->val;
     else 
        return -1;
 }
 
 private:
 node * head, *tail;
};
