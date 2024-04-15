#ifndef __CAMERA_HPP__
# define __CAMERA_HPP__

# include "../math/math.hpp"

# include <glad/glad.h>

namespace obj
{

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM		=  45.0f;

// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class camera
{
	public:
		// camera Attributes
		math::vec3	position;
		math::vec3	front;
		math::vec3	up;
		math::vec3	right;
		math::vec3	worldUp;
		float		yaw;
		float		pitch;
		float		movementSpeed;
		float		mouseSensitivity;
		float		zoom;

		camera();
		camera(math::vec3 position);
		camera(math::vec3 position, math::vec3 up, float yaw, float pitch);
		camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
		~camera();

		math::mat4	GetViewMatrix();

		void	ProcessKeyboard(Camera_Movement direction, float deltaTime);
		void	ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch);
		void	ProcessMouseScroll(float yoffset);

	private:
		// calculates the front vector from the Camera's (updated) Euler Angles
		void	updateCameraVectors();
};

}

#endif
