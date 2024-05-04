// Leet-Code : Q.No => 652 => Find Duplicate Subtrees => 4th May


    //  Binary tree + traversal + hashmap + string  


    // 1.******* Using C++ *******  

    vector<TreeNode*> ans;  // Vector to store the duplicate subtrees
    unordered_map<string, int> subTreeMap;  // Map to store the subtrees and their frequencies

    // Function to perform preorder traversal and detect duplicate subtrees
    string preOrder(TreeNode* root) 
    {
        // Base case: If the node is null, return "N"
        if(!root) 
        {
            return "N";
        }

        string curr = to_string(root->val);  // Convert the current node's value to string

        // Recursively traverse the left and right subtrees
        string l = preOrder(root->left);
        string r = preOrder(root->right);

        // Construct a unique identifier for the current subtree
        string s = curr + "," + l + "," + r;

        // Check if the current subtree is already encountered
        if (subTreeMap.find(s) != subTreeMap.end()) 
        {
            // If the subtree is found and it's the first occurrence, add the root to the answer vector
            if (subTreeMap[s] == 1) 
            {
                ans.push_back(root);
            }
            subTreeMap[s]++; // Increment the frequency of the subtree
        } 
        else 
        {
            subTreeMap[s] = 1; // If the subtree is encountered for the first time, add it to the map
        }

        return s; // Return the unique identifier of the subtree
    }


    // Function to find duplicate subtrees in the given binary tree
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        preOrder(root); // Perform preorder traversal to detect duplicate subtrees
        return ans; // Return the vector containing the duplicate subtrees
    }





    // 2.******* Using Java ******* 

    List<TreeNode> ans = new ArrayList<>();
    Map<String, Integer> subTreeMap = new HashMap<>();

    String preOrder(TreeNode root)
    {
        // base case 
        if(root == null)
        {
            return "N";
        }

        String curr = String.valueOf(root.val);

        // Recurrsion 
        String left = preOrder(root.left);
        String right = preOrder(root.right);

        String s = curr + "," + left + "," + right;

         // Check if the current subtree is already encountered
        if (subTreeMap.containsKey(s)) 
        {
            // If the subtree is found and it's the first occurrence, add the root to the answer list
            if (subTreeMap.get(s) == 1) 
            {
                ans.add(root);
            }
            subTreeMap.put(s, subTreeMap.getOrDefault(s, 0) + 1); // Increment the frequency of the subtree
        } 
        else 
        {
            subTreeMap.put(s, 1); // If the subtree is encountered for the first time, add it to the map
        }

        return s;
    }

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) 
    {
        preOrder(root);
        return ans;        
    } 