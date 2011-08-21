#This file builds a static library from the Sangwin Engine source.
#
#It can than then be used as a prebuilt library with any project 
#requiring use of the engine.
#
#See 'Usage-Android.mk' for an example of how to use the library.
#
#@author Ben Constable
#@version 1.0



#Set the Local Path to the current root of execution (i.e where the this .mk
#file is.
LOCAL_PATH := $(call my-dir)

#Build Sangwin code as a static library.
include $(CLEAR_VARS)
LOCAL_MODULE := libsangwin
LOCAL_SRC_FILES := src/appearance/Alpha.cpp \
		   src/scenegraph/App.cpp \
		   src/scenegraph/App2.cpp \
		   src/scenegraph/App3.cpp \
		   src/cameras/Cam2.cpp \
		   src/cameras/Cam3.cpp \
		   src/cameras/CameraMan2.cpp \
		   src/cameras/CameraMan3.cpp \
		   src/events/CollisionDetector.cpp \
		   src/events/CollisionEvent.cpp \
		   src/appearance/Colour.cpp \
		   src/lights/DirLight.cpp \
		   src/events/EventHandler.cpp \
		   src/maths/FastMath.cpp \
		   src/utils/GetNode.cpp \
		   src/lights/Light.cpp \
		   src/lights/LightBulb.cpp \
		   src/lights/LightMan.cpp \
		   src/appearance/LineAtt.cpp \
		   src/maths/Mat.cpp \
		   src/maths/Mat2.cpp \
		   src/maths/Mat3.cpp \
		   src/maths/Mat4.cpp \
		   src/appearance/Material.cpp \
		   src/scenegraph/Node.cpp \
		   src/utils/Object.cpp \
		   src/resource/OBJLexicalAnalyser.cpp \
		   src/resource/OBJLoader.cpp \
		   src/maths/Plane.cpp \
		   src/appearance/PointAtt.cpp \
		   src/appearance/PolyAtt.cpp \
		   src/resource/ResourceManager.cpp \
		   src/lights/SpotLight.cpp \
		   src/scenegraph/TexCoord.cpp \
		   src/appearance/Texture.cpp \
		   src/resource/Token.cpp \
		   src/scenegraph/Trfm.cpp \
		   src/scenegraph/Trfm2.cpp \
		   src/scenegraph/Trfm3.cpp \
		   src/scenegraph/Trimesh.cpp \
		   src/maths/Vec.cpp \
		   src/maths/Vec2.cpp \
		   src/maths/Vec3.cpp \
		   src/cameras/Viewport.cpp
include $(BUILD_STATIC_LIBRARY)
