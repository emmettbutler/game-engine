CXX = g++
CFLAGS = -g
LIBS = -lpng -lglfw -lGLEW -lGL -lGLU

LIBRARYPATH = lib
INCLUDEPATH = include
TESTPATH = tests

MAIN = Engine
SHAREDPATH = common
GLEWINC = external/glew/1.0.9/include/
GLFWINC = external/glfw-2.7.6/include
GLMINC = external/glm-0.9.4.0
LIBINC = -Iinclude
INCDIRS = -I$(SHAREDPATH) -I$(GLEWINC) -I$(GLFWINC) -I$(GLMINC) $(LIBINC)
SPLIB = spSprite.o spMatrixTransform.o spMatrix.o spGame.o
EXTERNALS = shader.o texture.o
TESTS = tMatrix tSprite tTransform tTransformLoad tTransformMultiTimer

all: $(MAIN).o splib externals tests
	$(CXX) $(CFLAGS) $(INCDIRS) -o $(MAIN) $(MAIN).o $(SPLIB) $(EXTERNALS) $(LIBS)

tests: $(TESTS)
tMatrix : tests/spMatrixTest.cpp
	$(CXX) $(CFLAGS) $(LIBINC) $(TESTPATH)/spMatrixTest.cpp $(LIBRARYPATH)/spMatrix.cpp -o tMatrix
tSprite : splib externals
	$(CXX) $(CFLAGS) $(INCDIRS) -o tSprite $(TESTPATH)/spSpriteTest.cpp $(SPLIB) $(EXTERNALS) $(LIBS)
tTransformLoad : splib externals
	$(CXX) $(CFLAGS) $(INCDIRS) -o tTransformLoad $(TESTPATH)/spTransformLoadTest.cpp $(SPLIB) $(EXTERNALS) $(LIBS)
tTransform : splib externals
	$(CXX) $(CFLAGS) $(INCDIRS) -o tTransform $(TESTPATH)/spTransformTest.cpp $(SPLIB) $(EXTERNALS) $(LIBS)
tTransformMultiTimer : splib externals
	$(CXX) $(CFLAGS) $(INCDIRS) -o tTransformMultiTimer $(TESTPATH)/spTransformMultiTimerTest.cpp $(SPLIB) $(EXTERNALS) $(LIBS)

$(MAIN).o : main.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c main.cpp -o $(MAIN).o

externals : $(EXTERNALS)
shader.o : common/shader.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c $(SHAREDPATH)/shader.cpp
texture.o : common/texture.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c $(SHAREDPATH)/texture.cpp -lpng

splib : $(SPLIB)
spSprite.o : $(LIBRARYPATH)/spSprite.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c $(LIBRARYPATH)/spSprite.cpp
spMatrixStack.o : $(LIBRARYPATH)/spMatrixStack.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c $(LIBRARYPATH)/spMatrixStack.cpp
spMatrixTransform.o : $(LIBRARYPATH)/spMatrixTransform.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c $(LIBRARYPATH)/spMatrixTransform.cpp
spList.o : $(LIBRARYPATH)/spList.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c $(LIBRARYPATH)/spList.cpp
spMatrix.o : $(LIBRARYPATH)/spMatrix.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c $(LIBRARYPATH)/spMatrix.cpp
spGame.o : $(LIBRARYPATH)/spGame.cpp
	$(CXX) $(CFLAGS) $(INCDIRS) -c $(LIBRARYPATH)/spGame.cpp

clean:
	rm -rf *.dSYM *.o .*.un~ .*.swp $(TESTS) $(MAIN)
