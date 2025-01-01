#include "node.h"
#include "imnodes.h"

int Node::nextID = 0;


Node::Node(std::string name)
: name(name) {

    id = nextID++;

    for (int i=0; i<5; i++) {
        int pinID = nextID++;
        NodePin newPin = {
            pinID,
            "input",
            nullptr
        };
        inputs[i] = newPin;
    }

    printf("ran constructor\n");
}

float Node::GetOutput() {
    return 0.0;
}

void Node::ConnectInputNode(Node* inputNode, int index) { 
    inputs[index].connectedNode = inputNode;
}
void Node::DisconnectInputNode(int index) {

}

void Node::DrawTitleBar() {

    ImNodes::BeginNodeTitleBar();

    ImGui::TextUnformatted(name.c_str());
    ImGui::SameLine();
    ImGui::TextUnformatted(std::to_string(id).c_str());

    ImNodes::EndNodeTitleBar();

    ImGui::Dummy(ImVec2(80.0f, 45.0f));
}

void Node::DrawBody() {

    for (int i=0; i<5; i++) {
        ImNodes::BeginInputAttribute(inputs[i].id);

        ImGui::Text(inputs[i].title.c_str());
        ImGui::SameLine();
        ImGui::TextUnformatted(std::to_string(inputs[i].id).c_str());

        ImNodes::EndInputAttribute();
    }

}

void Node::DrawNode() {
    ImNodes::BeginNode(id);

    this->DrawTitleBar();
    this->DrawBody();

    ImNodes::EndNode();
}