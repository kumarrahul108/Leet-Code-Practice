// Leet-Code : Q.No => 199 => Binary Tree Right Side View => 4th April 2024 


    //    tree traversal + recurssion + right me travel before than left


    // 1.******* Using C++ *******

    void solve(TreeNode* root,vector<int> &ans,int level)
    {
        // Base case: if the current node is NULL (reached the end of the tree)
        if(root == NULL)
        {
            return;
        }

        // Case when we encounter a new level
        // If the current level is equal to the size of the answer vector, 
        // it means this is the first node we encounter at this level from the right side.
        if(level == ans.size())
        {
            // Add the value of the current node to the answer vector
            ans.push_back(root->val);
        }

        // Recur for the right subtree first (right side view)
        solve(root->right,ans,level+1);

        // Recur for the left subtree (since we are interested in right side view)
        solve(root->left,ans,level+1);
    }

    // Function to obtain the right side view of a binary tree
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;

        // Start from level 0
        int level = 0; 

        // Call the solve function to traverse the tree and obtain the right side view
        solve(root, ans, level);

        // Return the right side view vector
        return ans;        
    }






    // 2.******* Using Java *******

    public void solve(TreeNode root,List<Integer> ans,int level)
    {
        // base case 
        if(root == null)
        {
            return;
        }

        // 1- case solve 
        if(ans.size() == level)
        {
            ans.add(root.val);
        }

        // recurssion 
        solve(root.right,ans,level+1);
        solve(root.left,ans,level+1);
    }


    public List<Integer> rightSideView(TreeNode root) 
    {
        List<Integer> ans = new ArrayList<>();
        int level = 0;

        solve(root,ans,level);

        return ans;
    }
