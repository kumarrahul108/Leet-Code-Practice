// Leet-Code : Q.No => 129 => Sum Root to Leaf Numbers => 15th April 2024 


    //  tree traversal + leaf node concept 


    // 1.******* Using C++ *******

    int helper(TreeNode* root, int pathSum) 
    {
        // Base case: if the current node is NULL, return 0
        if (root == NULL) 
        {
            return 0;
        }

        // Update the path sum by appending the value of the current node
        pathSum = pathSum * 10 + root->val;

        // Check if the current node is a leaf node
        if (root->left == NULL && root->right == NULL) 
        {
            // If it's a leaf node, return the path sum
            return pathSum;
        }

        // Recursively calculate the sum of numbers for the left and right subtrees
        return helper(root->left, pathSum) + helper(root->right, pathSum);
    }

    int sumNumbers(TreeNode* root) 
    {
        // Call the helper function with the root node and initial path sum of 0
        int ans = helper(root, 0);
        
        return ans; // Return the total sum of numbers formed by paths in the tree
    }






    // 2.******* Using Java *******


    public int helper(TreeNode root,int pathSum)
    {
        // base case 
        if(root == null)
        {
            return 0;
        }

        pathSum = pathSum * 10 + root.val;

        // leaf node
        if(root.left == null && root.right == null)
        {
            return pathSum;
        }

        // other than leaf node 
        return helper(root.left,pathSum)  + helper(root.right,pathSum);
    }

    public int sumNumbers(TreeNode root) 
    {
        int ans = helper(root,0);

        return ans;    
    }