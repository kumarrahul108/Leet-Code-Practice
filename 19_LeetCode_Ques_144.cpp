// Leet-Code : Q.No => 144 => Binary Tree PreOrder Traversal -> 8th March 2024 

    // Tree Traversal 

    // 1. Using C++

    void preOrder(TreeNode* root,vector<int> &ans)
    {
        // Base case: If the current node is NULL, return without doing anything
        if(root == NULL)
        {
            return;
        }

        // Add the value of the current node to the result vector
        ans.push_back(root->val);

        // Recursively traverse the left subtree
        preOrder(root->left,ans);

        // Recursively traverse the right subtree
        preOrder(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        // Initialize an empty vector to store the preorder traversal result
        vector<int> ans;

        // Perform preorder traversal starting from the root node
        preOrder(root,ans);

        // Return the vector containing the preorder traversal result
        return ans;
    }



    // 2. USing Java 

    void preOrder(TreeNode root,List<Integer> l)
    {
        if(root == null)
        {
            return;
        }

        l.add(root.val);

        preOrder(root.left,l);
        preOrder(root.right,l);
    }


    public List<Integer> preorderTraversal(TreeNode root) 
    {
        List<Integer> l = new ArrayList<>();

        preOrder(root,l);

        return l;
    }