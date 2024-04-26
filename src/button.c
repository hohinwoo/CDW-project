#include <stdio.h>  
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "button.h"

const int BUTTON_WIDTH = 200;
const int BUTTON_HEIGHT = 50;
const int BUTTON_X = 100;
const int BUTTON_Y = 200;

SDL_Rect button;

// Button textures
SDL_Texture* buttonTexture;
SDL_Texture* buttonTextureHover;

// Initialize button
void initButton(SDL_Renderer* renderer) {
	
    button.x = BUTTON_X;
    button.y = BUTTON_Y;
    button.w = BUTTON_WIDTH;
    button.h = BUTTON_HEIGHT;

SDL_FreeSurface(buttonSurface);
}

int handleButton(SDL_Event* event, SDL_Renderer* renderer) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // Check if mouse is over the button
    if (mouseX >= button.x && mouseX <= button.x + button.w &&
        mouseY >= button.y && mouseY <= button.y + button.h) {
        // Render hover texture
        SDL_RenderCopy(renderer, buttonTextureHover, NULL, &button);

        // Check if button is clicked
        if (event->type == SDL_MOUSEBUTTONDOWN) {
            // Button clicked
            return 1;
        }
    } else {
        // Render normal texture
        SDL_RenderCopy(renderer, buttonTexture, NULL, &button);
    }

    return 0;
}

void renderButton(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, buttonTexture, NULL, &button);
}