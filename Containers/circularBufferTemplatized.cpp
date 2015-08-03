#include <iostream>
using namespace std;


template <class T>
class circularQueue
{
   public:
   circularQueue(int size):  size(size), head(0), tail(0), empty(true) {array[size];}
   circularQueue():  size(5),  head(0), tail(0), empty(true) {array[5];}

   void add(T elem)
   {

      //tail always pointing to the start of the new element

      //over-write least recently used data, and update head pointer.
      if(tail==head && !empty)  // normally for fixed Length queue you'll throw exception
         head=(head+1)%size;

      array[tail]=elem;
      tail=(tail+1)%size;

      empty=false;

   }
   void remove()
   {
       if(isEmpty())
       {
           cout << " can't remove empty circular buffer " << endl;
           throw  "empty queue";
       }

       //head always points to the first added data, least recently used.
      head=(head+1)%size;

      //This means we deleted all the data.
      if(head==tail)
         empty=true;

   }

   T peek()
   {
        if(isEmpty())
        {
        cout << " nothing to peek! its empty";
        throw  "empty queue";
        }
       return array[head];
   }

   bool isEmpty()
   {
       return empty;
   }

   private:
   T array[];
   int size;
   int head;
   int tail;
   bool empty;
};


int main()
{
 circularQueue<int> cq(3);
 cq.add(2);
 cq.add(1);
 cout << cq.peek() << endl;
 //cq.remove();
 //cout << cq.peek() << endl;
 //cq.remove();
 //cq.remove();
return 0;
}
