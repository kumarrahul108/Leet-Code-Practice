// Leet-Code : Q.No => 106 => Construct Binary Tree from Inorder and Postorder Traversal => 11th April 2024 


    //  Binary Tree + Mapping + Divide & Conquer 


    // 1.******* Using C++ *******

    // Function to create a mapping of values to their indices in the inorder traversal
    void createMapping(vector<int> inorder, map<int,int>& mp) 
    {
        int n = inorder.size();
        for(int i = 0; i < n; i++)  
        {
            mp[inorder[i]] = i;
        }
    }


    // Recursive helper function to construct the binary tree
    TreeNode* helper(map<int,int>& mp, vector<int>& inorder, vector<int>& postorder, int &postIndex, int inorderStart, int inorderEnd) 
    {
        // Base case: If postIndex is negative or inorderStart exceeds inorderEnd
        if(postIndex < 0 || inorderStart > inorderEnd) 
        {
            return nullptr; // Return null node
        }

        // Construct root node from current element in postorder sequence
        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);

        // Find position of current element in inorder sequence using the mapping
        int pos = mp[element];

        // Recursive calls to build right and left subtrees
        root->right = helper(mp, inorder, postorder, postIndex, pos + 1, inorderEnd);
        root->left = helper(mp, inorder, postorder, postIndex, inorderStart, pos - 1);

        return root; // Return root of subtree
    }


    // Function to build binary tree from inorder and postorder traversal sequences
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int postIndex = postorder.size() - 1; // Initialize postorder index
        int inorderStart = 0; // Initialize start index of inorder sequence
        int inorderEnd = inorder.size() - 1; // Initialize end index of inorder sequence

        map<int,int> mp; // Create a mapping of values to their indices in the inorder traversal
        createMapping(inorder, mp);

        // Call helper function to construct binary tree
        TreeNode* root = helper(mp, inorder, postorder, postIndex, inorderStart, inorderEnd);

        return root; // Return root of binary tree
    }






    // 2.******* Using Java *******

    // Function to create a mapping of values to their indices in the inorder traversal
    void createMapping(int[] inorder, Map<Integer, Integer> mp) 
    {
        int n = inorder.length;
        for (int i = 0; i < n; i++) 
        {
            mp.put(inorder[i], i);
        }
    }

    // Recursive helper function to construct the binary tree
    TreeNode helper(Map<Integer, Integer> mp, int[] inorder, int[] postorder, int[] postIndex, int inorderStart, int inorderEnd) 
    {
        // Base case: If postIndex is negative or inorderStart exceeds inorderEnd
        if (postIndex[0] < 0 || inorderStart > inorderEnd) 
        {
            return null; // Return null node
        }

        // Construct root node from current element in postorder sequence
        int element = postorder[postIndex[0]--];
        TreeNode root = new TreeNode(element);

        // Find position of current element in inorder sequence using the mapping
        int pos = mp.get(element);

        // Recursive calls to build right and left subtrees
        root.right = helper(mp, inorder, postorder, postIndex, pos + 1, inorderEnd);
        root.left = helper(mp, inorder, postorder, postIndex, inorderStart, pos - 1);

        return root; // Return root of subtree
    }

    // Function to build binary tree from inorder and postorder traversal sequences
    TreeNode buildTree(int[] inorder, int[] postorder) 
    {
        int postIndex = postorder.length - 1; // Initialize postorder index
        int inorderStart = 0; // Initialize start index of inorder sequence
        int inorderEnd = inorder.length - 1; // Initialize end index of inorder sequence

        Map<Integer, Integer> mp = new HashMap<>(); // Create a mapping of values to their indices in the inorder traversal
        createMapping(inorder, mp);

        // Call helper function to construct binary tree
        TreeNode root = helper(mp, inorder, postorder, new int[]{postIndex}, inorderStart, inorderEnd);

        return root;
    }