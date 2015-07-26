#include<iostream>
using namespace std;


class node {
    public:
	node(int val): val(val), left(NULL), right(NULL), height(1) {}
    int val;
    node *left;
    node *right;
    int height;
};

class AVLTrees{
    private:
    node * _root;

	int getHeight(node* root)
    {
    	if(!root)
    		return 0;

    	return root->height;
    }
    node *rotateRight(node * root)
    {
        node * newroot=root->left;
        node * movable =newroot->right;
        
        newroot->right=root;
        root->left=movable;
        
        //adjust heights
        root->height = max(getHeight(root->left),getHeight(root->right))+1;
        newroot->height = max(getHeight(newroot->left),getHeight(newroot->right))+1;
        
        return newroot;
    }
    node *rotateLeft(node *root)
    {
        node * newroot=root->right;
        node * movable =newroot->left;
        
        newroot->left=root;
        root->right=movable;
        
        //adjust heights
        root->height = max(getHeight(root->left),getHeight(root->right))+1;
        newroot->height = max(getHeight(newroot->left),getHeight(newroot->right))+1;
        
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
        
        
        int diff = getHeight(root->left) - getHeight(root->right);
        
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
        
        cout << diff << endl;
        root->height = max(root->left?root->left->height:0,root->right?root->right->height:0)+1;
        
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
    
    void inOrder(node *root)
 	{
     	if(root)
     	{
         	preOrder(root->left);
         	cout << root->val << endl;
         	preOrder(root->right);
     	}
 	}

    public:
    AVLTrees(): _root(NULL){}

    void add(int key)
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
    void inOrder()
    {
        inOrder(_root);
    }
    
};
