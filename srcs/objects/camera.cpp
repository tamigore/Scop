#include "../../includes/objects/camera.hpp"
using namespace obj;

camera::camera()
{
	this->position = math::vec3(0.0f, 0.0f, 0.0f);
	this->worldUp = math::vec3(0.0f, 0.0f, 1.0f);
	this->yaw = YAW;
	this->pitch = PITCH;
	this->movementSpeed = SPEED;
	this->mouseSensitivity = SENSITIVITY;
	this->zoom = ZOOM;
	updateCameraVectors();
}

camera::camera(math::vec3 position)
{
	this->position = position;
	this->worldUp = math::vec3(0.0f, 0.0f, 1.0f);
	this->yaw = YAW;
	this->pitch = PITCH;
	this->movementSpeed = SPEED;
	this->mouseSensitivity = SENSITIVITY;
	this->zoom = ZOOM;
	updateCameraVectors();
}

camera::camera(math::vec3 position, math::vec3 up, float yaw, float pitch)
{
	this->position = position;
	this->worldUp = up;
	this->yaw = yaw;
	this->pitch = pitch;
	this->movementSpeed = SPEED;
	this->mouseSensitivity = SENSITIVITY;
	this->zoom = ZOOM;
	updateCameraVectors();
}

// constructor with scalar values
camera::camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) 
{
	this->position = math::vec3(posX, posY, posZ);
	this->worldUp = math::vec3(upX, upY, upZ);
	this->yaw = yaw;
	this->pitch = pitch;
	this->movementSpeed = SPEED;
	this->mouseSensitivity = SENSITIVITY;
	this->zoom = ZOOM;
	updateCameraVectors();
}

camera::~camera() {}

// returns the view matrix calculated using Euler Angles and the LookAt Matrix
math::mat4	camera::GetViewMatrix()
{
	return math::lookAt(position, position + front, up);
}

// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void	camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
	float velocity = movementSpeed * deltaTime;
	if (direction == FORWARD)
		position += front * velocity;
	if (direction == BACKWARD)
		position -= front * velocity;
	if (direction == LEFT)
		position -= right * velocity;
	if (direction == RIGHT)
		position += right * velocity;
}

// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void	camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	yaw   += xoffset;
	pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	// update Front, Right and Up Vectors using the updated Euler angles
	updateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void	camera::ProcessMouseScroll(float yoffset)
{
	zoom -= (float)yoffset;
	if (zoom < 1.0f)
		zoom = 1.0f;
	if (zoom > 45.0f)
		zoom = 45.0f;
}

// calculates the front vector from the Camera's (updated) Euler Angles
void	camera::updateCameraVectors()
{
	// calculate the new Front vector
	math::vec3 front;
	front.x = cos(math::radians(yaw)) * cos(math::radians(pitch));
	front.y = sin(math::radians(pitch));
	front.z = sin(math::radians(yaw)) * cos(math::radians(pitch));
	front = math::normalize(front);
	// also re-calculate the Right and Up vector
	right = math::normalize(math::cross(front, worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up    = math::normalize(math::cross(right, front));
	std::cout << "front: " << front << std::endl;
	std::cout << "right: " << right << std::endl;
	std::cout << "up: " << up << std::endl;
}
