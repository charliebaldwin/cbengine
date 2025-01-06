#include "node.h"

class ConstantNode : public Node{
public:

    float constValue;

    ConstantNode(std::string name, int value);

    float GetOutput() override;
    void DrawBody() override;
};