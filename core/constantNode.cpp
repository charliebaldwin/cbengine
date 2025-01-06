#include "constantNode.h"
#include "imnodes.h"

ConstantNode::ConstantNode(std::string name, int value) : Node(name)
{
    id = nextID++;
    constValue = value;

    numInputs = 0;
    numOutputs = 1;

    CreateOutputPins(numOutputs);

    printf("ran constructor\n");
}

float ConstantNode::GetOutput() {
    return constValue;
}

void ConstantNode::DrawBody() {

    //ImGui::Value("value", constValue);
    ImGui::SetNextItemWidth(80.0);
    ImGui::DragFloat("", &constValue);

    ImGui::Dummy(ImVec2(100.0f, 15.0f));

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

}