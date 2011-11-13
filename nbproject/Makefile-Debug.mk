#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/cameras/Cam.o \
	${OBJECTDIR}/src/appearance/Alpha.o \
	${OBJECTDIR}/src/scenegraph/Collider.o \
	${OBJECTDIR}/src/scenegraph/Node.o \
	${OBJECTDIR}/src/resource/Token.o \
	${OBJECTDIR}/src/appearance/PolyAtt.o \
	${OBJECTDIR}/src/scenegraph/Spatial.o \
	${OBJECTDIR}/src/collision/BoundingVolume.o \
	${OBJECTDIR}/src/lights/SpotLight.o \
	${OBJECTDIR}/src/collision/BoundingSphere.o \
	${OBJECTDIR}/src/events/EventHandler.o \
	${OBJECTDIR}/src/resource/ResourceManager.o \
	${OBJECTDIR}/src/lights/DirLight.o \
	${OBJECTDIR}/src/utils/Object.o \
	${OBJECTDIR}/src/scenegraph/Trimesh.o \
	${OBJECTDIR}/src/maths/Vec.o \
	${OBJECTDIR}/src/scenegraph/Geom.o \
	${OBJECTDIR}/src/lights/Light.o \
	${OBJECTDIR}/src/lights/LightBulb.o \
	${OBJECTDIR}/src/maths/Mat4.o \
	${OBJECTDIR}/src/scenegraph/App.o \
	${OBJECTDIR}/src/maths/Vec3.o \
	${OBJECTDIR}/src/cameras/CameraMan.o \
	${OBJECTDIR}/src/scenegraph/Visual.o \
	${OBJECTDIR}/src/events/CollisionDetector.o \
	${OBJECTDIR}/src/resource/OBJLoader.o \
	${OBJECTDIR}/src/scenegraph/TexCoord.o \
	${OBJECTDIR}/src/maths/Vec2.o \
	${OBJECTDIR}/src/maths/FastMath.o \
	${OBJECTDIR}/src/appearance/PointAtt.o \
	${OBJECTDIR}/src/lights/LightMan.o \
	${OBJECTDIR}/src/scenegraph/Bound.o \
	${OBJECTDIR}/src/scenegraph/Trfm.o \
	${OBJECTDIR}/src/appearance/Material.o \
	${OBJECTDIR}/src/resource/OBJLexicalAnalyser.o \
	${OBJECTDIR}/src/appearance/LineAtt.o \
	${OBJECTDIR}/src/utils/GetNode.o \
	${OBJECTDIR}/src/maths/Plane.o \
	${OBJECTDIR}/src/events/CollisionEvent.o \
	${OBJECTDIR}/src/cameras/Viewport.o \
	${OBJECTDIR}/src/appearance/Texture.o \
	${OBJECTDIR}/src/maths/Mat3.o \
	${OBJECTDIR}/src/maths/Mat2.o \
	${OBJECTDIR}/src/maths/Mat.o \
	${OBJECTDIR}/src/appearance/Colour.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sangwinredesign

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sangwinredesign: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sangwinredesign ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/cameras/Cam.o: src/cameras/Cam.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/cameras
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/cameras/Cam.o src/cameras/Cam.cpp

${OBJECTDIR}/src/appearance/Alpha.o: src/appearance/Alpha.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/appearance
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/appearance/Alpha.o src/appearance/Alpha.cpp

${OBJECTDIR}/src/scenegraph/Collider.o: src/scenegraph/Collider.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/Collider.o src/scenegraph/Collider.cpp

${OBJECTDIR}/src/scenegraph/Node.o: src/scenegraph/Node.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/Node.o src/scenegraph/Node.cpp

${OBJECTDIR}/src/resource/Token.o: src/resource/Token.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/resource
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/resource/Token.o src/resource/Token.cpp

${OBJECTDIR}/src/appearance/PolyAtt.o: src/appearance/PolyAtt.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/appearance
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/appearance/PolyAtt.o src/appearance/PolyAtt.cpp

${OBJECTDIR}/src/scenegraph/Spatial.o: src/scenegraph/Spatial.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/Spatial.o src/scenegraph/Spatial.cpp

${OBJECTDIR}/src/collision/BoundingVolume.o: src/collision/BoundingVolume.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/collision
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/collision/BoundingVolume.o src/collision/BoundingVolume.cpp

${OBJECTDIR}/src/lights/SpotLight.o: src/lights/SpotLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/lights
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/lights/SpotLight.o src/lights/SpotLight.cpp

${OBJECTDIR}/src/collision/BoundingSphere.o: src/collision/BoundingSphere.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/collision
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/collision/BoundingSphere.o src/collision/BoundingSphere.cpp

${OBJECTDIR}/src/events/EventHandler.o: src/events/EventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/events
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/events/EventHandler.o src/events/EventHandler.cpp

${OBJECTDIR}/src/resource/ResourceManager.o: src/resource/ResourceManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/resource
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/resource/ResourceManager.o src/resource/ResourceManager.cpp

${OBJECTDIR}/src/lights/DirLight.o: src/lights/DirLight.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/lights
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/lights/DirLight.o src/lights/DirLight.cpp

