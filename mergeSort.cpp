void merge(vector<int> &A, int start,int mid, int end)
{
    int lenL=mid-start+1;
    int lenR=end-mid;

    vector<int> L(A.begin()+start,A.begin()+mid+1);
    vector<int> R(A.begin()+mid+1,A.begin()+end+1);
   
    int i=0,j=0;
    for(int count=start;count<=end;count++)
    {
        if(i<lenL && j<lenR)
        {
            if(L[i]<R[j])
                A[count]=L[i++];
            else
                A[count]=R[j++];
        }
        else if(i<lenL)
            A[count]=L[i++];
        else
             A[count]=R[j++];
    }
}

void mergeSort(vector<int> &A, int start, int end)
{
    if(start>=end)
        return;
    
    int mid=(start+end)/2;
    mergeSort(A,start,mid);
    mergeSort(A,mid+1,end);
    merge(A,start,mid,end);
}
