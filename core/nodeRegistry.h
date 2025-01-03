#include "node.h"

class NodeRegistry {
public:

    NodeRegistry();

    std::vector<std::pair<int, NodePin>> pinIDs;
    std::vector<std::pair<int, int>> links;

    void RegisterNode(Node* node);
    void RegisterLink(int a, int b);

    Node* GetPinParent(int pinID);


};