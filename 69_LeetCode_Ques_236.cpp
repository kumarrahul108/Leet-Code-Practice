// Leet-Code : Q.No => 236 => Lowest Common Ancestor of a Binary Tree => 2nd April 2024 


    //  


    // 1.******* Using C++ *******

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // Base case: if the current node is NULL, return NULL
        if(root == NULL)
        {
            return root;
        } 

        // If the value of the current node matches either p or q, return the current node
        if(root->val == p->val)
        {
            return p;
        }   

        if(root->val == q->val)
        {
            return q;
        }

        // Recursively search for the lowest common ancestor in the left subtree 
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);

        // Recursively search for the lowest common ancestor in the right subtree
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        // If both leftAns and rightAns are NULL, the lowest common ancestor doesn't exist
        if(leftAns == NULL  &&  rightAns == NULL)
        {
            return NULL;
        }

        // If leftAns is not NULL and rightAns is NULL, return leftAns    
        else if(leftAns != NULL  &&  rightAns == NULL)
        {
            return leftAns;
        }

        // If leftAns is NULL and rightAns is not NULL, return rightAns
        else if(leftAns == NULL  &&  rightAns != NULL)
        {
            return rightAns;
        }

         // If both leftAns and rightAns are not NULL, the current node is the lowest common ancestor
        else 
        {
            return root;
        }
    }





    // 2.******* Using Java *******

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) 
    {
        // base case 
        if(root == null)
        {
            return root;
        }    

        if(root.val == p.val)
        {
            return p;
        }

        if(root.val == q.val)
        {
            return q;
        }

        // solve 

        TreeNode leftAns = lowestCommonAncestor(root.left,p,q);

        TreeNode rightAns = lowestCommonAncestor(root.right,p,q);

        if(leftAns == null  && rightAns == null)
        {
            return null;
        }

        else if(leftAns != null && rightAns == null)
        {
            return leftAns;
        }

        else if(leftAns == null  && rightAns != null)
        {
            return rightAns;
        }

        else 
        {
            return root;
        }
    }