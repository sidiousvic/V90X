//
//  main.cpp
//  V90X
//
//  Created by SIDIOUSVIC on 2019/12/15.
//  Copyright © 2019 SIDIOUSVIC. All rights reserved.
//
#include <stdio.h>
#include <iostream>
// GLEW
#include "glew.h"
// GLFW
#include "glfw3.h"


// WINDOW DIMENSIONS
const GLint WIDTH = 800, HEIGHT = 600;

int main() {
    
    // initialize GLFW
    if(!glfwInit()) {
        printf("GLFW initialization failed.");
        glfwTerminate();
        return 1;
    }
    
    // setup GLFW window properties
    // OPENGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // core profile = no backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
    if(!mainWindow) {
        printf("GLFW window creation failed.");
        glfwTerminate();
        return 1;
    }
    
    // get buffer size information
    int buffferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &buffferWidth, &bufferHeight);
    
    // set the context for GLEW to use
    glfwMakeContextCurrent(mainWindow);
    
    // allow modern extension features
    glewExperimental = GL_TRUE;
    
    // initialize GLEW
    if(glewInit() != GLEW_OK) {
        printf("GLEW initialization failed.");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }
    
    // setup viewport size
    glViewport(0, 0, buffferWidth, bufferHeight);
    
    // loop until window closed
    while (!glfwWindowShouldClose(mainWindow)) {
        // get and handle user input events
        glfwPollEvents();
        
        // clear the window
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(mainWindow);
    }
    
    std::cout << &bufferHeight;
    
    return 0;
}