${OBJECTDIR}/src/utils/Object.o: src/utils/Object.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/utils
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/utils/Object.o src/utils/Object.cpp

${OBJECTDIR}/src/scenegraph/Trimesh.o: src/scenegraph/Trimesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/Trimesh.o src/scenegraph/Trimesh.cpp

${OBJECTDIR}/src/maths/Vec.o: src/maths/Vec.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/Vec.o src/maths/Vec.cpp

${OBJECTDIR}/src/scenegraph/Geom.o: src/scenegraph/Geom.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/Geom.o src/scenegraph/Geom.cpp

${OBJECTDIR}/src/lights/Light.o: src/lights/Light.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/lights
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/lights/Light.o src/lights/Light.cpp

${OBJECTDIR}/src/lights/LightBulb.o: src/lights/LightBulb.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/lights
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/lights/LightBulb.o src/lights/LightBulb.cpp

${OBJECTDIR}/src/maths/Mat4.o: src/maths/Mat4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/Mat4.o src/maths/Mat4.cpp

${OBJECTDIR}/src/scenegraph/App.o: src/scenegraph/App.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/App.o src/scenegraph/App.cpp

${OBJECTDIR}/src/maths/Vec3.o: src/maths/Vec3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/Vec3.o src/maths/Vec3.cpp

${OBJECTDIR}/src/cameras/CameraMan.o: src/cameras/CameraMan.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/cameras
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/cameras/CameraMan.o src/cameras/CameraMan.cpp

${OBJECTDIR}/src/scenegraph/Visual.o: src/scenegraph/Visual.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/Visual.o src/scenegraph/Visual.cpp

${OBJECTDIR}/src/events/CollisionDetector.o: src/events/CollisionDetector.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/events
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/events/CollisionDetector.o src/events/CollisionDetector.cpp

${OBJECTDIR}/src/resource/OBJLoader.o: src/resource/OBJLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/resource
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/resource/OBJLoader.o src/resource/OBJLoader.cpp

${OBJECTDIR}/src/scenegraph/TexCoord.o: src/scenegraph/TexCoord.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/TexCoord.o src/scenegraph/TexCoord.cpp

${OBJECTDIR}/src/maths/Vec2.o: src/maths/Vec2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/Vec2.o src/maths/Vec2.cpp

${OBJECTDIR}/src/maths/FastMath.o: src/maths/FastMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/FastMath.o src/maths/FastMath.cpp

${OBJECTDIR}/src/appearance/PointAtt.o: src/appearance/PointAtt.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/appearance
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/appearance/PointAtt.o src/appearance/PointAtt.cpp

${OBJECTDIR}/src/lights/LightMan.o: src/lights/LightMan.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/lights
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/lights/LightMan.o src/lights/LightMan.cpp

${OBJECTDIR}/src/scenegraph/Bound.o: src/scenegraph/Bound.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/Bound.o src/scenegraph/Bound.cpp

${OBJECTDIR}/src/scenegraph/Trfm.o: src/scenegraph/Trfm.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/scenegraph
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/scenegraph/Trfm.o src/scenegraph/Trfm.cpp

${OBJECTDIR}/src/appearance/Material.o: src/appearance/Material.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/appearance
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/appearance/Material.o src/appearance/Material.cpp

${OBJECTDIR}/src/resource/OBJLexicalAnalyser.o: src/resource/OBJLexicalAnalyser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/resource
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/resource/OBJLexicalAnalyser.o src/resource/OBJLexicalAnalyser.cpp

${OBJECTDIR}/src/appearance/LineAtt.o: src/appearance/LineAtt.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/appearance
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/appearance/LineAtt.o src/appearance/LineAtt.cpp

${OBJECTDIR}/src/utils/GetNode.o: src/utils/GetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/utils
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/utils/GetNode.o src/utils/GetNode.cpp

${OBJECTDIR}/src/maths/Plane.o: src/maths/Plane.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/Plane.o src/maths/Plane.cpp

${OBJECTDIR}/src/events/CollisionEvent.o: src/events/CollisionEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/events
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/events/CollisionEvent.o src/events/CollisionEvent.cpp

${OBJECTDIR}/src/cameras/Viewport.o: src/cameras/Viewport.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/cameras
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/cameras/Viewport.o src/cameras/Viewport.cpp

${OBJECTDIR}/src/appearance/Texture.o: src/appearance/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/appearance
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/appearance/Texture.o src/appearance/Texture.cpp

${OBJECTDIR}/src/maths/Mat3.o: src/maths/Mat3.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/Mat3.o src/maths/Mat3.cpp

${OBJECTDIR}/src/maths/Mat2.o: src/maths/Mat2.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/Mat2.o src/maths/Mat2.cpp

${OBJECTDIR}/src/maths/Mat.o: src/maths/Mat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/maths
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/maths/Mat.o src/maths/Mat.cpp

${OBJECTDIR}/src/appearance/Colour.o: src/appearance/Colour.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/appearance
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/appearance/Colour.o src/appearance/Colour.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sangwinredesign

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
