#include "addNode.h"
#include "imnodes.h"

AddNode::AddNode(std::string name) : Node(name) {

    id = nextID++;

    numInputs = 2;
    numOutputs = 1;

    CreateInputPins(numInputs);
    CreateOutputPins(numOutputs);

    printf("ran constructor\n");
}

float AddNode::GetOutput() {
    float sum = 0;
    
    for (int i=0; i<numInputs; i++) {
        if (inputPins[i].connectedPin != nullptr) {
            sum += inputPins[i].connectedPin->parentNode->GetOutput();
        }
    }

    return sum;
}

void AddNode::DrawBody() {
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
    for (int i=0; i<numOutputs; i++) {
        ImNodes::BeginOutputAttribute(outputPins[i].id);
        ImGui::Text(outputPins[i].title.c_str());
        if (showIDs) {
            ImGui::SameLine();
            ImGui::TextUnformatted(std::to_string(outputPins[i].id).c_str());
        }
        ImNodes::EndOutputAttribute();
    }

}