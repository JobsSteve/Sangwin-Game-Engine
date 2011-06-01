#ifndef EVENTMANAGER_H
#define	EVENTMANAGER_H

#include "Action.h"
#include "HashMap.h"

#include <pthread.h>

/**
 * The EventHandler handles user input events (i.e touch, button press) as well
 * as events, like collisions, from within the engine.
 *
 * Events can be any format, but should extend the Event class. Actions can be
 * added which respond to a particular Event type as they are pulled out of the
 * event queue.
 *
 * Events are handled concurrently, which means the queue cannot be
 * modified whilst Events are being added or removed.
 *
 * EventHandler is a Singleton.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Events
 */
class EventHandler {

private:

    static EventHandler* inst; ///< instance of this class

    SPtr<HashMap<SPtr<Queue<SPtr<Event> > > > > events; ///< Event Queues. Each Event is held in a separate queue, based on type
    SPtr<HashMap<SPtr<ArrayList<SPtr<Action> > > > > actions; ///< Action Lists. Each Action is held in a separate list, based on type

    pthread_mutex_t postMutex; ///< mutex lock for the post function
    pthread_mutex_t updateMutex; ///< mutex lock for the update function

    /**
     * Default constructor. Creates empty maps for each set, and sets up
     * mutexes.
     */
    EventHandler();
    /**
     * Destructor.
     */
    ~EventHandler();

public:

    /**
     * Get the instance of this EventHandler, and create one if it does not yet
     * exist.
     * 
     * @return the instance of this EventHandler
     */
    static EventHandler* instance();

    /**
     * Listen out for the given Event type with given Action.
     * 
     * @param eventType Event type for this Action to listen for
     * @param action Action to perform on the given Event
     */
    void listen(const char* eventType, SPtr<Action> action);
    /**
     * Remove the given Action for the given Event type from the list.
     *
     * @param eventType Event type to remove Action from
     * @param action Action to remove for the given Event type
     */
    void ignore(const char* eventType, SPtr<Action> action);
    /**
     * Remove all Actions from the list.
     */
    void ignoreAll();
    /**
     * Add a new Event for the given event type queue.
     *
     * @param eventType Event type to add this Event to
     * @param event Event to add to the given event queue
     */
    void postEvent(const char* eventType, SPtr<Event> event);
    /**
     * Perform all Actions for the Events currently in the queues, then remove
     * the Events from the queues.
     */
    void update();
};

#endif	/* EVENTMANAGER_H */

