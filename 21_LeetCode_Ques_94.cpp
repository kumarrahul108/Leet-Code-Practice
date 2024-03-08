// Leet-Code : Q.No => 94 => Binary Tree InOrder Traversal -> 8th March 2024 

    // Tree Traversal 

    // 1. Using C++

    void inOrder(TreeNode* root,vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }

        inOrder(root->left,ans);

        ans.push_back(root->val);

        inOrder(root->right,ans);
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;

        if(root == NULL)
        {
            return ans;
        }    

        inOrder(root,ans);

        return ans;
    }



    // 2. Using Java 

    public void inOrder(TreeNode root,List<Integer> ans)
    {
        if(root == null)
        {
            return;
        }

        inOrder(root.left,ans);

        ans.add(root.val);

        inOrder(root.right,ans);
    }

    public List<Integer> inorderTraversal(TreeNode root) 
    {
        List<Integer> ans = new ArrayList<>();

        if(root == null)
        {
            return ans;
        }

        inOrder(root,ans);

        return ans;
    }
