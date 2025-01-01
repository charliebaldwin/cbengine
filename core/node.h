#include <string>

struct NodePin {
    int id;
    std::string title;
    Node* connectedNode;
};

class Node {
public:

    Node(std::string name);

    virtual float GetOutput();    
    
    void ConnectInputNode(Node* inputNode, int index);
    void DisconnectInputNode(int index);

    void DrawTitleBar();
    void DrawBody();

    virtual void DrawNode();

private:
    NodePin inputs[5];

    int id;
    std::string name;

    static int nextID;
};