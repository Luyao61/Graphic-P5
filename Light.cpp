#include "Light.h"
#include "Window.h"
#include <iostream>

#ifdef __APPLE__
    #include <GLUT/glut.h>
    //#include <GL/freeglut.h>
#else
    #include <GL/glut.h>
#endif


Light::Light()
{
    /*
    ambientColor = Color::ambientDefault();
    diffuseColor = Color::diffuseDefault();
    specularColor = Color::specularDefault();
    
    constantAttenuation = 0.5;
    linearAttenuation = 0.5;
    quadraticAttenuation = 0.05;
    
    spotdirection.set(0.0, 0.0, 0.0);
    
    cutoff = 1.0;
    exponent = 0.0;
     */
    ambientColor = Color::ambientDefault();
    diffuseColor = Color::diffuseDefault();
    specularColor = Color::specularDefault();
    
    constantAttenuation = 1.0;
    linearAttenuation = 0.0;
    quadraticAttenuation = 0.05;
    
    cutoff = 180.0;
    exponent = 0.0;
    spotdirection.set(0.0, 0.0, 0.0);
}

Light::~Light()
{
    //Delete any dynamically allocated memory/objects here
}

/*
void Light::bind(int id)
{
    if(id < 0 || id > 7) {
        std::cout << "ERROR: The light bind ID " << id << " is not valid!" << std::endl;
        return;
    }
    
    //Set the bindID
    bindID = id;
    
    //Configure the light at the bindID
    glEnable(GL_LIGHT0 + bindID);
    
    //Configure the color of the light
    glLightfv(GL_LIGHT0 + bindID, GL_AMBIENT, ambientColor.ptr());
    glLightfv(GL_LIGHT0 + bindID, GL_DIFFUSE, diffuseColor.ptr());
    glLightfv(GL_LIGHT0 + bindID, GL_SPECULAR, specularColor.ptr());
    
    //Position the light
    glLightfv(GL_LIGHT0 + bindID, GL_POSITION, position.ptr());
    
    if(id == 0){
        glLightf(GL_LIGHT0 + bindID, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);
    }
    
    if(id > 1){
        //Configure the attenuation properties of the light
        glLightf(GL_LIGHT0 + bindID, GL_LINEAR_ATTENUATION, linearAttenuation);
        //Add support for Constant Attenuation
        glLightf(GL_LIGHT0 + bindID, GL_CONSTANT_ATTENUATION, constantAttenuation);
        //Add support for Linear Attenuation
        glLightf(GL_LIGHT0 + bindID, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);
    }
    if(id > 2){
        //Setup spotlight direction, angle, and exponent here
        glLightfv(GL_LIGHT0 + bindID, GL_SPOT_DIRECTION, spotdirection.ptr());
    
        glLightf(GL_LIGHT0 + bindID, GL_SPOT_CUTOFF, cutoff);
    
        glLightf(GL_LIGHT0 + bindID, GL_SPOT_EXPONENT, exponent);
    }
}
 */

void Light::bind(int id)
{
    if(id < 0 || id > 7) {
        std::cout << "ERROR: The light bind ID " << id << " is not valid!" << std::endl;
        return;
    }
    
    //Set the bindID
    bindID = id;
    
    //Configure the light at the bindID
    glEnable(GL_LIGHT0 + bindID);
    
    //Configure the color of the light
    glLightfv(GL_LIGHT0 + bindID, GL_AMBIENT, ambientColor.ptr());
    glLightfv(GL_LIGHT0 + bindID, GL_DIFFUSE, diffuseColor.ptr());
    glLightfv(GL_LIGHT0 + bindID, GL_SPECULAR, specularColor.ptr());
    
    //Configure the attenuation properties of the light
    //Add support for Constant Attenuation
    //Add support for Linear Attenuation
    glLightf(GL_LIGHT0 + bindID, GL_QUADRATIC_ATTENUATION, quadraticAttenuation);
    glLightf(GL_LIGHT0 + bindID, GL_LINEAR_ATTENUATION, linearAttenuation);
    glLightf(GL_LIGHT0 + bindID, GL_CONSTANT_ATTENUATION, constantAttenuation);
    //Position the light
    glLightfv(GL_LIGHT0 + bindID, GL_POSITION, position.ptr());
    
    //Setup spotlight direction, angle, and exponent here
    glLightfv(GL_LIGHT0 + bindID, GL_SPOT_DIRECTION, spotdirection.ptr());
    
    glLightf(GL_LIGHT0 + bindID, GL_SPOT_CUTOFF, cutoff);
    
    glLightf(GL_LIGHT0 + bindID, GL_SPOT_EXPONENT, exponent);
}


void Light::unbind(void)
{
    glDisable(GL_LIGHT0 + bindID);
    bindID = -1;
}
