class mystack
{
 public:    
 mystack() :_top(0) {}
 void push(int elem)
 {
     if(_top<_table.size())
        _table[_top]=elem;
     else    
        _table.push_back(elem);
    ++_top;    
 }
 void pop()
 {
     if(!_top)
        cout << " Error can't pop empty stack" << endl;
     _top--;
     
 }
 bool isEmpty()
 {
     return _top==0;
 }
 int peek()
 {
     return _table[_top-1];
 }
 private:
  vector<int> _table;
  int _top;
    
};
 
 //Adding the linked list version
 
 class node{
    public:
    int val;
    node *next;
    node(int val) : val(val), next(NULL) {}
};

class mystack
{
 public:    
 mystack() : head(NULL) {}
 void push(int elem)
 {
    node * curr= new node(elem);
    curr->next=head;
    head=curr;
 }
 void pop()
 {
     if(head)
        head=head->next;
     
 }
 bool isEmpty()
 {
     return head==NULL;
 }
 int peek()
 {
     if(head)
        return head->val;
     else
        return -1;
 }
 private:
 node *head;
    
};
 
