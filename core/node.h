#pragma once

#include <string>
#include <vector>
#include "imnodes.h"
#include "imgui.h"

class Node;

struct NodePin {
    int id;
    int index;
    std::string title;
    NodePin* connectedPin;
    Node* connectedNode;
    Node* parentNode;
};

class Node {
public:

    Node(std::string name);

    virtual float GetOutput();    
    
    void ConnectInputPin(NodePin* inputPin, int index);
    void DisconnectInputPin(int index);

    static Node* GetPinParentNode(int pinID);
    static NodePin* GetPinByID(int pinID);

    float GetInputValue(NodePin inputPin);

    void DrawTitleBar();
    virtual void DrawBody();
    void DrawNode();

    std::string name;

    static void DrawPinLinks();
    static void ToggleIDDisplay();

    static bool showIDs;


protected:
    int numInputs;
    int numOutputs;
    NodePin inputPins[10];
    NodePin outputPins[10];

    void CreateInputPins(int numPins);
    void CreateOutputPins(int numPins);

    int id;

    static int nextID;
    static std::vector<NodePin*> pinsList;

    static ImColor titleColor;

};