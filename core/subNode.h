#include "node.h"

class SubNode : public Node {
public:
    SubNode(std::string name);

    void DrawBody() override;

    float GetOutput() override;

};