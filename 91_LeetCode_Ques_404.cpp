// Leet-Code : Q.No => 404 => Sum of Left Leaves => 14th April 2024 


    //  tree traversal 


    // 1.******* Using C++ *******

    int sumOfLeftLeaves(TreeNode* root) 
    {
        // Base case: if the root is null, return 0
        if (root == NULL) 
        {
            return 0;
        }            

        int ans = 0;

        // Check if the left child exists
        if (root->left) 
        {
            // If the left child is a leaf node (no left or right child)
            if (!root->left->left && !root->left->right) 
            {
                ans += root->left->val; // Add the value of the left leaf node to the answer
            } 
            else 
            {
                ans += sumOfLeftLeaves(root->left); // Recursively calculate the sum of left leaves in the left subtree
            }
        }

        // Recursively calculate the sum of left leaves in the right subtree
        ans += sumOfLeftLeaves(root->right);

        return ans; // Return the total sum of left leaves
    }





    // 2.******* Using Java *******

    public int sumOfLeftLeaves(TreeNode root) 
    {
        // base case 
        if(root == null)
        {
            return 0;
        }    

        int ans = 0;

        if(root.left != null)
        {
            if(root.left.left == null && root.left.right == null)
            {
                ans += root.left.val;
            }
            else 
            {
                ans += sumOfLeftLeaves(root.left);
            }
        }

        ans += sumOfLeftLeaves(root.right);

        return ans;
    }