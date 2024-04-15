// Leet-Code : Q.No => 652 => Find Duplicate Subtrees => 15th April 2024 


    //  


    // 1.******* Using C++ *******

    vector<TreeNode*> ans; // Global vector to store duplicate subtrees
    unordered_map<string,int> subTreeMap; // Map to store subtree strings and their counts

    string preOrder(TreeNode* root) 
    {
        // Base case: if the current node is NULL, return "N" to represent null node
        if (root == NULL) 
        {
            return "N";
        }

        // Convert the value of the current node to a string
        string curr = to_string(root->val);

        // Recursively traverse left and right subtrees and get their pre-order representations
        string l = preOrder(root->left);
        string r = preOrder(root->right);

        // Construct the pre-order string representation of the current subtree
        string s = curr + "," + l + "," + r; 

        // Check if the current subtree string is already present in the map
        if (subTreeMap.find(s) != subTreeMap.end()) 
        {
            // If it's already present, increment its count in the map
            subTreeMap[s]++;
            // If the count is 2, it means this is the second occurrence of the subtree, so add it to the result vector
            if (subTreeMap[s] == 2) 
            {
                ans.push_back(root);
            }
        } 
        else 
        {
            // If the subtree string is not present in the map, add it with count 1
            subTreeMap[s] = 1;
        }

        return s; // Return the pre-order string representation of the current subtree
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        // Call the preOrder function to find duplicate subtrees
        preOrder(root);
        return ans; // Return the vector containing duplicate subtrees
    }




    // 2.******* Using Java *******
