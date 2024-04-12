// Leet-Code : Q.No => 87 => Two Sum IV - Input is a BST => 12th April 2024 


    //  Binary Serach Tree + D.F.S  


    // 1.******* Using C++ *******


    void storeInOrder(TreeNode* root, vector<int>& inorder) 
    {
        // Base case: If root is null, return
        if(root == NULL) 
        {
            return;
        }

        // Traverse left subtree
        storeInOrder(root->left, inorder);

        // Store current node's value in inorder traversal
        inorder.push_back(root->val);

        // Traverse right subtree
        storeInOrder(root->right, inorder);
    }
    

    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> inorder;
        
        // Store inorder traversal of the BST
        storeInOrder(root, inorder);

        // Finding target using two pointers
        int start = 0;
        int end = inorder.size() - 1;

        while(start < end) 
        {
            int sum = inorder[start] + inorder[end];

            if(sum == k) 
            {
                return true;
            }

            else if(sum < k) 
            {
                start++;
            }

            else if(sum > k) 
            {
                end--;
            }
        }

        return false;
    } 






    // 2.******* Using Java *******

    List<Integer> inorder = new ArrayList<>();

    public void storeInOrder(TreeNode root)
    {
        // base case 
        if(root == null)
        {
            return;
        }

        // L N R 
        storeInOrder(root.left);

        inorder.add(root.val);

        storeInOrder(root.right);
    }


    public boolean findTarget(TreeNode root, int k) 
    {
        
        storeInOrder(root);

        int start = 0;
        int end = inorder.size() - 1;

        while(start < end)
        {
            int sum = inorder.get(start) + inorder.get(end);

            if(sum == k)
            {
                return true;
            }

            else if(sum < k)
            {
                start++;
            }

            else if(sum > k)
            {
                end--;
            }
        }

        return false;
    }