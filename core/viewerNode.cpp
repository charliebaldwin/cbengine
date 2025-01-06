#include "viewerNode.h"
#include "imnodes.h"

ViewerNode::ViewerNode(std::string name) : Node(name)
{
    numInputs = 1;
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

void ViewerNode::DrawBody() {

    float value = GetInputValue(inputPins[0]);

    ImGui::Value("value: ", value);

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