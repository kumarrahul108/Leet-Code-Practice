// Leet-Code : Q.No => 112 => Path Sum - I => 3rd April 2024 


    //   dfs + tree


    // 1.******* Using C++ *******

    // helper function 
    bool solve(TreeNode* root, int targetSum, int sum)
    {
        // Base case: if the current node is NULL, return false 
        if(root == NULL)
        {
            return false;
        }

        // 1- case solve 

        // Add the value of the current node to the sum
        sum += root->val;

        // Check if the current node is a leaf node (i.e., it has no children)
        if(root->left == NULL && root->right == NULL)
        {
            // If the sum equals the target sum, return true
            if(sum == targetSum)
            {
                return true;
            }
        }

        // Recursively check the left and right subtrees
        bool leftAns = solve(root->left,targetSum, sum);
        bool rightAns = solve(root->right,targetSum, sum);

        // Return true if either the left subtree or the right subtree contains a path with the target sum
        return (leftAns || rightAns);
    }

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        int sum = 0;

        // Call the solve function to check if there exists a path with the target sum starting from the root
        bool ans = solve(root, targetSum, sum);

        // Return the result
        return ans;    
    }





    // 2.******* Using Java *******

    public boolean solve(TreeNode root, int targetSum, int sum)
    {
        // base 
        if(root == null)
        {
            return false;
        }

        // 1- case solev karo 
        sum += root.val;

        // check for leaf node 
        if(root.left == null && root.right == null)
        {
            if(targetSum == sum)
            {
                return true;
            }
        }

        // reccursion 
        boolean leftAns = solve(root.left,targetSum,sum);
        boolean rightAns = solve(root.right,targetSum,sum);

        return (leftAns || rightAns);
    }  


    public boolean hasPathSum(TreeNode root, int targetSum) 
    {
        int sum = 0;

        boolean ans = solve(root,targetSum,sum);

        return ans;            
    }