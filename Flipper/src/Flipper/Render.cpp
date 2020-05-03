#include "Render.h"

namespace Flipper {
	RenderObject::RenderObject(const char* texture_id, SDL_Texture* texture, int x, int y, int w, int h) :id(texture_id), texture(texture) {

		render_rect.x = x;
		render_rect.y = y;

		if (w != NULL) {
			render_rect.w = w;
		}
		if (h != NULL) {
			render_rect.h = h;
		}

	};

	RenderObject::~RenderObject() {

		SDL_DestroyTexture(texture);

		delete& render_rect;

		delete id;
	};


	Renderer::Renderer(const char* window_title, int w, int h) :window_title(window_title), window_h(h), window_w(w) {


		window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

		//allocating space for 10 textures to start
		texture_stack.reserve(10);

	};

	Renderer::~Renderer() {
		for (int i = 0; i < texture_stack.size(); i++) {
			SDL_DestroyTexture(texture_stack[i].texture);
		}
		//vector method clear() frees up the memory taken by it's data.
		texture_stack.clear();

		SDL_DestroyRenderer(renderer);
		delete renderer;

		SDL_DestroyWindow(window);
		delete window;

		SDL_Quit();
	};

	void Renderer::update_base_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
		base_color[0] = r;
		base_color[1] = g;
		base_color[2] = b;
		base_color[3] = a;

		SDL_SetRenderDrawColor(renderer, r, g, b, a);
	};

	const int Renderer::get_width() const {
		return window_w;
	};

	const int Renderer::get_height() const {
		return window_h;
	};

	RenderObject* Renderer::texture_stack_push(const char* texture_name, const char* image_path, int x, int y, int w, int h) {

		SDL_Texture* tex = NULL;

		SDL_Surface* temp_surface = IMG_Load(image_path);

		if (temp_surface == NULL) {
			throw BMPLoadFailureException();
		}

		if (w == NULL) {
			w = temp_surface->w;
		}
		if (h == NULL) {
			h = temp_surface->h;
		}

		tex = SDL_CreateTextureFromSurface(renderer, temp_surface);

		RenderObject* r_o = new RenderObject(texture_name, tex, x, y, w, h);

		texture_stack.push_back(*r_o);

		SDL_FreeSurface(temp_surface);

		//returning the memory address of the renderobject in the vector.
		return &texture_stack.back();
	}

	void Renderer::update_render_object(RenderObject* r_o, int x, int y, int w, int h) {

		r_o->render_rect.x = x;
		r_o->render_rect.y = y;
		r_o->render_rect.w = w;
		r_o->render_rect.h = h;

	};

	void Renderer::update() {

		SDL_RenderClear(renderer);


		for (int i = 0; i < texture_stack.size(); i++) {
			const SDL_Rect* r_r = new SDL_Rect(texture_stack[i].render_rect);
			SDL_RenderCopy(renderer, texture_stack[i].texture, NULL, r_r);
		}

		SDL_RenderPresent(renderer);
	};

	const char* BMPLoadFailureException::what() const throw() {

		return "Failure to load BMP file and convert to texture.";

	};
}