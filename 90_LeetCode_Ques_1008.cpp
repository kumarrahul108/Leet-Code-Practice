// Leet-Code : Q.No => 1008 => Construct Binary Search Tree from PreOrder Traversal => 13th April 2024 


    //  Binary Serach Tree + D.F.S  


    // 1.******* Using C++ *******

    // Recursive function to build the Binary Search Tree (BST) from preorder traversal
    TreeNode* build(int &i, int min, int max, vector<int> &preorder) 
    {
        // Base case: If index i exceeds the size of preorder array, return NULL
        if(i >= preorder.size()) 
        {
            return NULL;
        }

        // Initialize root node as NULL
        TreeNode* root = NULL;

        // If current element in preorder array is within the range (min, max)
        if(preorder[i] > min && preorder[i] < max) 
        {
            // Create a new TreeNode with current element as value
            root = new TreeNode(preorder[i++]);

            // Recursively build left subtree with values within range (min, root->val)
            root->left = build(i, min, root->val, preorder);
            
            // Recursively build right subtree with values within range (root->val, max)
            root->right = build(i, root->val, max, preorder);
        }

        // Return the root of the subtree
        return root;
    }

    // Function to construct a Binary Search Tree (BST) from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        // Initialize min and max values for range checking
        int min = INT_MIN;
        int max = INT_MAX;

        // Initialize index i to track position in preorder array
        int i = 0;

        // Call the build function to construct the BST recursively
        return build(i, min, max, preorder);            
    }





    // 2.******* Using Java *******

    public TreeNode bstFromPreorder(int[] preorder) 
    {
        return constructBST(preorder,Integer.MAX_VALUE,new int[]{0});
    }

    public TreeNode constructBST(int[] preorder,int bound,int[]i) 
    {
        if(i[0]==preorder.length ||preorder[i[0]]>bound) return null;
        TreeNode root=new TreeNode(preorder[i[0]++]);
        root.left=constructBST(preorder,root.val,i);
        root.right=constructBST(preorder,bound,i);
        return root;

    }

