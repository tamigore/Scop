#include "../../includes/objects/camera.hpp"

// camera::camera()
// {
// 	this->position = math::vec3(0.0f, 0.0f, 0.0f);
// 	this->worldUp = math::vec3(0.0f, 0.0f, -1.0f);
// 	this->yaw = YAW;
// 	this->pitch = PITCH;
// 	this->movementSpeed = SPEED;
// 	this->mouseSensitivity = SENSITIVITY;
// 	this->zoom = ZOOM;
// 	updateCameraVectors();
// }

// camera::camera(math::vec3 position)
// {
// 	this->position = position;
// 	this->worldUp = math::vec3(0.0f, 0.0f, 1.0f);
// 	this->yaw = YAW;
// 	this->pitch = PITCH;
// 	this->movementSpeed = SPEED;
// 	this->mouseSensitivity = SENSITIVITY;
// 	this->zoom = ZOOM;
// 	updateCameraVectors();
// }

// camera::camera(math::vec3 position, math::vec3 up, float yaw, float pitch)
// {
// 	this->position = position;
// 	this->worldUp = up;
// 	this->yaw = yaw;
// 	this->pitch = pitch;
// 	this->movementSpeed = SPEED;
// 	this->mouseSensitivity = SENSITIVITY;
// 	this->zoom = ZOOM;
// 	updateCameraVectors();
// }

// // constructor with scalar values
// camera::camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) 
// {
// 	this->position = math::vec3(posX, posY, posZ);
// 	this->worldUp = math::vec3(upX, upY, upZ);
// 	this->yaw = yaw;
// 	this->pitch = pitch;
// 	this->movementSpeed = SPEED;
// 	this->mouseSensitivity = SENSITIVITY;
// 	this->zoom = ZOOM;
// 	updateCameraVectors();
// }

// camera::~camera() {}

// // returns the view matrix calculated using Euler Angles and the LookAt Matrix
// math::mat4	camera::GetViewMatrix()
// {
// 	return math::lookAt(this->position, this->position + this->front, this->up);
// }

// // processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
// void	camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
// {
// 	float velocity = this->movementSpeed * deltaTime;
// 	if (direction == FORWARD)
// 		this->position += this->front * velocity;
// 	if (direction == BACKWARD)
// 		this->position -= this->front * velocity;
// 	if (direction == LEFT)
// 		this->position -= this->right * velocity;
// 	if (direction == RIGHT)
// 		this->position += this->right * velocity;
// }

// // processes input received from a mouse input system. Expects the offset value in both the x and y direction.
// void	camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
// {
// 	xoffset *= mouseSensitivity;
// 	yoffset *= mouseSensitivity;

// 	this->yaw   += xoffset;
// 	this->pitch += yoffset;

// 	// make sure that when pitch is out of bounds, screen doesn't get flipped
// 	if (constrainPitch)
// 	{
// 		if (this->pitch > 89.0f)
// 			this->pitch = 89.0f;
// 		if (this->pitch < -89.0f)
// 			this->pitch = -89.0f;
// 	}

// 	// update Front, Right and Up Vectors using the updated Euler angles
// 	updateCameraVectors();
// }

// // processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
// void	camera::ProcessMouseScroll(float yoffset)
// {
// 	this->zoom -= (float)yoffset;
// 	if (this->zoom < 1.0f)
// 		this->zoom = 1.0f;
// 	if (this->zoom > 45.0f)
// 		this->zoom = 45.0f;
// }

// // calculates the front vector from the Camera's (updated) Euler Angles
// void	camera::updateCameraVectors()
// {
// 	// calculate the new Front vector
// 	math::vec3 front;
// 	std::cout << "yaw: " << this->yaw << std::endl;
// 	std::cout << "pitch: " << this->pitch << std::endl;

// 	this->front.x = std::cos(math::radians(this->yaw)) * std::cos(math::radians(this->pitch));
// 	this->front.y = std::sin(math::radians(this->pitch));
// 	this->front.z = std::sin(math::radians(this->yaw)) * std::cos(math::radians(this->pitch));
// 	this->front = math::normalize(this->front);
// 	// also re-calculate the Right and Up vector
// 	this->right = math::normalize(math::cross(this->front, this->worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
// 	this->up    = math::normalize(math::cross(this->right, this->front));
// 	std::cout << "front: " << this->front << std::endl;
// 	std::cout << "right: " << this->right << std::endl;
// 	std::cout << "up: " << this->up << std::endl;
// }
