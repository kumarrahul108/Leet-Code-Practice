// Leet-Code : Q.No => 938 => Range Sum of BST => 13th April 2024 


    //  Binary Serach Tree + D.F.S  


    // 1.******* Using C++ *******

    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        // Base case: If root is null, return 0 
        if(root == NULL)
        {
            return 0;
        }  

        // Initialize variables
        bool wasInRange = false;    // Flag to track if current node's value is within the range
        int ans = 0;    // Variable to store the sum of values within the range

        // Check if current node's value is within the range
        if(root->val >= low && root->val <= high)
        {
            wasInRange = true;        // Set flag to true
            ans = ans + root->val;   // Add current node's value to the sum
        }      

        // If current node's value was within the range, recursively process left and right subtrees
        if(wasInRange)
        {
            ans += rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }

        // If current node's value is less than low, recursively process right subtree
        else if(root->val < low)
        {
            ans += rangeSumBST(root->right,low,high);
        }

        // If current node's value is greater than high, recursively process left subtree
        else if(root->val > high)
        {
            ans += rangeSumBST(root->left,low,high);
        }

        // Return the sum of values within the range
        return ans;
    }






    // ******** 2. Using Java ******

    public int rangeSumBST(TreeNode root, int low, int high) 
    {
        // base case 
        if(root == null)
        {
            return 0;
        }    

        int ans = 0;
        boolean flag = false;

        if(root.val >= low && root.val <= high)
        {
            ans = ans + root.val;
            flag = true;    
        }

        if(flag)
        {
            ans += rangeSumBST(root.left,low,high) + rangeSumBST(root.right,low,high);
        }

        else if(root.val < low)
        {
            ans += rangeSumBST(root.right,low,high);
        }

        else if(root.val > high)
        {
            ans += rangeSumBST(root.left,low,high);
        }

        return ans;
    }

