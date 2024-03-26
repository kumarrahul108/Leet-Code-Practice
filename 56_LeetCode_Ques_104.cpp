// Leet-Code : Q.No => 104 => Maximum Depth of Binary Tree => 26th March 2024 


    //  BFS + Traversal 


    // 1.******* Using C++ *******

    int maxDepth(TreeNode* root) 
    {
        // Base case: if the root is NULL, it means the tree is empty, so the depth is 0 
        if(root == NULL)
        {
            return 0;
        }    

        // Recursively find the maximum depth of the left subtree
        int leftHt = maxDepth(root->left);

        // Recursively find the maximum depth of the right subtree
        int rightHt = maxDepth(root->right);

        // Return the maximum depth among the left and right subtrees, and add 1 for the current node
        return max(leftHt,rightHt) + 1;
    }




    // 2.******* Using Java *******

    public int maxDepth(TreeNode root) 
    {
        // base case 
        if(root == null)
        {
            return 0;
        }    

        int leftHt = maxDepth(root.left);
        int rightHt = maxDepth(root.right);

        int Ht = Math.max(leftHt , rightHt) + 1;

        return Ht;      
    }