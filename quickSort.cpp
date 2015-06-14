int partition(vector<int> &A, int start, int end)
{
	int pivot=end;
    for(int i=start; i< end;i++)
		if(A[i] < A[pivot])
			swap(A[i],A[start++]);
			
	swap(A[start],A[pivot]);
	
	return start;
}	

void quickSort(vector<int> &A, int start, int end)
{
	//cout << start << end << endl;
	if(start>end)
		return;
	
	int pivot= partition(A,start,end);
	
	quickSort(A,start,pivot-1);
	quickSort(A,pivot+1,end);
}




