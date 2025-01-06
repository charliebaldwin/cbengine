#include "node.h"
#include "imnodes.h"

int Node::nextID = 0;
bool Node::showIDs = false;
ImColor Node::titleColor = ImColor((float)1.0, (float)0.0, (float)0.4);
std::vector<NodePin*> Node::pinsList;


Node::Node(std::string name)
: name(name) {
    id = nextID++;

    numInputs = 2;
    numOutputs = 1;

    CreateInputPins(numInputs);
    CreateOutputPins(numOutputs);

    printf("ran constructor\n");
}

void Node::CreateInputPins(int numPins) {
    for (int i=0; i<numPins; i++) {
        int pinID = nextID++;
        NodePin newPin = {
            pinID,      // ID
            i,          // index within node's inputs
            "input",    // title
            nullptr,    // connected Pin pointer
            nullptr,    // connected Node pointer (obsolete?)
            this        // parent Node pointer
        };
        inputPins[i] = newPin;
        pinsList.push_back(&inputPins[i]);
    }
}
void Node::CreateOutputPins(int numPins) {
    for (int i=0; i<numPins; i++) {
        int pinID = nextID++;
        NodePin newPin = {
            pinID,      // ID
            i,          // index within node's outputs
            "output",    // title
            nullptr,    // connected Pin pointer
            nullptr,    // connected Node pointer (obsolete?)
            this        // parent Node pointer
        };
        outputPins[i] = newPin;
        pinsList.push_back(&outputPins[i]);
    }
}

float Node::GetOutput() {
    return 0.0;
}

void Node::ConnectInputPin(NodePin* inputPin, int index) { 
    inputPins[index].connectedPin = inputPin;
}
void Node::DisconnectInputPin(int index) {

}

Node* Node::GetPinParentNode(int pinID) {
    for (int i=0; i<pinsList.size(); i++) {
        if (pinsList[i]->id == pinID) {
            return pinsList[i]->parentNode;
        }
    }
    return nullptr;
}
NodePin* Node::GetPinByID(int pinID) {
    for (int i=0; i<pinsList.size(); i++) {
        if (pinsList[i]->id == pinID) {
            return pinsList[i];
        }
    }
    return nullptr;
}

float Node::GetInputValue(NodePin inputPin) {
    if (inputPin.connectedPin != nullptr) {
        return inputPin.connectedPin->parentNode->GetOutput();
    } else {
        return 0.0;
    }
}

void Node::DrawTitleBar() {

    ImNodes::BeginNodeTitleBar();

    ImGui::TextUnformatted(name.c_str());

    if (showIDs) {
        ImGui::SameLine();
        ImGui::TextUnformatted(std::to_string(id).c_str());
    }

    ImNodes::EndNodeTitleBar();
}

void Node::DrawBody() {

    // OUTPUT
    for (int i=0; i<numOutputs; i++) {
        ImNodes::BeginOutputAttribute(outputPins[i].id);
        ImGui::Text(outputPins[i].title.c_str());
        if (showIDs) {
            ImGui::SameLine();
            ImGui::TextUnformatted(std::to_string(outputPins[i].id).c_str());
        }
        ImNodes::EndOutputAttribute();
    }

    ImGui::Dummy(ImVec2(100.0f, 15.0f));

    // INPUTS
    for (int i=0; i<numInputs; i++) {
        ImNodes::BeginInputAttribute(inputPins[i].id);
        ImGui::Text(inputPins[i].title.c_str());
        if (showIDs) {
            ImGui::SameLine();
            ImGui::TextUnformatted(std::to_string(inputPins[i].id).c_str());
        }
        ImNodes::EndInputAttribute();
    }

}

void Node::DrawNode() {
    ImNodes::PushColorStyle(ImNodesCol_TitleBar, titleColor);

    ImNodes::BeginNode(id);

    if (name != "") {
        this->DrawTitleBar();
    }
    this->DrawBody();

    ImNodes::EndNode();

    ImNodes::PopColorStyle();

}

void Node::DrawPinLinks() {
    for (int i=0; i<pinsList.size(); i++){
        if (pinsList[i]->connectedPin != nullptr) {
            int firstID = pinsList[i]->connectedPin->id;
            int secondID = pinsList[i]->id;
            ImNodes::Link(i, firstID, secondID);
        }
    }
}
void Node::ToggleIDDisplay() {
    showIDs = !showIDs;
}