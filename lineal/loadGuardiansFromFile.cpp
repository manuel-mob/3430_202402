#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

struct Guardian {
    std::string name;
    int powerLevel;
    std::string mainMaster;
    std::string village;
    std::vector<Guardian*> aprendices;
};

struct Node {
    Guardian* guardian;
    Node* left;
    Node* right;
};

class GuardiansTree {
public:
    Node* rootBinary;
    GuardiansTree() : root(nullptr) {
        rootBinary = nullptr;
    }


    void insertGuardian(const std::string& name, const std::string& powerLevel, const std::string& mainMaster, const std::string& village) {
        Guardian* guardian = new Guardian;
        guardian->name = name;
        guardian->powerLevel = stoi(powerLevel);
        guardian->mainMaster = mainMaster;
        guardian->village = village;
        guardians.push_back(guardian);

        insertBinary(guardian);
        // If the mainMaster Guardian is found, add the guardian as an Aprendiz (apprentice)
        if (root == nullptr) {
            root = guardian;
            std::cout << "root" << std::endl;
        }
        else {
            Guardian* master = findGuardian(mainMaster);
            if(master != nullptr) {
                master->aprendices.push_back(guardian);
            }
        }
    }

    void loadGuardiansFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return;
        }
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name, mainMaster, village;
            std::string powerLevel;
            std::getline(iss, name, ',');
            std::getline(iss, powerLevel , ',');
            std::getline(iss, mainMaster, ',');
            std::getline(iss, village);
            insertGuardian(name, powerLevel, mainMaster, village);
            
        }
        file.close();
    }

    void printGuardians() {
        printGuardian(root, 0);
    }

    Guardian* getRoot(){
        return root;
    }

    Node* getRootBinary(){
        return rootBinary;
    }

    Guardian* findGuardianFromVillage(Guardian* guardian, const std::string& village) {
        if (guardian != nullptr) {
            if (strcmp(guardian->village.c_str(),village.c_str()) == 0) {
                //std::cout << guardian->village << " vs " << village << " " << strcmp(guardian->village.c_str(),village.c_str())  <<std::endl;
                return guardian;
            }
            for (Guardian* aprendiz : guardian->aprendices) {
                return findGuardianFromVillage(aprendiz, village);
            }
        }
        //return in case of village not found
        return nullptr;
    }

        void insertBinary(Guardian* guardian) {
        Node* newNode = new Node;
        newNode->guardian = guardian;
        newNode->left = NULL;
        newNode->right = NULL;
        if (rootBinary == NULL) {
            rootBinary = newNode;
        }
        else {
            Node* current = rootBinary;
            while (true) {
                if (guardian->powerLevel < current->guardian->powerLevel) {
                    if (current->left == NULL) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else {
                    if (current->right == NULL) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            std::cout << "[" << node->guardian->powerLevel << "]"  << node->guardian->name  << " " << std::endl;
            inorderTraversal(node->right);
        }
    }

    void preOrderTraversal(Node* node) {
        if (node != NULL) {
            std::cout << "[" << node->guardian->powerLevel << "]"  << node->guardian->name  << " " << std::endl;
            inorderTraversal(node->left);
            inorderTraversal(node->right);
        }
    }
    void postOrderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            inorderTraversal(node->right);
            std::cout << "[" << node->guardian->powerLevel << "]"  << node->guardian->name  << " " << std::endl;
        }
    }

    void printInorder() {
        inorderTraversal(rootBinary);
    }

   

private:
    std::vector<Guardian*> guardians;
    Guardian* root;

    Guardian* findGuardian(const std::string& name) {
        for (Guardian* guardian : guardians) {
            if (guardian->name == name) {
                return guardian;
            }
        }
        return nullptr;
    }

    void updateTreeStructure() {
        for (Guardian* guardian : guardians) {
            if (guardian->mainMaster != "") {
                Guardian* master = findGuardian(guardian->mainMaster);
                if (master != nullptr) {
                    master->aprendices.push_back(guardian);
                }
            }
            else {
                root = guardian;
            }
        }
    }

    void printGuardian(Guardian* guardian, int indent) {
        if (guardian != nullptr) {
            std::cout << std::string(indent, ' ') << "- " << guardian->name << " (Power Level: " << guardian->powerLevel << ", Village: " << guardian->village << ")" << std::endl;
            for (Guardian* aprendiz : guardian->aprendices) {
                printGuardian(aprendiz, indent + 4);
            }
        }
    }
};




class BinaryTree {
private:
    Node* root;
public:
    BinaryTree() {
        root = NULL;
    }

    void insertBinary(Guardian* guardian) {
        Node* newNode = new Node;
        newNode->guardian = guardian;
        newNode->left = NULL;
        newNode->right = NULL;
        if (root == NULL) {
            root = newNode;
        }
        else {
            Node* current = root;
            while (true) {
                if (guardian->powerLevel < current->guardian->powerLevel) {
                    if (current->left == NULL) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else {
                    if (current->right == NULL) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    void inorderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            std::cout << "[" << node->guardian->powerLevel << "]"  << node->guardian->name  << " " << std::endl;
            inorderTraversal(node->right);
        }
    }

    void preOrderTraversal(Node* node) {
        if (node != NULL) {
            std::cout << "[" << node->guardian->powerLevel << "]"  << node->guardian->name  << " " << std::endl;
            inorderTraversal(node->left);
            inorderTraversal(node->right);
        }
    }
    void postOrderTraversal(Node* node) {
        if (node != NULL) {
            inorderTraversal(node->left);
            inorderTraversal(node->right);
            std::cout << "[" << node->guardian->powerLevel << "]"  << node->guardian->name  << " " << std::endl;
        }
    }

    void printInorder() {
        inorderTraversal(root);
    }
};


int main() {
    GuardiansTree tree;
    //Binary Tree

    
    tree.loadGuardiansFromFile("guardians.csv");
    tree.printGuardians();
    Guardian* master = new Guardian;
    
    std::string city = "Tesla Capital";
    std::cout << "The City is " << city << std::endl;
    Guardian* root = tree.getRoot();
    std::cout << "The Master is " << root->name << std::endl;
    master = tree.findGuardianFromVillage(root,city);
    if (master ==  nullptr) {
        std::cout << "Master is dead" << std::endl;
    }
    std::cout << "The master of " <<  city << " is " << master->name << std::endl;
    std::cout << master->name << " is master of :";
    for (Guardian* aprendiz : master->aprendices) {
        std::cout << aprendiz->name << ", ";
    }

    //Creating ranking tree
    Node* rootbinary = tree.getRootBinary();
    tree.preOrderTraversal(rootbinary);
    std::cout << std::endl;
    tree.postOrderTraversal(rootbinary);
    std::cout << std::endl;
    tree.inorderTraversal(rootbinary);
    std::cout << std::endl;
    tree.printInorder();
    
    return 0;
}
