#ifndef APP2_H
#define	APP2_H

#include "headers/scenegraph/App.h"

/**
 * App2 is an Appearance Object for 2D games. It inherits from the abstract
 * class App. The visual information for the attached Node is stored in this
 * object.
 *
 * @see App
 * @see Node
 * 
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class App2: public App {

public:

    /**
     * Default constructor for App2. Sets the inheritance to 0 and initialises
     * the Texture array.
     */
    App2()
    :App()
    {}
    /**
     * Copy constructor. Creates a SHALLOW copy of this App2.
     * 
     * @param rhs App2 to copy from
     */
    App2(const App2& rhs)
    :App(rhs)
    {}
    /**
     * Assignment operator. Creates a SHALLOW copy of this App2.
     *
     * @param rhs App2 to copy from
     * @return this
     */
    App2& operator=(const App2& rhs);

    /**
     * Add the given App's visual information to this App.
     *
     * @param app App to get visual information from
     */
    void add(App& app);
};

#endif	/* APP2_H */

