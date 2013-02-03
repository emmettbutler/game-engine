CXX = g++
CFLAGS = -g -O2
LIBS = -lglfw -lGLEW -lGL -lGLU

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
TESTS = tMatrix tSprite

all: $(MAIN).o splib externals tests
	$(CXX) -g $(INCDIRS) -o $(MAIN) $(MAIN).o $(SPLIB) $(EXTERNALS) $(LIBS)

tests: $(TESTS)
tMatrix : tests/spMatrixTest.cpp
	$(CXX) -g $(LIBINC) $(TESTPATH)/spMatrixTest.cpp $(LIBRARYPATH)/spMatrix.cpp -o tMatrix
tSprite : splib externals
	$(CXX) -g $(INCDIRS) -o tSprite $(TESTPATH)/spSpriteTest.cpp $(SPLIB) $(EXTERNALS) $(LIBS)

$(MAIN).o : main.cpp
	$(CXX) -g $(INCDIRS) -c main.cpp -o $(MAIN).o

externals : $(EXTERNALS)
shader.o : common/shader.cpp
	$(CXX) -g $(INCDIRS) -c $(SHAREDPATH)/shader.cpp
texture.o : common/texture.cpp
	$(CXX) -g $(INCDIRS) -c $(SHAREDPATH)/texture.cpp -lpng

splib : $(SPLIB)
spSprite.o : $(LIBRARYPATH)/spSprite.cpp
	$(CXX) -g $(INCDIRS) -c $(LIBRARYPATH)/spSprite.cpp
spMatrixStack.o : $(LIBRARYPATH)/spMatrixStack.cpp
	$(CXX) -g $(INCDIRS) -c $(LIBRARYPATH)/spMatrixStack.cpp
spMatrixTransform.o : $(LIBRARYPATH)/spMatrixTransform.cpp
	$(CXX) -g $(INCDIRS) -c $(LIBRARYPATH)/spMatrixTransform.cpp
spList.o : $(LIBRARYPATH)/spList.cpp
	$(CXX) -g $(INCDIRS) -c $(LIBRARYPATH)/spList.cpp
spMatrix.o : $(LIBRARYPATH)/spMatrix.cpp
	$(CXX) -g $(INCDIRS) -c $(LIBRARYPATH)/spMatrix.cpp
spGame.o : $(LIBRARYPATH)/spGame.cpp
	$(CXX) -g $(INCDIRS) -c $(LIBRARYPATH)/spGame.cpp

clean:
	rm -rf *.dSYM *.o .*.un~ .*.swp $(TESTS) $(MAIN)
