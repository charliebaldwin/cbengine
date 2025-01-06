#include "node.h"

class AddNode : public Node {
public:
    AddNode(std::string name);

    void DrawBody() override;

    float GetOutput() override;

};