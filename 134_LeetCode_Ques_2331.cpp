// Leet-Code : Q.No => 2331 => Evaluate Boolean Binary Tree => 16th May


    // tree traversal   


    // 1.******* Using C++ ******* 


    // Helper function to evaluate the tree based on the node values.
    bool helper(TreeNode* root)
    {
        // Base case: If the node value is 0 or 1, return true if it's 1, false otherwise.
        if(root->val == 0 || root->val == 1)
        {
            return root->val == 1;
        }
        // If the node value is 2, perform logical OR on the results of the left and right subtree evaluations.
        else if(root->val == 2)
        {
            return helper(root->left) || helper(root->right);
        }
        // If the node value is 3, perform logical AND on the results of the left and right subtree evaluations.
        else if(root->val == 3)
        {
            return helper(root->left) && helper(root->right);
        }

        // If the node value is something other than 0, 1, 2, or 3, return false (shouldn't reach here in a valid tree).
        return false;
    }

    // Main function to evaluate the binary tree by calling the helper function.
    bool evaluateTree(TreeNode* root) 
    {
        return helper(root);    
    }




    // 2.******* Using Java ******* 

    public boolean helper(TreeNode root)
    {
        if(root.val == 0 || root.val == 1)
        {
            return root.val == 1;
        }
        else if(root.val == 2)
        {
            return helper(root.left) || helper(root.right);
        }
        else if(root.val == 3)
        {
            return helper(root.left) && helper(root.right);
        }

        return false;
    }

    public boolean evaluateTree(TreeNode root) 
    {
        return helper(root);    
    }