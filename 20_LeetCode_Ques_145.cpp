// Leet-Code : Q.No => 145 => Binary Tree PostOrder Traversal -> 8th March 2024 

    // Tree Traversal 

    // 1. Using C++

    void postOrder(TreeNode* root,vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }

        postOrder(root->left,ans);

        postOrder(root->right,ans);

        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;

        postOrder(root,ans);

        return ans;    
    }


    // 2. Using Java 

    public void postOrder(TreeNode root,List<Integer> ans)
    {
        if(root == null)
        {
            return;
        }

        postOrder(root.left,ans);
        postOrder(root.right,ans);

        ans.add(root.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) 
    {
        List<Integer> ans = new ArrayList<>(); 

        if(root == null)
        {
            return ans;
        }

        postOrder(root,ans);

        return ans;
    }
    
