// Leet-Code : Q.No => 230 => Kth Smallest Element in a BST => 12th April 2024 


    //  Binary Serach Tree + D.F.S  


    // 1.******* Using C++ *******

    int count = 0;

    int inorder(TreeNode* root, int k)
    {
        if (root == NULL) 
        {
            return -1;
        }

        int leftAns = inorder(root->left, k);
        if (leftAns != -1) 
        {
            return leftAns;
        }

        count++;
        if (count == k) 
        {
            return root->val;
        }

        return inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        return inorder(root, k);
    }





    // 2.******* Using Java *******

    public int kthSmallest(TreeNode root, int k) 
    {
        int count = countNodes(root.left);
        if (k <= count) 
        {
            return kthSmallest(root.left, k);
        } 
        else if (k > count + 1) 
        {
            return kthSmallest(root.right, k-1-count); // 1 is counted as current node
        }
      
        return root.val;
    }
  
    public int countNodes(TreeNode n) 
    {
        if (n == null) 
        return 0;
      
        return 1 + countNodes(n.left) + countNodes(n.right);
    }