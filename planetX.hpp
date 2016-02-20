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
			timeold = glutGet(GLUT_ELAPSED_TIME);
		}
	};
}; //end of namespace CGLab08
#endif //YP_CGLAB08_HPP
