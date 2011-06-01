#ifndef ABSTRACTRENDERER_H
#define	ABSTRACTRENDERER_H

/**
 * The AbstractRender class provides the basic information required by any
 * renderer using the engine.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class AbstractRenderer {

public:

    static bool renderBounds;
    static int canvasWidth; ///< width of the canvas in use
    static int canvasHeight; ///< height of the canvas in use

    AbstractRenderer(){}
};

#endif	/* ABSTRACTRENDERER_H */

