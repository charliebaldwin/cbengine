#include "node.h"

class ViewerNode : public Node{
public:
    ViewerNode(std::string name);

    void DrawBody() override;
};