#include "node.h"
#include "imnodes.h"

int Node::nextID = 0;
std::vector<NodePin*> Node::pinsList;


Node::Node(std::string name)
: name(name) {

    numInputs = 2;

    id = nextID++;

    for (int i=0; i<numInputs; i++) {
        int pinID = nextID++;
        NodePin newPin = {
            pinID,
            i,
            "input",
            nullptr,
            this
        };
        inputPins[i] = newPin;
        pinsList.push_back(&inputPins[i]);
    }

    int outputPinID = nextID++;
    outputPin = {
        outputPinID,
        0,
        "output",
        nullptr,
        this
    };
    pinsList.push_back(&outputPin);


    printf("ran constructor\n");
}

float Node::GetOutput() {
    return 0.0;
}

void Node::ConnectInputNode(Node* inputNode, int index) { 
    inputPins[index].connectedNode = inputNode;
}
void Node::DisconnectInputNode(int index) {

}

Node* Node::GetPinParentNode(int pinID) {
    for (int i=0; i<pinsList.size(); i++) {
        if (pinsList[i]->id == pinID) {
            return pinsList[i]->parentNode;
        }
    }
    return nullptr;
}

float Node::GetInputValue(NodePin inputPin) {
    if (inputPin.connectedNode != nullptr) {
        return inputPin.connectedNode->GetOutput();
    } else {
        return 0.0;
    }
}

void Node::DrawTitleBar() {

    ImNodes::BeginNodeTitleBar();

    ImGui::TextUnformatted(name.c_str());
    ImGui::SameLine();
    ImGui::TextUnformatted(std::to_string(id).c_str());

    ImNodes::EndNodeTitleBar();
}

void Node::DrawBody() {

    // OUTPUT
    ImNodes::BeginOutputAttribute(outputPin.id);
    ImGui::Text(outputPin.title.c_str());
    ImGui::SameLine();
    ImGui::TextUnformatted(std::to_string(outputPin.id).c_str());
    ImNodes::EndOutputAttribute();


    ImGui::Dummy(ImVec2(100.0f, 15.0f));

    // INPUTS
    for (int i=0; i<numInputs; i++) {
        ImNodes::BeginInputAttribute(inputPins[i].id);
        ImGui::Text(inputPins[i].title.c_str());
        ImGui::SameLine();
        ImGui::TextUnformatted(std::to_string(inputPins[i].id).c_str());
        ImNodes::EndInputAttribute();
    }

}

void Node::DrawNode() {
    ImNodes::BeginNode(id);

    this->DrawTitleBar();
    this->DrawBody();

    ImNodes::EndNode();
}