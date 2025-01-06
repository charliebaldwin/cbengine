#include "constantNode.h"
#include "imnodes.h"

ConstantNode::ConstantNode(std::string name, int value) : Node(name)
{
    constValue = value;

    numInputs = 0;
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

float ConstantNode::GetOutput() {
    return constValue;
}

void ConstantNode::DrawBody() {

    ImGui::Value("value: ", constValue);

    ImGui::Dummy(ImVec2(100.0f, 15.0f));

    // OUTPUT
    ImNodes::BeginOutputAttribute(outputPin.id);
    ImGui::Text(outputPin.title.c_str());
    ImGui::SameLine();
    ImGui::TextUnformatted(std::to_string(outputPin.id).c_str());
    ImNodes::EndOutputAttribute();

}