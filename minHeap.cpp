class minHeap{
void min_heapify(vector<int> &input, int index)
{
	int candidate=index;

	if( index*2 <= input.size() && input[index*2-1] < input[index-1]) //left
		candidate=index*2;
		
	if(index*2 +1 <= input.size() && input[index*2+1-1] < input[candidate-1]) //right
		candidate=index*2+1;
	
	if(candidate!=index)
	{
		swap(input[index-1],input[candidate-1]);
		min_heapify(input,candidate);
	}
	
		
}	
void add(vector<int> &input, int elem)
{
	input.push_back(elem);
	int child=input.size();
	int parent=input.size()/2;
	
	while(parent >0 && input[parent-1]>input[child-1])
	{
		swap(input[parent-1],input[child-1]);
		child=parent;
		parent=child/2;
	}
	
}

int find(vector<int> &input , int elem)
{
	for(int i=0;i<input.size();i++)
		if(input[i]==elem)
			return i+1;
			
	return -1;
}

void remove(vector<int> &input, int elem)
{
	int idx=find(input,elem);
	if(idx==-1)
		return;
		
 	swap(input[input.size()-1],input[idx-1]);
	input.pop_back();
	min_heapify(input,idx);	
}



void make_heap(vector<int> &input)
{
	for(int i=input.size()/2;i>0;i--)
		min_heapify(input,i);
}
void print(vector<int> &input)
{
	for(int i=0;i<input.size();i++)
		cout << " " <<input[i];
	
}
};
