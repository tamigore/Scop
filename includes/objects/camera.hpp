

#ifndef CAMERA_H
#define CAMERA_H

#include "../math/math.hpp"
#include "../../includes/glad/glad.h"

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
const float ZOOM        =  45.0f;


// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class camera
{
public:
    // camera Attributes
    math::vec3 Position;
    math::vec3 Front;
    math::vec3 Up;
    math::vec3 Right;
    math::vec3 WorldUp;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // constructor with vectors
    camera(math::vec3 position = math::vec3(0.0f, 0.0f, 0.0f), math::vec3 up = math::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(math::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }
    // constructor with scalar values
    camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(math::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = math::vec3(posX, posY, posZ);
        WorldUp = math::vec3(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // returns the view matrix calculated using Euler Angles and the LookAt Matrix
    math::mat4 GetViewMatrix()
    {
        math::vec3 Pos(Position.x, Position.y, Position.z), front(Front.x, Front.y, Front.z), up(Up.x, Up.y, Up.z);
        math::mat4 libmath = math::lookAt(Pos, Pos + front, up);
        
        math::mat4 vec = math::lookAt(Position, Position + Front, Up);
        std::cout << "__________ Notre LIBMATH __________" << std::endl;

        std::cout << libmath << std::endl;
        std::cout << "__________ REAL LIBMATH __________" << std::endl;

        for (int i = 0; i < 4; i++)
		{
			std::cout << "| ";
			for (int y = 0; y < 4; y++)
			{
				std::cout << vec[y][i] << " ";
			}
			std::cout << "|" << std::endl;
		}
		std::cout << std::endl;
        std::cout << "____________________" << std::endl;

        return math::lookAt(Position, Position + Front, Up);
    }

    // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
        float velocity = MovementSpeed * deltaTime;
        if (direction == FORWARD)
            Position += Front * velocity;
        if (direction == BACKWARD)
            Position -= Front * velocity;
        if (direction == LEFT)
            Position -= Right * velocity;
        if (direction == RIGHT)
            Position += Right * velocity;
    }

    // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw   += xoffset;
        Pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        // update Front, Right and Up Vectors using the updated Euler angles
        updateCameraVectors();
    }

    // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
    void ProcessMouseScroll(float yoffset)
    {
        Zoom -= (float)yoffset;
        if (Zoom < 1.0f)
            Zoom = 1.0f;
        if (Zoom > 45.0f)
            Zoom = 45.0f;
    }

private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors()
    {
        // calculate the new Front vector
        math::vec3 front;
        front.x = cos(math::radians(Yaw)) * cos(math::radians(Pitch));
        front.y = sin(math::radians(Pitch));
        front.z = sin(math::radians(Yaw)) * cos(math::radians(Pitch));
        Front = math::normalize(front);
        // also re-calculate the Right and Up vector
        Right = math::normalize(math::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        Up    = math::normalize(math::cross(Right, Front));
    }
};

} // namespace obj

#endif