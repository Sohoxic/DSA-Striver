string serialize(TreeNode* root) {
    if(!root) return "";
    string s = "";
    queue<TreeNode*> q;
    q.push(root)
    while(!q.empty){
        Treenode* top = q.front();
        q.pop();
        if(top==NULL)   s.append("#,");
        else s.append(top->data+",");
        if(top!=NULL){
            q.push(top->left);
            q.push(top->right);
        }
    }   
    return s;
}

TreeNode* deserialize(string data){
    if(data.size() == 0) return NULL; 
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str=='#'){
            node->left = NULL;  
        }
        else{
            TreeNode* newNode = new TreeNode(stoi(str));
            node->left = newNode;
            q.push(newNode);
        }
        getline(s, str, ',');
        if(str=='#'){
            node->left = NULL;  
        }
        else{
            TreeNode* newNode = new TreeNode(stoi(str));
            node->right = newNode;
            q.push(newNode);
        }

    }

    return root;
}

