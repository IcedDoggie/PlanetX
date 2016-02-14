/*
TGD2151 Computer Graphics Fundamentals
Faculty of Computing & Informatics, Multimedia University
CGLab05.hpp
Objective: Header File for Lab05 on Points & Lines
*/
#ifndef planetX_HPP
#define planetX_HPP
#include "CGLabmain.hpp"
#include "utilities/Mesh.hpp"
#include "utilities/Extrusion.hpp"
#include "utilities/Loft.hpp"
#include "utilities/Replicate.hpp"
namespace planetX
{
//class declaration


	class MyVirtualWorld
	{
		public:


		long int timeold, timenew, elapseTime;

		void draw()
		{


		}

		void tickTime()
		{
			timenew = glutGet(GLUT_ELAPSED_TIME);
			elapseTime = timenew - timeold;
			timeold = timenew;

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
