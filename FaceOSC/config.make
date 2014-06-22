# add custom variables to this file

# OF_ROOT allows to move projects outside apps/* just set this variable to the
# absoulte path to the OF root folder

OF_ROOT = ../../..


# USER_CFLAGS allows to pass custom flags to the compiler
# for example search paths like:
# USER_CFLAGS = -I src/objects

USER_CFLAGS =


# USER_LDFLAGS allows to pass custom flags to the linker
# for example libraries like:
# USER_LD_FLAGS = libs/libawesomelib.a

USER_LDFLAGS = /lib64/libgstreamer-0.10.so /lib64/libgstapp-0.10.so.0 /lib64/libgstvideo-0.10.so.0 /lib64/libopencv_calib3d.so.2.4 /lib64/libX11.so.6 /lib64/libXi.so.6 /lib64/libXrandr.so.2 /lib64/libXxf86vm.so.1 /lib64/libudev.so.1 /lib64/libGLEW.so.1.9.0 /usr/lib64/libPocoNetSSL.so.11 /lib64/libPocoXML.so.11


# use this to add system libraries for example:
# USER_LIBS = -lpango


USER_LIBS =-lpthread -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_flann -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_ts -lopencv_video -lgstbase-0.10


# change this to add different compiler optimizations to your project

USER_COMPILER_OPTIMIZATION = -march=native -mtune=native -Os


EXCLUDE_FROM_SOURCE="bin,.xcodeproj,obj,.git"
