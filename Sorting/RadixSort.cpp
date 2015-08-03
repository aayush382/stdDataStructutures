#include <iostream>
using namespace std;

int getMax(int array[],int n)
{
   if(n<=0)
   return 0;

   int maxElem=array[0];
   for(int i=1;i<n;i++)
      maxElem=max(maxElem,array[i]);

return maxElem;

}

void countSort(int array[],int n, int denom)
{

   int count[10]={0};
   int output[n];

   for(int i=0;i<n;i++)
        count[(array[i]/denom)%10]++;

   for(int i=1;i<10;i++)
        count[i]+=count[i-1];

   for(int i=n-1;i>=0;i--)
        output[(count[(array[i]/denom)%10]--) - 1]=array[i];

   for(int i=n-1;i>=0;i--)
        array[i]=output[i];
}

void radixSort(int array[], int n)
{

 int denom=1;
 int max = getMax(array,n);
 while(max/denom) //|| (max/denom%10))
   {
   countSort(array,n,denom);
   denom*=10;
   }

}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver program to test above functions
int main()
{
    //int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int arr[] = {39,76};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    print(arr, n);
    return 0;
}

