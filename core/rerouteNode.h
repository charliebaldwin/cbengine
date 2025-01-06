#include "node.h"

class RerouteNode : public Node {
public:
    RerouteNode();

    void DrawBody() override;

    float GetOutput() override;

};