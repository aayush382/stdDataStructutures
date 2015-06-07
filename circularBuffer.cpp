
class circularQueue
{
    public:
    circularQueue(int size): _list(size,0), _size(size), _start(0), _end(-1), _empty(true) {}
    circularQueue(): _list(5,0), _size(5),  _start(0), _end(-1), _empty(true) {}
    
    void add(int elem)
    {
         //end always pointing to end of list
         
        _end=(_end+1)%_size; 
        _list[_end]=elem;
        
        //over-write least recently used data, and update _start pointer.
         if(_end==_start && !_empty)
            _start=(_start+1)%_size;
            
     _empty=false;
       
    }
    void remove()
    {
        if(_empty) 
        {
            cout << " can't remove empty circular buffer " << endl;
            return;
        }
        //_start always points to the first added data, least recently used.
       _list[_start]=0; 
       _start=(_start+1)%_size;
       
       //This means we deleted all the data.
       if(_start==(_end+1)%_size)
          _empty=true;
        
    }
    
    int peek()
    {
        return _list[_start];
    }
    
    bool isEmpty()
    {
        return _empty;
    }
   
    private:
    vector<int> _list; 
    int _size;
    int _start;
    int _end;
    bool _empty;
};
