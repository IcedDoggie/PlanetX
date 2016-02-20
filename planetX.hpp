/*
TGD2151 Computer Graphics Fundamentals
Faculty of Computing & Informatics, Multimedia University
CGLab05.hpp
Objective: Header File for Lab05 on Points & Lines
*/
#ifndef planetX_HPP
#define planetX_HPP
#include "CGLabmain.hpp"
#include "bezier.hpp"
#include "cubeShaper.hpp"
#include "CGimageloader.hpp"
#include <cmath>
#include "utilities/Mesh.hpp"
#include "utilities/Extrusion.hpp"
#include "utilities/Loft.hpp"
#include "utilities/Replicate.hpp"
#include "utilities/Lathe.hpp"
namespace planetX
{
//class declaration
     class PlanetX
     {
          public:
               PlanetX();
               ~PlanetX(){};
               void draw();
               void drawRails();
               void drawTrain();
               void tickTime(long int elapseTime);


          private:
               GLfloat velx,vely,velz;
               GLfloat posx,posy,posz;
               GLfloat roty;


     };



	class MyVirtualWorld
	{
		public:
          Mesh *deer;
          Loft *loth;
          Replicate *replicate;
          Extrusion *extrude;
          Lathe *lathe;
          PlanetX themeParkX;
          long int timeold,timenew,elapseTime;


          MyVirtualWorld()
          {
               numberOfTexture = 0;
               textureNumbers = NULL;
               textureison = false;
          }

          ~MyVirtualWorld()
          {
               if (textureNumbers != NULL)
                    delete[] textureNumbers;
          }

          void setupTextures()
          {
               numberOfTexture = 3;
               textureNumbers = new GLuint[numberOfTexture];
               //Set pixel storage mode
               glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
               //set texture environment parameters
               glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
               //Generate texture map identifiers
               glGenTextures(numberOfTexture, textureNumbers);
               //Read image data into memory
               MyImage myimage[numberOfTexture];
               myimage[0].loadJPG("images/marble1.jpg");
               myimage[1].loadJPG("images/wood1.jpg");
               myimage[2].loadJPG("images/brick1.jpg");
               //Try this: myimage[2].loadBMP("images/rocks.bmp");
               //for each texture map identifiers
               for (int i=0; i<numberOfTexture; i++)
               {
                    //Bind a named texture to a texturing target
                    glBindTexture(GL_TEXTURE_2D, textureNumbers[i]);
                    //Set texture parameters
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                    //Set texture map
                    glTexImage2D(GL_TEXTURE_2D, // defining a 2D texture
                    0, // level (not multi-resolution)
                    GL_RGBA, // format of OpenGL's texture
                    myimage[i].width, myimage[i].height,// dimensions of the image
                    0, // border
                    GL_RGB, GL_UNSIGNED_BYTE, // format of image
                    myimage[i].buffer // pixel data of image
                    );
               }
                    textureison = true;
          }

          void toggleTextures()
          {
               textureison = !textureison;
          }

		void draw()
		{
               themeParkX.draw();
               themeParkX.drawRails();
               themeParkX.drawTrain();
		}

		void tickTime()
		{
			timenew = glutGet(GLUT_ELAPSED_TIME);
			elapseTime = timenew - timeold;
			timeold = timenew;

			themeParkX.tickTime(elapseTime);

		}
		//for any one-time only initialization of the
		// virtual world before any rendering takes place
		// BUT after OpenGL has been initialized
		void init()
		{
		     setupTextures();
			timeold = glutGet(GLUT_ELAPSED_TIME);
		}

		private:
               int numberOfTexture;
               GLuint* textureNumbers;
               bool textureison;
	};
}; //end of namespace CGLab08
#endif //YP_CGLAB08_HPP
