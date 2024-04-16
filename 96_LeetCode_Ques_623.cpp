// Leet-Code : Q.No => 623 => Add One to Tree => 16th April 2024 


    //  Tree Traversal


    // 1.******* Using C++ *******

    TreeNode* add(TreeNode* root, int val, int depth, int curr) 
    {
        // Base case: if the current node is NULL, return NULL
        if (root == NULL) 
        {
            return NULL;
        }

        // If the current depth is one less than the target depth, add nodes at this level
        if (curr == depth - 1) 
        {
            // Store the current left and right subtrees
            TreeNode* lTemp = root->left;
            TreeNode* rTemp = root->right;

            // Create new nodes with the given value and attach them as left and right children of the current node
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            // Attach the original left and right subtrees to the new nodes
            root->left->left = lTemp;
            root->right->right = rTemp;

            return root; // Return the modified root node
        }

        // Recursively call the function on the left and right subtrees with incremented depth
        root->left = add(root->left, val, depth, curr + 1);
        root->right = add(root->right, val, depth, curr + 1);

        return root; // Return the root node
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        // Base case: if the target depth is 1, create a new root with the given value and attach the original root as its left child
        if (depth == 1) 
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot; // Return the new root
        }

        // Otherwise, recursively call the add function to add nodes at the specified depth
        return add(root, val, depth, 1);
    }







    // 2.******* Using Java *******
    

    public TreeNode add(TreeNode root, int val, int depth, int curr)
    {
        // base case 
        if(root == null)
        {
            return null;
        }

        if(curr == depth-1)
        {
            TreeNode lTemp = root.left;
            TreeNode rTemp = root.right;

            root.left = new TreeNode(val);
            root.right = new TreeNode(val);
            root.left.left = lTemp;
            root.right.right = rTemp;

            return root;
        }

        root.left = add(root.left,val,depth,curr+1);
        root.right = add(root.right,val,depth,curr+1);

        return root;
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) 
    {
        // base case 
        if(depth == 1)
        {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }        

        return add(root ,val ,depth ,1);
    }




