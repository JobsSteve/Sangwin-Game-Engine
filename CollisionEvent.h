#ifndef COLLISIONEVENT_H
#define	COLLISIONEVENT_H

#include "Event.h"
#include "Bound.h"
#include "Vec3.h"

/**
 * The CollisionEvent class is a specific kind of engine Event which deals with
 * object collisions. CollisionEvents come in 3 forms: Collision Enter,
 * Collision and Collision Exit. This gives the programmer a good amount of
 * control over what to do when Collisions occur.
 *
 * CollisionEvents do not need to be created manually: they are created and
 * passed to the EventHandler by the CollisionDetector.
 *
 * CollisionEvents change state as the collision they handle changes. They also
 * hold pointers to the Bound Nodes that they are handling the collision
 * between.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Events
 */
class CollisionEvent: public Event {

public:

    /**
     * Describes what type of Collision this Event is.
     */
    enum EventType {
        COLLISION_ENTER, ///< Fired when two objects first collide
        COLLISION, ///< Fired continuously whilst two objects are colliding
        COLLISION_EXIT ///< Fired when two objects have finished colliding
    };

    bool inUse; ///< whether or not this Event has been used before
    EventType type; ///< Current type of this CollisionEvent
    SPtr<Bound<Vec3> > A; ///< First collider object this event is handling
    SPtr<Bound<Vec3> > B; ///< Second collider object this event is handling

    /**
     * Default constructor. Null collider pointers and event not in use.
     */
    CollisionEvent();
    /**
     * Copy constructor. Creates SHALLOW copies of collider objects.
     *
     * @param rhs CollisionEvent to copy from
     */
    CollisionEvent(const CollisionEvent& rhs);
    /**
     * Assignment operator. Creates SHALLOW copies of collider objects.
     *
     * @param rhs CollisionEvent to copy from
     * @return
     */
    CollisionEvent& operator=(const CollisionEvent& rhs);
    /**
     * Destructor.
     */
    ~CollisionEvent();

    /**
     * Return the type of this CollisionEvent.
     *
     * @return type
     */
    inline EventType getType();
    /**
     * Return the first collider this CollisionEvent is handling.
     *
     * @return first collider
     */
    inline SPtr<Bound<Vec3> > getA();
    /**
     * Return the second collider this CollisionEvent is handling.
     *
     * @return second collider
     */
    inline SPtr<Bound<Vec3> > getB();
    /**
     * Check if this CollisionEvent is handling a collision between the given
     * parameters.
     *
     * @param a first collider
     * @param b second collider
     * @return true if this CollisionEvent is handling collisions between a and
     * b, false if not.
     */
    bool isCollisionBetween(const SPtr<Bound<Vec3> >& a, const SPtr<Bound<Vec3> >& b);
};

//INLINE FUNCTION DEFINITIONS

inline CollisionEvent::EventType CollisionEvent::getType() {

    return type;
}


inline SPtr<Bound<Vec3> > CollisionEvent::getA() {

    return A;
}


inline SPtr<Bound<Vec3> > CollisionEvent::getB() {

    return B;
}

#endif	/* COLLISIONEVENT_H */

