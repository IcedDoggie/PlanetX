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
#include "sweep.hpp"
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
               void drawSpaceRide();
               void tickTime(long int elapseTime);
               ///unfinished
               void drawCups(bool toggler);
               void drawEyesOnVader();
               static GLfloat profilepoints[];



          private:
               GLfloat velx,vely,velz;
               GLfloat posx,posy,posz;
               GLfloat roty;
               bool toggleDir;


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
          //MySweepSurface mysweepsurface;
          long int timeold,timenew,elapseTime;
          vector<vec3> pts, ptsTransformed,points3d;
          vector<vec2> points;
          bool toggleDir=true;




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
               themeParkX.drawCups(toggleDir);

               //replicate->draw();
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

			///initializing for sweep



			/// initializing variables for spline creation
//               points3d =
//               {
//                {{ -4.0f, -5.0f,5.0f }},
//                {{  4.0f,  5.0f,5.0f }},
//                {{  8.0f,  7.0f,5.0f }},
//                {{  12.0f,  5.0f,5.0f }},
//                {{  16.0f, -5.0f,5.0f }},
//                {{  20.0f, -7.0f,5.0f }}
//               };
//
//                 auto circle = getCircle(2, 10);
//                 for (auto &v : circle) points.push_back({{ v[0], v[2] }});
//
//                 spring:
//                 points3d = generateSpline(-10, 50, 50,
//                                           [](float z)->float { return sin(z/2.0) * 5; },
//                                           [](float x)->float { return cos(x/2.0) * 5; },
//                                           [](float y)->float { return y; });
//
//
//                 deer = new Mesh("data/omid.obj");
//                 deer->setFlatColor({{.8, .2, .8}});
//                 deer->setTranslateY(-5.5f);
//                 deer->setRotateZ(-90);
//                 deer->setScale(0.5f);
//                 replicate = new Replicate(points3d,deer);

		}

		private:
               int numberOfTexture;
               GLuint* textureNumbers;
               bool textureison;
	};
}; //end of namespace CGLab08
#endif //YP_CGLAB08_HPP
