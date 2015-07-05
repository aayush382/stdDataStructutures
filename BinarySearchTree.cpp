#include <iostream>
#include <vector>
using namespace std;

class node {
    public:
    int val;
    node *left;
    node *right;
    node(int val): val(val), left(NULL), right(NULL){}
};

class BinarySearchTree
{
  public:
    
  BinarySearchTree(node *head):_head(head) {}
  BinarySearchTree():_head(NULL) {}
  void insert(int key)
  {
      addToBST(key,_head);
  }
  void search(int key)
  {
      findInBST(key,_head);
  }
  void inorder(node *root)
  {
      if(!root)
        return;
    inorder(root->left);
    cout <<  " " << root->val ;
    inorder(root->right);
  }
  void remove(int key)
  {
      deleteFromBST(key,_head);
  }
  private:
  void addToBST(int key, node *root)
    {
        if(root->val>key)
        {
            if(root->left)
                addToBST(key,root->left);
            else
                root->left=new node(key);
        }
        else 
        {
            if(root->right)
                addToBST(key,root->right);
            else
                root->right=new node(key);
        }
            
    }
    
    node * deleteFromBST(int key,node *root)
    {
        if(!root)
            return NULL;
            
        if(root->val > key)
            root->left =deleteFromBST(key,root->left);
        else if(root->val < key)
            root->right = deleteFromBST(key,root->right);
        else
           {
            if(!root->left)
                {
                node *tmp = root->right; 
                delete root;
                return tmp;
                }
            else if(!root->right)
                {
                node *tmp = root->left; 
                delete root;
                return tmp;
                }
            else
                {
                node *tmp= findSuccessor(root->right);
                root->val =tmp->val;
                root->right = deleteFromBST(tmp->val,root->right);
                }
           }    
        return root;    
    }
    node *findSuccessor(node *root)
    {
        while(root->left)
            root=root->left;
        return root;    
    }
    node * findInBST(int key, node * root) 
    {
        if(!root)
            return NULL;
        if(root->val==key)
            return root;
        else if(root->val >key)
            return findInBST(key,root->left);
        else
            return findInBST(key,root->right);
    }
    
  node * _head;
};


// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
  
    node * root = new node(50);
    BinarySearchTree  * cl= new BinarySearchTree(root);
    cl->insert(30);
    cl->insert(20);
    cl->insert(40);
    cl->insert(70);
    cl->insert(60);
    cl->insert(80);
  
  
    
    
    printf("Inorder traversal of the given tree \n");
      // print inoder traversal of the BST
    cl->inorder(root);
 
    printf("\nDelete 20\n");
    cl->remove(20);
    printf("Inorder traversal of the modified tree \n");
    cl->inorder(root);
 
    printf("\nDelete 30\n");
    cl->remove(30);
    printf("Inorder traversal of the modified tree \n");
    cl->inorder(root);
    
    printf("\nDelete 50\n");
    cl->remove(50);
    printf("Inorder traversal of the modified tree \n");
    cl->inorder(root);
  
    return 0;
}

