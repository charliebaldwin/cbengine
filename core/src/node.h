
class Node {
protected:
    virtual float GetOutput();    
    
    void ConnectInputNode(Node* inputNode, int index);
    void DisconnectInputNode(int index);

private:
    Node* inputNodes[6];
}