#include<iostream>
#include<vector>

class ListNode {
public:
    ListNode(): _isAtom(false), atomStrValue("") {}
    ListNode(std::string st): _isAtom(true), atomStrValue(st)  {}

    bool isAtom() { return _isAtom; }
    std::string getAtom() { return atomStrValue; }

    void addChildNode(ListNode *list) { children.push_back(list); }
    int numChildren() { return children.size(); }
    std::vector<ListNode *> getChildren() { return children; }

private:
    std::vector<ListNode *> children;
    bool _isAtom;
    std::string atomStrValue;
};
