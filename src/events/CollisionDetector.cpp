#include "headers/events/CollisionDetector.h"
#include "headers/events/EventHandler.h"

CollisionDetector::CollisionDetector()
:events(new LinkedList<SPtr<CollisionEvent> >()),
 collider(),
 evt()
{}


CollisionDetector::CollisionDetector(const CollisionDetector& rhs)
:events(rhs.events),
 collider(new Bound(*rhs.collider)),
 evt(new CollisionEvent(*rhs.evt))
{}


CollisionDetector& CollisionDetector::operator =(CollisionDetector& rhs) {

    events = rhs.events;
    *collider = *rhs.collider;
    *evt = *rhs.evt;
    
    return *this;
}


CollisionDetector::~CollisionDetector() {}


void CollisionDetector::checkCollisions(SPtr<Bound> boundNode) {

    bool evtReused = false;
    bool shouldRecurse = true;
    if(boundNode->getBounds().get()) {
        //Check if bound groups are the same, and if the given Bound collides
        //with the Bound being checked
        if(boundNode->boundGroup == collider->boundGroup &&
                boundNode->getBounds()->collides(*collider->getBounds())) {
            //Must be a leaf
            if(boundNode->isLeaf()) {
                //Convert CollisionEvent if it already exists
                for(int i=0; i<events->size(); i++) {
                    evt = events->get(i);
                    if(!evt->inUse && evt->isCollisionBetween(collider,boundNode)) {
                        //modify event
                        evtReused = true;
                        evt->type = CollisionEvent::COLLISION;
                        evt->inUse = evtReused;

                        break;
                    }
                }

                //Else, create a new event
                if(!evtReused) {
                    evt = SPtr<CollisionEvent>(new CollisionEvent());
                    evt->type = CollisionEvent::COLLISION_ENTER;
                    evt->inUse = true;
                    events->addLast(evt);
                }

                //fill out CollisionEvent and post to the EventHandler
                evt->A = collider;
                evt->B = boundNode;
                EventHandler::instance()->postEvent("CollisionEvent",evt);

                shouldRecurse = false;
            }
        }
        else {
            shouldRecurse = false;
        }

        //recurse if a collision has not yet been found
        if(shouldRecurse) {
            for(int i=0; i<boundNode->getChildren().size(); i++) {
                checkCollisions(boundNode->getChildren().get(i).smart_static_cast(SPtr<Bound>()));
            }
        }
    }
}


void CollisionDetector::accend(SPtr<Node> parent, SPtr<Node> child) {

    //If parent is not null
    if(parent.get()) {
        //Get the start index (the next child along from the one given)
        int start = parent->getChildren().indexOf(child) + 1;
        //Keep moving right along the child list
        for(int i=start; i<parent->getChildren().size(); i++) {
            //Check if this child collides with the current collider
            checkCollisions(parent->getChildren().get(i).smart_static_cast(SPtr<Bound>()));
        }
        //Move up the tree
        accend(parent->getParent(),parent);
    }
}


void CollisionDetector::findColliders(SPtr<Bound> boundNode) {

    //Check for collider
    if(boundNode->getBounds().get() && boundNode->isLeaf()) {
        /*
         * collider found! Accend the tree checking for collisions on all
         * subtrees to the right until the whole tree has been searched.
         */
        collider = boundNode;
        accend(boundNode->getParent(),boundNode);
    }
    else {
        //recurse, checking for colliders for each child of the given Node
        for(int i=0; i<boundNode->getChildren().size(); i++) {
            findColliders(boundNode->getChildren().get(i).smart_static_cast(SPtr<Bound>()));
        }
    }
}


void CollisionDetector::detect(SPtr<Node> root) {

    collider = SPtr<Bound>();
    findColliders(root.smart_static_cast(SPtr<Bound>()));

    for(int i=0; i<events->size(); i++) {
        evt = events->get(i);
        if(evt->inUse) {
            //reset
            evt->inUse = false;
        }
        else if(evt->type != CollisionEvent::COLLISION_EXIT) {
            //convert event to COLLISION_EXIT
            evt->type = CollisionEvent::COLLISION_EXIT;
            EventHandler::instance()->postEvent("CollisionEvent",evt);
        }
        else {
            events->remove(i);
        }
    }
}