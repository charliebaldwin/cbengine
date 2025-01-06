#include "rerouteNode.h"
#include "imnodes.h"

RerouteNode::RerouteNode() : Node("") {

    id = nextID++;

    numInputs = 1;
    numOutputs = 1;

    CreateInputPins(numInputs);
    CreateOutputPins(numOutputs);

    printf("ran constructor\n");
}

float RerouteNode::GetOutput() {
    if (inputPins[0].connectedPin != nullptr) {
        return inputPins[0].connectedPin->parentNode->GetOutput();
    } else {
        return 0;
    }
}

void RerouteNode::DrawBody() {
    ImGui::Dummy(ImVec2(1.0f, 1.0f));

    // INPUTS
    ImNodes::BeginInputAttribute(inputPins[0].id);
    if (showIDs) {
        ImGui::SameLine();
        ImGui::TextUnformatted(std::to_string(inputPins[0].id).c_str());
    }
    ImNodes::EndInputAttribute();
    ImGui::SameLine();
    ImNodes::BeginOutputAttribute(outputPins[0].id);
    if (showIDs) {
        ImGui::SameLine();
        ImGui::TextUnformatted(std::to_string(outputPins[0].id).c_str());
    }
    ImNodes::EndOutputAttribute();

}