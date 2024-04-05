// Leet-Code : Q.No => 100 => Same Tree => 5th April 2024 


    // tree traversal + comparison 


    // 1.******* Using C++ *******

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // both node is null 
        if(p == NULL && q == NULL)
        {
            return true;
        }    

        // both node is not null
        if(p != NULL && q != NULL)
        {
            return (p->val == q->val) 
                && (isSameTree(p->left,q->left))
                && (isSameTree(p->right,q->right));
        }

        // when either of the node is not null
        return false;

        /*
        if(p == NULL && q != NULL)
        {
            return false;
        }

        if(p != NULL && q == NULL)
        {
            return false;
        }

        return false;  */
    }





    // 2.******* Using Java *******   

    public boolean isSameTree(TreeNode p, TreeNode q) 
    {
        // both (p & q) node is null 
        if(p == null && q == null)
        {
            return true;
        }    

        // when p is null & q is not null
        if(p == null && q != null)
        {
            return false;
        }

        // when p is not null & q not null
        if(p != null && q == null)
        {
            return false;
        }

        //  both not null 
        if(p != null && q != null)
        {
            return (p.val == q.val)
                && (isSameTree(p.left,q.left))
                && (isSameTree(p.right,q.right));
        }

        return false;
    }