int BinarySearch(vector<int> &A, int start, int end, int key)
{
    if(start>end)
        return -1;
    int mid=(start+end)/2;
    if(A[mid]==key)
        return mid;
    
    if(A[mid]>key)
        return BinarySearch(A, start,mid-1,key);
    else
        return BinarySearch(A,mid+1,end,key);
}

int BinarySearchIter(vector<int> &A, int start, int end, int key)
{
   int l=start;
   int r=end;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (A[mid]==key)
            return mid;
        else if(A[mid]>key)
            r=mid-1;
        else
            l=mid+1;
            
    }
    return -1;
}
