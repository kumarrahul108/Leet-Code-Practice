// Leet-Code : Q.No => 98 => Validate Binary Search Tree => 12th April 2024 


    //  Binary Serach Tree  +  D.F.S


    // 1.******* Using C++ *******


    // ****** approach - 1 ******* 

    bool helper(TreeNode* root,long long int lowerBound,long long int upperBound)
    {
        // base case 
        if(root == NULL)
        {
            return true;
        }    

        bool cond1 = (root->val > lowerBound);
        bool cond2 = (root->val < upperBound);

        bool leftAns = helper(root->left,lowerBound,root->val);
        bool rightAns = helper(root->right,root->val,upperBound);

        if(cond1 && cond2 && leftAns && rightAns)
        {
            return true;
        }

        return false;
    }

    bool isValidBST(TreeNode* root) 
    {
        long long int lowerBound = -2147483657;                    
        long long int upperBound = 2147483657;

        bool ans = helper(root,lowerBound,upperBound);

        return ans;                    
    }


    // ****** approach - 2 ******* 

    // Helper function to recursively validate BST
    bool helper(TreeNode* root, long long int lowerBound, long long int upperBound) 
    {
        // Base case: If root is null, return true
        if (root == NULL) 
        {
            return true;
        }    

        // Check if the current node's value is within the valid range
        bool cond1 = (root->val > lowerBound);
        bool cond2 = (root->val < upperBound);

        // Recursively validate left and right subtrees with updated bounds
        bool leftAns = helper(root->left, lowerBound, root->val);
        bool rightAns = helper(root->right, root->val, upperBound);

        // If all conditions are met, return true
        if (cond1 && cond2 && leftAns && rightAns) 
        {
            return true;
        }

        // Otherwise, return false
        return false;
    }

    // Function to validate whether a binary tree is a binary search tree
    bool isValidBST(TreeNode* root) 
    {
        // Define lower and upper bounds for the root node
        long long int lowerBound = LLONG_MIN; // Minimum value representable by long long int
        long long int upperBound = LLONG_MAX; // Maximum value representable by long long int

        /* or use this 
        long long int lowerBound = -2147483657;
        long long int upperBound = 2147483657;
        */

        // Call the helper function to validate the BST
        bool ans = helper(root, lowerBound, upperBound);

        // Return the result
        return ans;
    }





    // 2.******* Using Java *******

    public boolean helper(TreeNode root, long lowerBound, long upperBound) 
    {
        // Base case: if root is null, return true
        if (root == null) 
        {
            return true;
        }

        // Check if the current node's value is within the valid range
        boolean cond1 = (root.val > lowerBound);
        boolean cond2 = (root.val < upperBound);

        // Recursively check left and right subtrees with updated bounds
        boolean leftAns = helper(root.left, lowerBound, root.val);
        boolean rightAns = helper(root.right, root.val, upperBound);

        // If all conditions are met, return true
        if (cond1 && cond2 && leftAns && rightAns) 
        {
            return true;
        }

        // Otherwise, return false
        return false;
    }

    public boolean isValidBST(TreeNode root) 
    {
        // Initialize lower bound as the minimum value representable by long
        long lowerBound = Long.MIN_VALUE;
        // Initialize upper bound as the maximum value representable by long
        long upperBound = Long.MAX_VALUE;

        // Call the helper function to validate the BST
        return helper(root, lowerBound, upperBound);
    }