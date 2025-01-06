#include "viewerNode.h"
#include "imnodes.h"

ViewerNode::ViewerNode(std::string name) : Node(name)
{
    id = nextID++;

    numInputs = 1;
    numOutputs = 0;

    CreateInputPins(numInputs);

    printf("ran constructor\n");
}

void ViewerNode::DrawBody() {

    float value = GetInputValue(inputPins[0]);

    ImGui::Value("value", value);

    ImGui::Dummy(ImVec2(20.0f, 5.0f));

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