/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // Two passes. First - map each original node to a newly created copy node. Second - Link each new node's next and random by referencing from the map
    // Node* copyRandomList(Node* head) {
    //     unordered_map<Node*, Node*> old_to_new;

    //     old_to_new[NULL] = NULL; // So that those pointers that were null originally point to null in the new list

    //     // Creating the hash map
    //     Node* old = head;
    //     while(old) {
    //         Node* newNode = new Node(old->val);
    //         old_to_new[old] = newNode;
    //         old = old->next;
    //     }

    //     // Attaching next and random nodes
    //     old = head;
    //     while(old) {
    //         Node* newNode = old_to_new[old];
    //         newNode->next = old_to_new[old->next];
    //         newNode->random = old_to_new[old->random];
    //         old = old->next;
    //     }

    //     return old_to_new[head];
    // }

    // Recursive approach
    unordered_map<Node*, Node*> old_to_new;

    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }

        // So that cycles due to random pointers don't cause an infinite loop
        if (old_to_new.count(head)) {
            return old_to_new[head];
        }

        // Create new node
        Node* newNode = new Node(head->val);

        // Map the old and new nodes
        old_to_new[head] = newNode;

        // The actual recursion to reach to the end and consequently, attach the next pointers to the copied list when recursion starts to return back
        newNode->next = copyRandomList(head->next);

        // Start connecting the random pointers. We have the map of all required nodes now
        newNode->random = old_to_new[head->random];

        return newNode;
    }
};
