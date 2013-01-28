all:
	g++ -g -Iexternal/glew-1.9.0/include/ -Iexternal/glfw-2.7.6/include -Iexternal/glm-0.9.4.0 -Icommon main.cpp -o main common/shader.cpp common/texture.cpp spSprite.cpp spMatrixStack.cpp spList.cpp -lglfw -lGLEW -lGL -lGLU
