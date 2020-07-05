/*
	Flipper Engine Render header file

	purpose: Defines behaviour for the render functionality.

	@author: Murray Smith

	@version: 1.0
*/

#ifndef RENDER_H
#define RENDER_H


#include "Core.h"

namespace Flipper {
	//A class representing an object to be rendered to the screen.
	class FLIPPER_API RenderObject {

	public:
		//the id of the RenderObject
		const char* id;

		//the rectangle defining render position and size.
		SDL_Rect render_rect;

		//The actual texture object
		SDL_Texture* texture;

		RenderObject(const char* texture_id, SDL_Texture* texture, int x, int y, int w, int h);

		~RenderObject();

	};

	//A renderer class, storing data about the SDL window and renderer objects.
	class FLIPPER_API Renderer {
	private:

		//The width of the window.
		const int window_w;
		//The height of the window.
		const int window_h;
		//The title of the window
		const char* window_title;
		//A vector-based stack storing the texture data to be rendered each frame, 
		//its render size, and its render position stored as an instance of RenderObject
		std::vector<RenderObject> texture_stack;
		//An array representing the base render colour in RGBA format. Black by default
		Uint8 base_color[4]{ 0x00, 0x00, 0x00, 0xFF };


	public:

		//The main Window object
		SDL_Window* window;
		//The main Renderer object
		SDL_Renderer* renderer;
		//Update the base_colour
		void update_base_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

		//Return the width of the window in pixels.
		const int get_width();
		//Return the height of the window in pixels.
		const int get_height();
		//Add a RenderObject to the texture stack, which stores the data for an image to be rendered each frame. 
		//Return a pointer of the RenderObject added.
		RenderObject* texture_stack_push(const char* texture_name, const char* image_path, int x, int y, int w = NULL, int h = NULL);
		//Update the position or size of a RenderObject on the texture stack. If any of x, y, w, h are NULL, 
		//do not transform in that way.
		void update_render_object(RenderObject* r_o, int x, int y, int w, int h);
		//update and render all textures on the stack.
		void update();
		//Create a new instance of Renderer, with width w, height h, and title window_title.
		Renderer(const char* window_title, int w, int h);
		//Deconstruct the renderer, only to be done when the program ends. This method destroys the window, renderer, and all textures and shuts down SDL.
		~Renderer();

	};

	//Custom Error to be raised when a texture fails to load from a BMP file.
	struct FLIPPER_API BMPLoadFailureException : public std::exception {

		const char* what() const throw();

	};
}
#endif