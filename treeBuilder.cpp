class mytuple{
    public:
    string parent;
    string child;
    mytuple(string parent, string child): parent(parent), child(child) {}
};

class node{
    public:
    string val;
    node *left;
    node *right;
    node(string val): left(NULL), right(NULL), val(val) {}
};

class treeBuilder
{
    public:
    treeBuilder() : _root(NULL) {}
    treeBuilder(vector<mytuple *> &input) : _root(NULL),_input(input) 
    {
        
        createTree(_input);
    }
    node * findParent(map<string, string> &parentList, map<string,node *> &valNodeMap, string child)
    {
        map<string,string>::iterator got;
        got = parentList.find(child);
        
        while(got!=parentList.end())
        {
            child=got->second;
            got = parentList.find(child);
        }
        
        return valNodeMap.find(child)->second;
    }
    void createTree(vector<mytuple*>& input)
    {
        map<string,node *> valNodeMap;
        map<string,string> parentList;
        map<string,node *>::iterator got;
        for(int i=0;i<input.size();i++)
        {
            node *parent;
            got = valNodeMap.find(input[i]->parent);
            if(got!=valNodeMap.end())
               parent= got->second;
            else
               {
               parent = new node(input[i]->parent);
               valNodeMap.insert(pair<string,node*>(input[i]->parent, parent));
               }
            
            node *child;
            got = valNodeMap.find(input[i]->child);
            if(got!=valNodeMap.end())
               child= got->second;
            else
               {
               child = new node(input[i]->child); 
               valNodeMap.insert(pair<string,node*>(input[i]->child, child));
               }
           
           //update root
           if(parent->left)
           {
           	  cout << " node " <<input[i]->parent << " right---> " << input[i]->child << endl;
              parent->right=child;
           }
           else
           {
           	cout << " node " <<input[i]->parent << " left---> " << input[i]->child << endl;
              parent->left=child;
           }
            
            //update the hash table
            parentList.insert(pair<string,string>(input[i]->child,input[i]->parent));
            
           //update _parent
            if(!_root )
                _root=parent;
            else if(_root==child)
                _root= findParent(parentList,valNodeMap, input[i]->parent);
            
        }
    }
    void printInorderTree(node *root)
    {
        if(!root)
            return ;
        printInorderTree(root->left);    
        cout << "  val " << root->val << endl;
        printInorderTree(root->right);  
          
    }
    void printPostorderTree(node *root)
    {
        if(!root)
            return ;
        printPostorderTree(root->left);    
        printPostorderTree(root->right);  
        cout << "  val " << root->val << endl;
          
    }
    node * _root;
    vector<mytuple *> _input;
};
