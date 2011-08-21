#This .mk file shows how to use the library after it has been prebuilt.
#
#@author Ben Constable
#@version 1.0

#Set the Local Path to the current root of execution (i.e where the this .mk
#file is.
LOCAL_PATH := $(call my-dir)

#Build Sangwin code as a static library. This assumes that the library is 
#stored in libs/ as libsangwin.a
include $(CLEAR_VARS)
LOCAL_MODULE := libsangwin-prebuilt
LOCAL_SRC_FILES := libs/libsangwin.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)

#Create the native Game as a shared library, using the Sangwin static library.
#Include OpenGL ES as well.
include $(CLEAR_VARS)
LOCAL_MODULE    := game
#Add game source files here
#LOCAL_SRC_FILES := 
LOCAL_STATIC_LIBRARIES := libsangwin-prebuilt
LOCAL_LDLIBS    := -lGLESv1_CM -ljnigraphics -llog
include $(BUILD_SHARED_LIBRARY)