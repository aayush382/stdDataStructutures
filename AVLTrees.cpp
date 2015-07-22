
class node {
    public:
    int val;
    int height;
    node *left;
    node *right;
    node(int val): val(val), left(NULL), right(NULL), height(0) {}
};

class AVLTrees{
    private:
    node * _root;
    node *rotateRight(node * root)
    {
        node * newroot=root->left;
        node * movable =newroot->right;
        
        newroot->right=root;
        root->left=movable;
        
        //adjust heights
        root->height = max(root->left->height,root->right->height)+1;
        newroot->height = max(newroot->left->height,newroot->right->height)+1;
        
        return newroot;
    }
    node *rotateLeft(node *root)
    {
        node * newroot=root->right;
        node * movable =newroot->left;
        
        newroot->left=root;
        root->right=movable;
        
        //adjust heights
        root->height = max(root->left->height,root->right->height)+1;
        newroot->height = max(newroot->left->height,newroot->right->height)+1;
        
        return newroot;
    }
    
    node *add(int key, node *root)
    {
        if(!root)
            return new node(key);
            
        if(root->val >key)
            root->left=add(key,root->left);
        else
            root->right=add(key,root->right);
        
        
        int diff =root->left->height - root->right->height;
        
        if(diff>1 && key < root->left->val)
        {
            return rotateRight(root); 
        }
        
        if(diff>1 && key> root->left->val)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root); 
        }
        
        if(diff <-1 && key > root->right->val)
        {
            return rotateLeft(root);
        }
        
        if(diff <-1 && key <root->right->val)
        {
            root->right=rotateRight(root->right);
            return rotateLeft(root);
        }
        
        root->height = max(root->left->height,root->right->height)+1;
        
        return root;    
    }
    
    void preOrder(node *root)
	{
    	if(root)
    	{
        	cout << root->val << endl;
        	preOrder(root->left);
        	preOrder(root->right);
    	}
	}
    
    public:
    AVLTrees(): _root(NULL){}
    node * add(int key)
    {
        _root = add(key,_root);
    }   
    void remove(int key)
    {
        //remove(key,_root);
    }
    void find(int key)
    {
        
    }
    void preOrder()
	{
    	preOrder(_root);
	}
    
};
