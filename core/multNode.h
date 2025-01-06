#include "node.h"

class MultNode : public Node {
public:
    MultNode(std::string name);

    void DrawBody() override;

    float GetOutput() override;

};