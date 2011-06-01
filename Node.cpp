#include "Node.h"
#include <string.h>

Node::Node()
:name(""),
 type(NODE),
 parent(0),
 children(new ArrayList<SPtr<Node> >())
{
    
}


Node::Node(const char* aName)
:name(aName),
 type(NODE),
 parent(0),
 children(new ArrayList<SPtr<Node> >())
{}


Node::Node(const Node& rhs)
:name(rhs.name),
 type(rhs.type),
 parent(rhs.parent),
 children(new ArrayList<SPtr<Node> >(*rhs.children))
{}


Node& Node::operator =(const Node& rhs) {

    Node* parentOrig = parent;
    name = rhs.name;
    parent = rhs.parent;
    delete parentOrig;
    type = rhs.type;
    *children = *rhs.children;

    return *this;
}


Node::~Node() {

    delete children;
}


SPtr<Node> Node::findChild(const char* name) {

    if(!strcmp(this->name,name)) {
        return SPtr<Node>(this);
    }

    Node* r = 0;
    SPtr<Node> result(r);
    for(int i=0; i<children->size(); i++) {
        result = children->get(i)->findChild(name);

        if(result.get()) {
            return result;
        }
    }
    return result;
}


void Node::attachChild(SPtr<Node> child) {

    if(!children->contains(child)) {
        child->parent = this;
        children->add(SPtr<Node>(child));
    }
}


void Node::detachChild(const SPtr<Node>& child) {

    if(children->contains(child)) {
        child->parent = 0;
        children->remove(child);
    }
}


SPtr<Node> Node::detachChild(int i) {

    if(i <= children->size() && i > 0) {
        children->get(i)->parent = 0;
        return children->remove(i);
    }
    return SPtr<Node>();
}


void Node::reparent(Node& newParent) {

    SPtr<Node> thisPointer(this);
    if(!newParent.children->contains(thisPointer)) {
        parent->detachChild(thisPointer);
        newParent.attachChild(thisPointer);
    }
}


