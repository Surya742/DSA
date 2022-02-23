/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*> db;
    void helper(Node* head, Node* node){
        if(!node)
            return;
        head->val = node->val;
        db[head->val] = head;
        for(auto it:node->neighbors){
            if(db.count(it->val)){
                head->neighbors.push_back(db[it->val]);
                continue;
            }
            Node* ptr = new Node();
            head->neighbors.push_back(ptr);
            helper(ptr,it);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL; 
        }
        Node* head = new Node();
        helper(head,node);
        return head;
    }
};