// Leet-Code : Q.No => 110 => Balnaced Binary Tree => 2nd April 2024 


    //  using height of B.T  +  (lh - rh) <= 1 (condition)


    // 1.******* Using C++ *******

    // Function to calculate the height of the binary tree rooted at 'root'
    int height(TreeNode* root)
    {
        // base case 
        if(root == NULL)
        {
            return 0;
        }

        int lht = height(root->left);
        int rht = height(root->right);

        int ht = max(lht,rht) + 1;

        return ht;
    }

    // Function to check if the binary tree rooted at 'root' is balanced
    bool isBalanced(TreeNode* root) 
    {
        // Base case: if the current node is NULL, it is balanced by definition
        if(root == NULL)
        {
            return true;
        }

        // Calculate the heights of the left and right subtrees
        int lh = height(root->left);
        int rh = height(root->right);

        // Calculate the absolute difference in heights of the left and right subtrees
        int diff = abs(lh - rh);

        // Check if the tree rooted at 'root' is balanced
        // A tree is balanced if the height difference between its left and right subtrees is at most 1
        bool bal = diff <= 1;

        // Recursively check if both the left and right subtrees are balanced 
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

         // If the current node is balanced and both its left and right subtrees are balanced, return true 
        if(bal && leftAns && rightAns)
        {
            return true;
        }

        // Otherwise, return false
        return false;
    }





    // 2.******* Using Java *******

    public int height(TreeNode root)
    {
        // base case 
        if(root == null)
        {
            return 0;
        }

        int lht = height(root.left);
        int rht = height(root.right);

        int ht = Math.max(lht,rht) + 1;

        return ht;
    }

    public boolean isBalanced(TreeNode root) 
    {
        // base case 
        if(root == null)
        {
            return true;
        }    

        // solve for 1-case 
        int lh = height(root.left);
        int rh = height(root.right);

        int diff = Math.abs(lh-rh);

        boolean ans = diff <= 1;

        boolean leftAns = isBalanced(root.left);
        boolean rightAns = isBalanced(root.right);


        // comparison 
        if(ans && leftAns && rightAns)
        {
            return true;
        }

        return false;
    }

    