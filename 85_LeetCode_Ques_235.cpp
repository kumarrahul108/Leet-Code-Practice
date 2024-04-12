// Leet-Code : Q.No => 235 => Lowest Common Ancestor of a Binary Search Tree => 12th April 2024 


    //  Binary Serach Tree + D.F.S  


    // 1.******* Using C++ *******

    // Function to find the Lowest Common Ancestor of two nodes in a BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // Base case: If root is null, return null
        if (root == NULL) 
        {
            return NULL;
        }             


        // Case 1: If both p and q are less than the current node's value,
        // then LCA must be in the left subtree
        if (p->val < root->val && q->val < root->val) 
        {
            // Recursively find LCA in the left subtree
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns; // Return the result from the left subtree
        } 


        // Case 2: If both p and q are greater than the current node's value,
        // then LCA must be in the right subtree
        else if (p->val > root->val && q->val > root->val) 
        {
            // Recursively find LCA in the right subtree
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns; // Return the result from the right subtree
        }


        // Case 3: If one node is in the left subtree and the other is in the right subtree,
        // then the current node is the LCA
        else 
        {
            return root; // Return the current node as the LCA
        }

        // Return the current node as the LCA (this line is unreachable)
        return root;
    }





    // 2.******* Using Java *******

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) 
    {
        // base 
        if(root == null)
        {
            return null;
        }    

        // case 1 : p & q comes in left subtree
        if((p.val < root.val) && (q.val < root.val))
        {
            return lowestCommonAncestor(root.left,p,q);
        }

        // case 2 : p & q comes in right subtree
        else if((p.val > root.val) && (q.val > root.val))
        {
            TreeNode rightAns = lowestCommonAncestor(root.right,p,q);
            return rightAns;
        }

        // case 3 : both on opposite sub tree 
        else 
        {
            return root;
        }

        // return root;
    }