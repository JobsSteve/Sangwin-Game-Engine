#ifndef ACTION_H
#define	ACTION_H

#include "Queue.h"
#include "Event.h"

/**
 * The Action class is the main subclass for all actions used in the
 * EventHandler. It provides a basic interface to ensure that each Action has
 * the required functionality to work with the engine.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Events
 */
class Action: public Object {

public:

    bool isActive; ///< Whether or not this Action is in use.

	/**
	 * Default constructor.
	 */
	Action() {}
	/**
	 * Copy constructor.
	 *
	 * @param rhs Action to copy from
	 */
	Action(const Action& rhs) {}

    /**
     * Perform the given Event Queue on this Action.
     *
     * @param events queue of events
     */
    virtual void perform(SPtr<Queue<SPtr<Event> > > events) = 0;
};


#endif	/* ACTION_H */

