#include "../includes/header.hpp"
#include "../includes/game.hpp"

using namespace scop;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)action;
	(void)mods;
	(void)window;
		std::cout << key << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

int game::init(int ac, char **av, obj::mesh mesh)
{
    (void)ac;
    (void)av;

    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(width, height, "SCOP LE PROJET COOL", NULL, NULL);
    if (this->window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return 2;
	}
    glfwMakeContextCurrent(this->window);
	glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);

	std::cout << "glViewport" << std::endl;
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return 3;
	}
	std::cout << "after Glad" << std::endl;

	initShadder();
	initBuffers();

	std::cout << "Init End" << std::endl;

    return (1);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
		std::cout << "GLFW_KEY_ESCAPE" << std::endl;
        glfwSetWindowShouldClose(window, true);
    }
}

void game::loop()
{
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES ,0, 3);
		glfwSwapBuffers(window);
        glfwPollEvents();
    }
	    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return;

}
GLFWwindow *game::getWindow()
{
	return (this->window);
}

game::game(int width, int height): width(width), height(height)
{

}

float point[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    }; 
unsigned int indices[3] = {0, 1, 2};


int game::initBuffers()
{
	
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);
	
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(math::vec3), &Mesh.m_vertices[0], GL_STATIC_DRAW);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	// color attribute
	// glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3* sizeof(float)));
	// glEnableVertexAttribArray(1);

	// glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	// glEnableVertexAttribArray(2);

	// glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(8 * sizeof(float)));
	// glEnableVertexAttribArray(3);


	
	

	

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); 

	
	return (0);
}
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int game::initShadder()
{
	/*Vertex Shader*/
	int success;
	std::cout << "initShadder" << std::endl;
    char infoLog[512];


	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	if (!vertexShader)
	{
		std::cout << "vertex shadder fail" << std::endl;
		return 1;
	}
	std::cout << "vertex_shader" << std::endl;

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	try {
		glCompileShader(vertexShader);
	}
	catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);	
	/*Fragment Shader*/
	if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	if (!fragmentShader)
	{
		std::cout << "fragmentShader shadder fail" << std::endl;
		return 2;
	}
	std::cout << "fragmentShader" << std::endl;

	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

	/*Shader Program Finalisation*/
	
	this->shaderProgram = glCreateProgram();
	if (!this->shaderProgram)
	{
		std::cout << "this->shaderProgram shadder fail" << std::endl;
		return 3;
	}

	glAttachShader(this->shaderProgram, vertexShader);
	glAttachShader(this->shaderProgram, fragmentShader);
	glLinkProgram(this->shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);  
	std::cout << "End of initShadder" << std::endl;

	return (0);
}

game::~game()
{
	glfwDestroyWindow(this->window);
    
}



