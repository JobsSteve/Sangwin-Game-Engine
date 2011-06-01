#ifndef COLLISIONDETECTOR_H
#define	COLLISIONDETECTOR_H

#include "Object.h"
#include "LinkedList.h"
#include "CollisionEvent.h"
#include "GetNode.h"

/**
 * The CollisionDetector checks the scenegraphs BoundingVolume heirarchy for
 * collisions.
 *
 * The collision detection algorithm used requires the scenegraph to be ordered
 * with leaf nodes on the left of non-leaf nodes.
 *
 * THIS COLLISION DETECTOR CAN ONLY BE USED WITH 3D SCENEGRAPHS.
 * 
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Events
 */
class CollisionDetector: public Object {

private:

    SPtr<LinkedList<SPtr<CollisionEvent> > > events; ///< list of events found on the last scenegraph traversal

    //Convenience variables, used for speed
    SPtr<Bound<Vec3> > collider;
    SPtr<CollisionEvent> evt;

    /**
     * Recursively checks subtree of the given Bound Node for collisions, and
     * posts them to the events list if and when they are found.
     *
     * @param boundNode Bound to check the subtree of
     */
    void checkCollisions(SPtr<Bound<Vec3> > boundNode);
    /**
     * Recursively move up the tree to the root from the given parent Node,
     * checking for collisions at each level.
     *
     * @param parent parent of the Node previously accended from
     * @param child child previously accended from. Passing this along with the
     * parent allows all links to the left of the child to be ignored.
     */
    void accend(SPtr<Node> parent, SPtr<Node> child);
    /**
     * Check to see if the given Node and its children are 'colliders' i.e Nodes
     * with BoundingVolumes which are leaves.
     *
     * When one is found, check it for collisions by accending the tree.
     *
     * @param boundNode Node to check
     */
    void findColliders(SPtr<Bound<Vec3> > boundNode);

public:

    /**
     * Default constructor. Creates an empty LinkedList of CollisionEvents.
     */
    CollisionDetector();
    /**
     * Copy constructor. Creates a SHALLOW copy of the CollisionEvent list.
     *
     * @param rhs CollisionDetector to copy from
     */
    CollisionDetector(const CollisionDetector& rhs);
    /**
     * Assignment operator. Creates a SHALLOW copy of the CollisionEvent list.
     *
     * @param rhs CollisionDetector to copy from
     * @return this
     */
    CollisionDetector& operator=(CollisionDetector& rhs);
    /**
     * Destructor.
     */
    ~CollisionDetector();

    /**
     * Check for collisisions from the given Node and down its tree. Adding
     * CollisionEvents to the EventHandler as they are found.
     *
     * @param root Root Node to start checking Collisions from
     */
    void detect(SPtr<Node> root);
};


#endif	

