// Leet-Code : Q.No => 987 => Vertical Order Traversal of a Binary Tree => 11th April 2024 


    //    HashMap + Binary Tree + DFS + BFS 


    // 1.******* Using C++ *******


    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans; // Stores the final answer
        queue<pair<TreeNode*, pair<int, int>>> q; // Queue to perform level order traversal (Node, {x-coordinate, y-coordinate})
        map<int, map<int, multiset<int>>> mp; // Map to store nodes based on their x-coordinate and y-coordinate

        // Push root node with initial coordinates (0, 0) into the queue
        q.push({root, {0, 0}});

        // Perform level order traversal
        while (!q.empty()) 
        {
            auto it = q.front(); // Retrieve the front element of the queue
            q.pop(); // Pop the front element
            TreeNode* N = it.first; // Node pointer
            int x = it.second.first; // x-coordinate of the node
            int y = it.second.second; // y-coordinate of the node

            // Insert the node value into the map based on its coordinates
            mp[x][y].insert(N->val);

            // If the left child exists, push it into the queue with updated coordinates (x-1, y+1)
            if (N->left != nullptr) 
            {
                q.push({N->left, {x - 1, y + 1}});
            }

            // If the right child exists, push it into the queue with updated coordinates (x+1, y+1)
            if (N->right != nullptr) 
            {
                q.push({N->right, {x + 1, y + 1}});
            }
        }

        // Traverse the map to retrieve nodes in vertical order
        for (auto co : mp) 
        {
            vector<int> col; // Vector to store node values in the same column
            // Traverse the inner map to retrieve nodes at the same x-coordinate
            for (auto c : co.second) 
            {
                // Append node values to the column vector
                col.insert(col.end(), c.second.begin(), c.second.end());
            }
            // Append the column vector to the final answer
            ans.push_back(col);
        }

        // Return the final answer
        return ans;        
    }