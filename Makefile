CXX = g++
CFLAGS = -g -O2
LIBS = -lglfw -lGLEW -lGL -lGLU

MAIN = Test
SHAREDPATH = common
GLEWINC = external/glew/1.0.9/include/
GLFWINC = external/glfw-2.7.6/include
GLMINC = external/glm-0.9.4.0
INCDIRS = -I$(SHAREDPATH) -I$(GLEWINC) -I$(GLFWINC) -I$(GLMINC)

all: $(MAIN).o splib externals
	$(CXX) -g $(INCDIRS) -o $(MAIN) $(MAIN).o shader.o texture.o spSprite.o spMatrixStack.o spMatrixTransform.o spList.o $(LIBS)

$(MAIN).o : main.cpp
	$(CXX) -g $(INCDIRS) -c main.cpp -o $(MAIN).o

externals : shader.o texture.o
shader.o : common/shader.cpp
	$(CXX) -g $(INCDIRS) -c common/shader.cpp
texture.o : common/texture.cpp
	$(CXX) -g $(INCDIRS) -c common/texture.cpp

splib : spSprite.o spMatrixStack.o spMatrixTransform.o spList.o
spSprite.o : spSprite.cpp
	$(CXX) -g $(INCDIRS) -c spSprite.cpp
spMatrixStack.o : spMatrixStack.cpp
	$(CXX) -g $(INCDIRS) -c spMatrixStack.cpp
spMatrixTransform.o : spMatrixTransform.cpp
	$(CXX) -g $(INCDIRS) -c spMatrixTransform.cpp
spList.o : spList.cpp
	$(CXX) -g $(INCDIRS) -c spList.cpp

clean:
	rm -rf *.dSYM *.o .*.un~ .*.swp $(MAIN)
