#ifndef NODE_H
#define	NODE_H

#include "ArrayList.h"

/**
 * The Node class is the base class for all scenegraph nodes. It provides the
 * functionality for attaching and detaching nodes. Children are reference
 * counted by the parent, but parents are not reference counted by the child.
 * This means that nodes do not delete their parents when they are removed, but
 * do delete the subtree that is beneath them.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class Node: public Object {

public:

    /**
     * Enum to describe the type of this Node. Used to check the type at
     * runtime.
     */
    enum NodeType {NODE, BOUND, SPATIAL, COLLIDER, VISUAL, GEOM};
    const char* name; ///< The name of this Node
    NodeType type; ///< The type of this Node, as defined in the enum.

    /**
     * Default constructor. Creates an empty list of children and no parent.
     * Name is the empty string.
     */
    Node();
    /**
     * Constructor that gives this Node a name from the given parameter. Child
     * and parent behaviour is as default.
     * 
     * @param aName Name for this Node
     */
    Node(const char* aName);
    /**
     * Copy constructor. Children are SHALLOW copies.
     *
     * @param rhs Node to copy from
     */
    Node(const Node& rhs);
    /**
     * Assignment operator. Children are SHALLOW copies.
     * 
     * @param rhs Node to copy from
     * @return this
     */
    Node& operator=(const Node& rhs);
    /**
     * Destructor.
     */
    virtual ~Node();

    /**
     * Return a SPtr to the parent of this Node.
     *
     * @return parent
     */
    inline SPtr<Node> getParent();
    /**
     * Search for a child of the given name in the subtree of this Node
     *
     * @param name Name of Node to search for
     * @return child, or null Node
     */
    SPtr<Node> findChild(const char* name);
    /**
     * Return this Node's children.
     *
     * @return ArrayList of children
     */
    inline ArrayList<SPtr<Node> >& getChildren();
    /**
     * Attach a child to this Node, if it is not already attached.
     * 
     * @param child child to attach
     */
    virtual void attachChild(SPtr<Node> child);
    /**
     * Detach the given child from this Node.
     * 
     * @param child child Node to detach
     */
    virtual void detachChild(const SPtr<Node>& child);
    /**
     * Detach the child node at the given index from this Node. If the index is
     * invalid, return a null Node.
     * 
     * @param i index
     * @return child, or null Node.
     */
    virtual SPtr<Node> detachChild(int i);
    /**
     * Give this Node a new parent.
     * 
     * @param newParent New parent of this Node
     */
    void reparent(Node& newParent);
    /**
     * Check to see if this Node is a leaf i.e it has no children.
     *
     * @return true if Node is a leaf, false if not
     */
    inline bool isLeaf();
    /**
     * Create a new, identical copy of this Node, detached from its parent.
     *
     * @return Copy of this Node.
     */
    virtual SPtr<Node> clone() = 0;
    /**
     * Create a new, identical copy of this Node and its subtree, detached
     * from its parent.
     *
     * @param parent This a recursive method, so parent is the Node to parent
     * the Node this is being called on to.
     * @return Copy of this Node, and its subtree.
     */
    virtual SPtr<Node> cloneTree(SPtr<Node>& parent) = 0;

protected:
    
    Node* parent;
    ArrayList<SPtr<Node> >* children;
};

//INLINE FUNCTION DEFINITIONS

inline SPtr<Node> Node::getParent() {

    return SPtr<Node>(parent);
}


inline ArrayList<SPtr<Node> >& Node::getChildren() {

    return *children;
}


inline bool Node::isLeaf() {

    return children->size() == 0;
}

#endif	/* NODE_H */

