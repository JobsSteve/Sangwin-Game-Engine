#ifndef EVENT_H
#define	EVENT_H

#include "headers/utils/Object.h"

/**
 * The Event class provides a basic class that all Events should subclass.
 *
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Events
 */
class Event: public Object {

public:

	/**
	 * Default constructor.
	 */
	Event() {}
	/**
	 * Copy constructor.
	 *
	 * @param rhs Event to copy from
	 */
	Event(const Event& rhs) {}
};

#endif	/* EVENT_H */

