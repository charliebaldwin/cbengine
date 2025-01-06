#pragma once

#include <string>
#include <vector>

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

    static Node* GetPinParentNode(int pinID);

    float GetInputValue(NodePin inputPin);

    void DrawTitleBar();
    virtual void DrawBody();
    void DrawNode();

    std::string name;


protected:
    int numInputs;
    NodePin inputPins[10];
    NodePin outputPin;

    int id;

    static int nextID;
    static std::vector<NodePin*> pinsList;
};