// Leet-Code : Q.No => 101 => Symmetric Tree => 5th April 2024 


    //   tree traversal & comparison 


    // 1.******* Using C++ *******

    
    // Function to check if two trees are mirror images of each other
    bool isMirror(TreeNode* p, TreeNode* q)
    {
        // If both trees are null, they are mirror images 
        if(!p && !q)
        {
            return true;
        }

        // If both trees are not null 
        if(p && q)
        {
            // Check if the values of corresponding nodes are equal and their subtrees are mirror images
            return (p->val == q->val)           // Values of corresponding nodes are equal
                && isMirror(p->left,q->right)    // Check if left subtree of p is mirror of right subtree of q
                && isMirror(p->right,q->left);   // Check if right subtree of p is mirror of left subtree of q   
        }

        // If one of the trees is null and the other is not, they cannot be mirror images
        return false;
    }


    // Function to check if a binary tree is symmetric
    bool isSymmetric(TreeNode* root) 
    {
        // Call the isMirror function with the left subtree of root and the right subtree of root
        return isMirror(root->left,root->right);
    }



    // 2.******* Using Java *******

    public boolean isMirror(TreeNode root1, TreeNode root2)
    {
        // Check if both root's are null then return true, because both root are at leaf node and both root have similar height.
        if(root1 == null && root2 == null)
        {
            return true;
        }

        // Check if only one root is null then return false, because both root have different height.
        if(root1 == null || root2 == null)
        {
            return false;
        }

        // Check if both root's value is differnrt it means it is not a symmetric , so simplly return false.
        if(root1.val != root2.val)
        {
            return false;
        }

        // return the isMirror function that is checking both root1's left with root2's right or root1's right with root2's left.
        return isMirror(root1.left,root2.right) && isMirror(root1.right,root2.left);

    }

    public boolean isSymmetric(TreeNode root) 
    {
        // base case 
        if(root ==  null)
        {
            return true;
        }    

        return isMirror(root.left,root.right);
    }