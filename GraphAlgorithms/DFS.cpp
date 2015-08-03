class Node{
    public:
    int val;
    vector<Node *> children;
    bool isVisited;
    Node(int val): val(val), isVisited(false) {}
};

void DFSVisit(Node *root)
{
    if(!root)
        return ;
        
    root->isVisited=true;
    
    //Do what you want with the visit.
    cout << " Visiting node " << root->val << endl;
    
    for(int i=0;i<root->children.size();i++)
    {
        if(!root->children[i]->isVisited) 
            DFSVisit(root->children[i]);
    }
    
}

void DFSVisitIterative(Node *root)
{
    stack<Node *> traverseList;
    traverseList.push(root);
    while(!traverseList.empty())
    {
        Node * node=traverseList.top();
        traverseList.pop();
        
        node->isVisited=true;
        
        //Do what you want with the visit.
        cout << " Visiting node " << node->val << endl;
        
        for(int i=0;i<node->children.size();i++)
        {   
            
            if(!node->children[i]->isVisited)
                traverseList.push(node->children[i]);
        }
    }
}
