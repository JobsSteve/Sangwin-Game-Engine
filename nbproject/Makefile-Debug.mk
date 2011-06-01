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
	${OBJECTDIR}/LightBulb.o \
	${OBJECTDIR}/Texture.o \
	${OBJECTDIR}/PolyAtt.o \
	${OBJECTDIR}/Vec.o \
	${OBJECTDIR}/GetNode.o \
	${OBJECTDIR}/Vec2.o \
	${OBJECTDIR}/App3.o \
	${OBJECTDIR}/Plane.o \
	${OBJECTDIR}/EventHandler.o \
	${OBJECTDIR}/LineAtt.o \
	${OBJECTDIR}/App.o \
	${OBJECTDIR}/OBJLoader.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Colour.o \
	${OBJECTDIR}/OBJLexicalAnalyser.o \
	${OBJECTDIR}/Trfm.o \
	${OBJECTDIR}/Light.o \
	${OBJECTDIR}/Viewport.o \
	${OBJECTDIR}/Cam2.o \
	${OBJECTDIR}/Vec3.o \
	${OBJECTDIR}/Mat2.o \
	${OBJECTDIR}/CameraMan3.o \
	${OBJECTDIR}/CollisionEvent.o \
	${OBJECTDIR}/CollisionDetector.o \
	${OBJECTDIR}/App2.o \
	${OBJECTDIR}/Trfm2.o \
	${OBJECTDIR}/TexCoord.o \
	${OBJECTDIR}/DirLight.o \
	${OBJECTDIR}/Alpha.o \
	${OBJECTDIR}/LightMan.o \
	${OBJECTDIR}/ResourceManager.o \
	${OBJECTDIR}/Mat3.o \
	${OBJECTDIR}/Mat4.o \
	${OBJECTDIR}/Object.o \
	${OBJECTDIR}/Mat.o \
	${OBJECTDIR}/Trimesh.o \
	${OBJECTDIR}/CameraMan2.o \
	${OBJECTDIR}/Cam3.o \
	${OBJECTDIR}/SpotLight.o \
	${OBJECTDIR}/Trfm3.o \
	${OBJECTDIR}/Node.o \
	${OBJECTDIR}/Token.o \
	${OBJECTDIR}/FastMath.o \
	${OBJECTDIR}/PointAtt.o \
	${OBJECTDIR}/Material.o


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

${OBJECTDIR}/LightBulb.o: LightBulb.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LightBulb.o LightBulb.cpp

${OBJECTDIR}/Texture.o: Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Texture.o Texture.cpp

${OBJECTDIR}/PolyAtt.o: PolyAtt.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/PolyAtt.o PolyAtt.cpp

${OBJECTDIR}/Vec.o: Vec.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Vec.o Vec.cpp

${OBJECTDIR}/GetNode.o: GetNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/GetNode.o GetNode.cpp

${OBJECTDIR}/Vec2.o: Vec2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Vec2.o Vec2.cpp

${OBJECTDIR}/App3.o: App3.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/App3.o App3.cpp

${OBJECTDIR}/Plane.o: Plane.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Plane.o Plane.cpp

${OBJECTDIR}/EventHandler.o: EventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/EventHandler.o EventHandler.cpp

${OBJECTDIR}/LineAtt.o: LineAtt.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LineAtt.o LineAtt.cpp

${OBJECTDIR}/App.o: App.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/App.o App.cpp

${OBJECTDIR}/OBJLoader.o: OBJLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/OBJLoader.o OBJLoader.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Colour.o: Colour.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Colour.o Colour.cpp

${OBJECTDIR}/OBJLexicalAnalyser.o: OBJLexicalAnalyser.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/OBJLexicalAnalyser.o OBJLexicalAnalyser.cpp

${OBJECTDIR}/Trfm.o: Trfm.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Trfm.o Trfm.cpp

${OBJECTDIR}/Light.o: Light.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Light.o Light.cpp

${OBJECTDIR}/Viewport.o: Viewport.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Viewport.o Viewport.cpp

${OBJECTDIR}/Cam2.o: Cam2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Cam2.o Cam2.cpp

${OBJECTDIR}/Vec3.o: Vec3.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Vec3.o Vec3.cpp

${OBJECTDIR}/Mat2.o: Mat2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Mat2.o Mat2.cpp

${OBJECTDIR}/CameraMan3.o: CameraMan3.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/CameraMan3.o CameraMan3.cpp

${OBJECTDIR}/CollisionEvent.o: CollisionEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/CollisionEvent.o CollisionEvent.cpp

${OBJECTDIR}/CollisionDetector.o: CollisionDetector.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/CollisionDetector.o CollisionDetector.cpp

${OBJECTDIR}/App2.o: App2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/App2.o App2.cpp

${OBJECTDIR}/Trfm2.o: Trfm2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Trfm2.o Trfm2.cpp

${OBJECTDIR}/TexCoord.o: TexCoord.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/TexCoord.o TexCoord.cpp

${OBJECTDIR}/DirLight.o: DirLight.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/DirLight.o DirLight.cpp

${OBJECTDIR}/Alpha.o: Alpha.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Alpha.o Alpha.cpp

${OBJECTDIR}/LightMan.o: LightMan.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LightMan.o LightMan.cpp

${OBJECTDIR}/ResourceManager.o: ResourceManager.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ResourceManager.o ResourceManager.cpp

${OBJECTDIR}/Mat3.o: Mat3.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Mat3.o Mat3.cpp

${OBJECTDIR}/Mat4.o: Mat4.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Mat4.o Mat4.cpp

${OBJECTDIR}/Object.o: Object.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Object.o Object.cpp

${OBJECTDIR}/Mat.o: Mat.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Mat.o Mat.cpp

${OBJECTDIR}/Trimesh.o: Trimesh.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Trimesh.o Trimesh.cpp

${OBJECTDIR}/CameraMan2.o: CameraMan2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/CameraMan2.o CameraMan2.cpp

${OBJECTDIR}/Cam3.o: Cam3.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Cam3.o Cam3.cpp

${OBJECTDIR}/SpotLight.o: SpotLight.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/SpotLight.o SpotLight.cpp

${OBJECTDIR}/Trfm3.o: Trfm3.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Trfm3.o Trfm3.cpp

${OBJECTDIR}/Node.o: Node.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Node.o Node.cpp

${OBJECTDIR}/Token.o: Token.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Token.o Token.cpp

${OBJECTDIR}/FastMath.o: FastMath.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/FastMath.o FastMath.cpp

${OBJECTDIR}/PointAtt.o: PointAtt.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/PointAtt.o PointAtt.cpp

${OBJECTDIR}/Material.o: Material.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Material.o Material.cpp

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
