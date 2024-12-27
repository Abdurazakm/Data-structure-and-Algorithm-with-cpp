#include <iostream>
using namespace std;

// Structure to define a node in the Binary Search Tree (BST)
struct BinarySearchTree {
    int data;                        // Data stored in the node
    BinarySearchTree* left;          // Pointer to the left child
    BinarySearchTree* right;         // Pointer to the right child
};

// Function to insert a new node into the BST
void insertBST(BinarySearchTree*& RNP, BinarySearchTree* NNP) {
    int inserted = 0;               // Flag to check if the node is inserted
    BinarySearchTree* temp = RNP;   // Temporary pointer to traverse the tree
    if (RNP == nullptr) {           // If the tree is empty
        RNP = NNP;                  // Make the new node the root
    } else {
        while (inserted == 0) {     // Traverse the tree until the node is inserted
            if (temp->data > NNP->data) {  // Go to the left subtree if data is smaller
                if (temp->left == nullptr) {
                    temp->left = NNP;      // Insert as the left child
                    inserted = 1;          // Mark as inserted
                } else {
                    temp = temp->left;     // Move to the left child
                }
            } else if (temp->data < NNP->data) { // Go to the right subtree if data is larger
                if (temp->right == nullptr) {
                    temp->right = NNP;     // Insert as the right child
                    inserted = 1;          // Mark as inserted
                } else {
                    temp = temp->right;    // Move to the right child
                }
            }
        }
    }
}

// Function to create a new node with a given value
BinarySearchTree* CreateNode(int value) {
    BinarySearchTree* newNode = new BinarySearchTree();
    newNode->data = value;          // Set the data value
    newNode->left = nullptr;        // Initialize left child as null
    newNode->right = nullptr;       // Initialize right child as null
    return newNode;
}

// In-order traversal: Left -> Root -> Right (to display the BST in sorted order)
void inOrderTraversal(BinarySearchTree* rootptr) {
    if (rootptr != nullptr) {
        inOrderTraversal(rootptr->left);   // Visit left subtree
        cout << rootptr->data << " ";      // Print root data
        inOrderTraversal(rootptr->right);  // Visit right subtree
    }
}

// Function to delete a node with a given value in the BST
void deleteBST(BinarySearchTree* RNP, BinarySearchTree* PDNP, int x) {
    // RNP: Current node being checked
    // PDNP: Parent of the current node
    // x: The value to delete

    BinarySearchTree* DNP; // Pointer to the node to be deleted

    if (RNP == nullptr) {
        // Base case: Node not found
        cout << "Data Not Found" << endl;
    } else if (RNP->data > x) {
        // Value is smaller; search in the left subtree
        deleteBST(RNP->left, RNP, x);
    } else if (RNP->data < x) {
        // Value is larger; search in the right subtree
        deleteBST(RNP->right, RNP, x);
    } else {
        // Node to delete found (RNP->data == x)
        DNP = RNP;

        if (DNP->left == nullptr && DNP->right == nullptr) {
            // Case 1: Node is a leaf (no children)
            if (PDNP == nullptr) {
                RNP = nullptr; // Root node case
            } else if (PDNP->left == DNP) {
                PDNP->left = nullptr; // Unlink the node
            } else {
                PDNP->right = nullptr; // Unlink the node
            }
            delete DNP; // Free memory
        } else if (DNP->left != nullptr) {
            // Case 2: Node has a left child
            PDNP = DNP;
            DNP = DNP->left;

            // Find the rightmost node in the left subtree (predecessor)
            while (DNP->right != nullptr) {
                PDNP = DNP;
                DNP = DNP->right;
            }

            // Replace value and recursively delete the predecessor
            RNP->data = DNP->data;
            deleteBST(DNP, PDNP, DNP->data);
        } else {
            // Case 3: Node has a right child
            PDNP = DNP;
            DNP = DNP->right;

            // Find the leftmost node in the right subtree (successor)
            while (DNP->left != nullptr) {
                PDNP = DNP;
                DNP = DNP->left;
            }

            // Replace value and recursively delete the successor
            RNP->data = DNP->data;
            deleteBST(DNP, PDNP, DNP->data);
        }
    }
}

int main() {
    // Create and insert nodes into the BST
    BinarySearchTree* rootptr = nullptr;
    int values[] = {10, 5, 15, 3, 7, 13, 17};
    for (int value : values) {
        BinarySearchTree* newNode = CreateNode(value);
        insertBST(rootptr, newNode);
    }

    // Display the BST in sorted order (before deletion)
    cout << "In-order Traversal Before Deletion: ";
    inOrderTraversal(rootptr);
    cout << endl;

    // Delete a node (e.g., 10)
    cout << "Deleting node 10..." << endl;
    deleteBST(rootptr, nullptr, 10);

    // Display the BST in sorted order (after deletion)
    cout << "In-order Traversal After Deletion: ";
    inOrderTraversal(rootptr);
    cout << endl;

    return 0;
}
