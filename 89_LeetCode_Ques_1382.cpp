// Leet-Code : Q.No => 1382 => Balance a Binary Search Tree => 13th April 2024 


    //  Binary Serach Tree + D.F.S  


    // 1.******* Using C++ *******

    // Function to perform inorder traversal of the tree and store the values in a vector
    void inorder(TreeNode* root, vector<int>& in)
    {
        // Base case: If root is null, return
        if(root == NULL)
        {
            return ;
        }

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    // Function to construct a balanced BST from a sorted array of values
    TreeNode* inorderToBst(int s, int e, vector<int>& inorderVal)
    {
        // base case 
        if(s>e)
        {
            return NULL;
        }

        // calculating mid value 
        int mid  = (s+e)/2;

        // Create a new node with the value at the mid index
        TreeNode* root = new TreeNode(inorderVal[mid]);

        // Recursively construct left subtree using values from start to mid-1
        root->left = inorderToBst(s, mid-1, inorderVal);

        // Recursively construct right subtree using values from mid+1 to end
        root->right = inorderToBst( mid +1, e, inorderVal);

        // Return the root of the constructed subtree
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) 
    {
        // Vector to store the inorder traversal of the BST
        vector<int> inorderVal;

        // Perform inorder traversal and store values in the vector
        inorder(root , inorderVal);

        // Construct a balanced BST from the sorted array of values
        return inorderToBst(0, inorderVal.size()-1, inorderVal);
    }






    // 2.******* Using Java *******

    public void inOrder(TreeNode root, List<Integer> list) 
    {
        // Base case: If root is null, return
        if(root == null) 
        {
            return;
        }

        // Inorder traversal: left, root, right
        inOrder(root.left, list);
        list.add(root.val);
        inOrder(root.right, list);
    }

    public TreeNode buildTree(List<Integer> list, int start, int end) 
    {
        // Base case: If start index is greater than end index, return null
        if(start > end) 
        {
            return null;
        }

        // Calculate mid index
        int mid = (start + end) / 2;

        // Create a new TreeNode with value at mid index
        TreeNode root = new TreeNode(list.get(mid));

        // Recursively build left subtree using values from start to mid-1
        root.left = buildTree(list, start, mid - 1);

        // Recursively build right subtree using values from mid+1 to end
        root.right = buildTree(list, mid + 1, end);

        // Return the root of the constructed subtree
        return root;
    }

    public TreeNode balanceBST(TreeNode root) 
    {
        // List to store inorder traversal of the BST
        List<Integer> list = new ArrayList<>();
        
        // Perform inorder traversal and store values in the list
        inOrder(root, list);

        // Build balanced BST from the sorted list
        return buildTree(list, 0, list.size() - 1);
    }

