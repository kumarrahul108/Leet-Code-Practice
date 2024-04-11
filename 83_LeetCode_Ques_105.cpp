// Leet-Code : Q.No => 105 => Construct Binary Tree from Preorder and Inorder Traversal => 11th April 2024 


    //  Binary Tree + Mapping + Divide & Conquer 


    // 1.******* Using C++ *******

    // ********* Approach - 1 ********


     // Function to search for target in the inorder traversal sequence
    /*
    int searchInInorder(vector<int> &inorder, int target) 
    {
        int n = inorder.size();
        // Iterate through the inorder sequence
        for (int i = 0; i < n; i++) 
        {
            // If target found, return its index
            if (inorder[i] == target) 
            {
                return i;
            }
        }
        // If target not found, return -1
        return -1;
    }  */

    // store value & its position in map  
    void createMapping(vector<int> inorder,map<int,int> &mp)
    {
        for(int i=0;i<inorder.size();i++)
        {
            int element = inorder[i];
            int index = i;
            mp[element] = index;
        }
    }


    // Recursive helper function to construct the binary tree
    TreeNode* helper(map<int,int> &mp,vector<int>& preorder, vector<int>& inorder, int &preIndex, int inorderStart, int inorderEnd) 
    {
        // Base case: If start index exceeds end index or preorder index exceeds preorder size
        if (inorderStart > inorderEnd || preIndex >= preorder.size()) 
        {
            return nullptr; // Return null node
        }

        // Construct root node from current element in preorder sequence
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);

        // Find position of current element in inorder sequence
        // int pos = searchInInorder(inorder, element);
        int pos = mp[element];

        // Recursive calls to build left and right subtrees
        root->left = helper(mp,preorder, inorder, preIndex, inorderStart, pos - 1);
        root->right = helper(mp,preorder, inorder, preIndex, pos + 1, inorderEnd);

        return root; // Return root of subtree
    }


    // Function to build binary tree from preorder and inorder traversal sequences
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0; // Initialize preorder index
        int inorderStart = 0; // Initialize start index of inorder sequence
        int inorderEnd = inorder.size() - 1; // Initialize end index of inorder sequence

        map<int,int> mp;

        createMapping(inorder,mp);

        // Call helper function to construct binary tree
        TreeNode* root = helper(mp,preorder, inorder, preIndex, inorderStart, inorderEnd);

        return root; // Return root of binary tree
    }






    // ******* approach - 2 ***********

    // Function to search for target in the inorder traversal sequence
    int searchInInorder(vector<int> &inorder, int target) 
    {
        int n = inorder.size();
        // Iterate through the inorder sequence
        for (int i = 0; i < n; i++) 
        {
            // If target found, return its index
            if (inorder[i] == target) 
            {
                return i;
            }
        }
        // If target not found, return -1
        return -1;
    }


    // Recursive helper function to construct the binary tree
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inorderStart, int inorderEnd) 
    {
        // Base case: If start index exceeds end index or preorder index exceeds preorder size
        if (inorderStart > inorderEnd || preIndex >= preorder.size()) 
        {
            return nullptr; // Return null node
        }

        // Construct root node from current element in preorder sequence
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);

        // Find position of current element in inorder sequence
        int pos = searchInInorder(inorder, element);

        // Recursive calls to build left and right subtrees
        root->left = helper(preorder, inorder, preIndex, inorderStart, pos - 1);
        root->right = helper(preorder, inorder, preIndex, pos + 1, inorderEnd);

        return root; // Return root of subtree
    }


    // Function to build binary tree from preorder and inorder traversal sequences
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0; // Initialize preorder index
        int inorderStart = 0; // Initialize start index of inorder sequence
        int inorderEnd = inorder.size() - 1; // Initialize end index of inorder sequence

        // Call helper function to construct binary tree
        TreeNode* root = helper(preorder, inorder, preIndex, inorderStart, inorderEnd);

        return root; // Return root of binary tree
    }





    // ***** approch - 3 ******



    // Function to search for target in the inorder traversal sequence
    int searchInInorder(vector<int> &inorder, int target) 
    {
        int n = inorder.size();
        // Iterate through the inorder sequence
        for (int i = 0; i < n; i++) 
        {
            // If target found, return its index
            if (inorder[i] == target) 
            {
                return i;
            }
        }
        // If target not found, return -1
        return -1;
    }


    // Recursive helper function to construct the binary tree
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inorderStart, int inorderEnd) 
    {
        // Base case: If start index exceeds end index or preorder index exceeds preorder size
        if (inorderStart > inorderEnd || preIndex >= preorder.size()) 
        {
            return nullptr; // Return null node
        }

        // Construct root node from current element in preorder sequence
        int element = preorder[preIndex++];
        TreeNode* root = new TreeNode(element);

        // Find position of current element in inorder sequence
        int pos = searchInInorder(inorder, element);

        // Recursive calls to build left and right subtrees
        root->left = helper(preorder, inorder, preIndex, inorderStart, pos - 1);
        root->right = helper(preorder, inorder, preIndex, pos + 1, inorderEnd);

        return root; // Return root of subtree
}


    // Function to build binary tree from preorder and inorder traversal sequences
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preIndex = 0; // Initialize preorder index
        int inorderStart = 0; // Initialize start index of inorder sequence
        int inorderEnd = inorder.size() - 1; // Initialize end index of inorder sequence

        // Call helper function to construct binary tree
        TreeNode* root = helper(preorder, inorder, preIndex, inorderStart, inorderEnd);

        return root; // Return root of binary tree
    }







    // 2.******* Using Java *******

    int preIndex = 0;
    public int findElement(int[] preorder , int target)
    {
        int n = preorder.length;
        for(int i=0;i<n;i++)
        {
            if(preorder[i] == target)
            {
                return i;
            }
        }
        return -1;
    }


    public TreeNode helper(int[] preorder, int[] inorder,int inorderStart,int inorderEnd)
    {
        // base 
        if(inorderStart > inorderEnd || preIndex >= preorder.length)
        {
            return null;
        }

        // 1-case solve karo
        int element = preorder[preIndex];
        preIndex++;
        TreeNode root = new TreeNode(element);
        int pos = findElement(inorder,element);


        // bakki recurssion 
        root.left = helper(preorder,inorder,inorderStart,pos-1);
        root.right = helper(preorder,inorder,pos+1,inorderEnd);

        return root;
    }


    public TreeNode buildTree(int[] preorder, int[] inorder) 
    {
        // int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.length - 1;

        TreeNode root = helper(preorder,inorder,inorderStart,inorderEnd);

        return root;
    }