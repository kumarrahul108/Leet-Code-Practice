// Leet-Code : Q.No => 437 => Path SUm - III => 14th April 2024 


    //  traversal + dfs



    // 1.******* Using C++ *******


    int ans = 0; // Global variable to store the count of paths with the given sum

    // Function to count paths with the given sum starting from a particular root
    void pathFromOneRoot(TreeNode* root, long long sum) 
    {
        // Base case: If the root is null, return
        if (root == NULL) 
        {
            return;
        }

        // If the current node's value equals the remaining sum, increment the count
        if (sum == root->val) 
        {
            ans++;
        }

        // Recursively explore paths in the left subtree by subtracting the current node's value from the sum
        pathFromOneRoot(root->left, sum - root->val);

        // Recursively explore paths in the right subtree by subtracting the current node's value from the sum
        pathFromOneRoot(root->right, sum - root->val);
    }


    // Function to find paths with the given sum in the entire tree
    int pathSum(TreeNode* root, int targetSum) 
    {
        // Check if the root is not null
        if (root != NULL) 
        {
            // Count paths with the given sum starting from the current root
            pathFromOneRoot(root, targetSum);
            
            // Recursively explore paths with the given sum in the left subtree
            pathSum(root->left, targetSum);
            
            // Recursively explore paths with the given sum in the right subtree
            pathSum(root->right, targetSum);
        }

        return ans; // Return the total count of paths with the given sum
    }






    // 2.******* Using Java *******


    int ans = 0;

    public void pathFromOneRoot(TreeNode root,long targetSum)
    {   
        // base case 
        if(root == null)
        {
            return;
        }

        if(root.val == targetSum)
        {
            ans++;
        }

        pathFromOneRoot(root.left,targetSum - root.val);
        pathFromOneRoot(root.right,targetSum - root.val);       
    }

    public int pathSum(TreeNode root, int targetSum) 
    {
        if(root != null)
        {
            pathFromOneRoot(root,targetSum);

            // recurssion 
            pathSum(root.left,targetSum);
            pathSum(root.right,targetSum);
        }   

        return ans;  
    }