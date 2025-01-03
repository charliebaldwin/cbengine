#include <string>

class Node;

struct NodePin {
    int id;
    int index;
    std::string title;
    Node* connectedNode;
    Node* parentNode;
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
    NodePin inputPins[2];
    NodePin outputPin;

    int id;
    std::string name;

    static int nextID;
};