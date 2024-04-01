// Leet-Code : Q.No => 543 => Diameter of Binary Tree => 1st April 2024 


    //  using height of Binary Tree 


    // 1.******* Using C++ *******

    

    // **** Approaxch - 1 *** 

    // Function to calculate the height of a binary tree
    int height(TreeNode* root)
    {
        // Base case: if the root is NULL, the height is 0
        if(root == NULL)
        {
            return 0;
        }

        // Recursively calculate the height of the left & right subtree
        int leftHT = height(root->left);
        int rightHT = height(root->right);

        // Height of the current node is the maximum height of its subtrees + 1
        int Ht = max(leftHT,rightHT) + 1;

        return Ht;
    }

    // Function to calculate the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) 
    {
        // Base case: if the root is NULL, the diameter is 0 
        if(root == NULL)
        {
            return 0;
        }

        // Recursively calculate the diameter of the left subtree
        int opt1 = diameterOfBinaryTree(root->left);

        // Recursively calculate the diameter of the right subtree
        int opt2 = diameterOfBinaryTree(root->right);

        // Diameter passing through the current node = height of left subtree + height of right subtree
        int opt3 = height(root->left) + height(root->right);

        // Diameter of the tree is the maximum among the diameters calculated so far
        int dia = max(opt1 , max(opt2 , opt3));

        return dia;
    }




    // **** Approaxch - 2 *** 

    // Global variable to store the diameter of the binary tree
    int Dia = 0;

    // Function to calculate the height of a binary tree
    int height(TreeNode* root)
    {
        // base case 
        if(root == NULL)
        {
            return 0;
        }

        // Recursively calculate the height of the left & right subtree
        int lht = height(root->left);
        int rht = height(root->right);

        // Calculate the diameter passing through the current node
        int currDia = lht + rht;

        // Update the global variable Dia with the maximum diameter found so far
        Dia = max(Dia,currDia);

        // Return the height of the current node
        return (max(lht,rht) + 1);
    }

    // Function to calculate the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) 
    {
        // Call the height function to calculate the height of the binary tree
        height(root);

        // Return the diameter stored in the global variable Dia
        return Dia;
    }






    // 2.******* Using Java *******

    

    // **** Approaxch - 1 *** 

     public static int height(TreeNode root)
    {
        // base 
        if(root == null)
        {
            return 0;
        }

        int LH = height(root.left);
        int RH = height(root.right);

        return (Math.max(LH,RH) + 1);
    } 

    public int diameterOfBinaryTree(TreeNode root) 
    {
        // base 
        if(root == null)
        {
            return 0;
        }    

        int opt1 = diameterOfBinaryTree(root.left);

        int opt2 = diameterOfBinaryTree(root.right);

        int opt3 = height(root.left) + height(root.right);

        int dia = Math.max(opt1 , Math.max(opt2,opt3));

        return dia;
    }



    // **** Approaxch - 2 *** 

     int Dia = 0;

    public int height(TreeNode root)
    {
        // base 
        if(root == null)
        {
            return 0;
        }

        int lht = height(root.left);
        int rht = height(root.right);

        int curr_Dia = lht + rht;

        Dia = Math.max(Dia , curr_Dia);

        return (Math.max(lht,rht) + 1); 
    }

    public int diameterOfBinaryTree(TreeNode root) 
    {
        height(root);

        return Dia;
    }