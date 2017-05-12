/* Asteroids view
*/

/* C libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/* hardware platform libraries */
#include <display.h>
#include <mbed.h>

#include "asteroids.h"
#include "model.h"
#include "utils.h"
#include "view.h"

Display *graphics = Display::theDisplay();

const colour_t background = BLACK; /* Black background */
//const std::uint8_t *rock2_point=rock2_bits[0];


const coordinate_t shape[] = {
    {-5,-5}, {10,0}, {-5,5}
};

/* double buffering functions */
void init_DBuffer(void)
{   /* initialise the LCD driver to use second frame in buffer */
    uint16_t *bufferbase = graphics->getFb();
    uint16_t *nextbuffer = bufferbase+ (480*272);
    LPC_LCD->UPBASE = (uint32_t)nextbuffer;
}

void swap_DBuffer(void)
{   /* swaps frames used by the LCD driver and the graphics object */
    uint16_t *buffer = graphics->getFb();
    graphics->setFb( (uint16_t*) LPC_LCD->UPBASE);
    LPC_LCD->UPBASE = (uint32_t)buffer;
}

void draw_sidebar(int score, int elapsed_time, int lives) {
graphics->drawRect(0,0,480,30,WHITE);
	graphics->setCursor(20,10);
	graphics->printf("Total : %d", score);
	graphics->setCursor(420,10);
	graphics->printf("Lives: %d",lives);
}

void drawmissiles(missile *shots) {
		for( ; shots ; shots=shots->next ) {	
		graphics->drawCircle(shots->p.x,shots->p.y,1,WHITE);	
		}
};
	


//reverse bits
unsigned char reverse(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

//Draw each type of bitmap
void drawrocks(rock *asteroids) {
	  for( ; asteroids ; asteroids=asteroids->next ) {
			if(asteroids->type == 1) {
				unsigned char pic[sizeof(rock1_bits)];
				memcpy (pic, rock1_bits, sizeof(pic));
				for (int c = 0; c < sizeof(rock1_bits) ; c++) {
					pic[c] = reverse(pic[c]);
				}
				graphics->drawBitmap(asteroids->p.x,asteroids->p.y, pic, rock1_width, rock1_height, WHITE);	
			}
			
			else if (asteroids->type == 2) {
				unsigned char pic[sizeof(rock2_bits)];
				memcpy (pic, rock2_bits, sizeof(pic));
				for (int c = 0; c < sizeof(rock2_bits) ; c++) {
					pic[c] = reverse(pic[c]);
				}
				graphics->drawBitmap(asteroids->p.x,asteroids->p.y, pic, rock2_width, rock2_height, WHITE);	
			}
				
			else if (asteroids->type == 3) {
				unsigned char pic[sizeof(bigrock_bits)];
				memcpy (pic, bigrock_bits, sizeof(pic));
				for (int c = 0; c < sizeof(bigrock_bits) ; c++) {
					pic[c] = reverse(pic[c]);
				}
				graphics->drawBitmap(asteroids->p.x,asteroids->p.y, pic, bigrock_width, bigrock_height, WHITE);	
			}	
			}
		};


void drawship(ship player) {
	
	
	//code to wraparound player ship
	if (player.p.x < 0) 
		player.p.x = 480;
	else if (player.p.x > 480) 
		player.p.x = 0;
	
	if (player.p.y < 0) 
		player.p.y = 280;
	else if (player.p.y > 280) 
		player.p.y = 0;
	
	//code to draw player ship around position
	float x1, x2, x3, y1, y2, y3;

	
	x1 = player.p.x + (shape[0].x*cos(radians(player.heading))) - (shape[0].y*sin(radians(player.heading)));
	y1 = player.p.y + (shape[0].x*sin(radians(player.heading))) + (shape[0].y*cos(radians(player.heading)));
	
	x3 = player.p.x + (shape[1].x*cos(radians(player.heading))) - (shape[1].y*sin(radians(player.heading)));
	y3 = player.p.y +(shape[1].x*sin(radians(player.heading))) + (shape[1].y*cos(radians(player.heading)));
	
	x2 = player.p.x +(shape[2].x*cos(radians(player.heading))) - (shape[2].y*sin(radians(player.heading)));
	y2 = player.p.y +(shape[2].x*sin(radians(player.heading))) + (shape[2].y*cos(radians(player.heading)));
	
	//ship detection when hit
	if (player.resetTime > 0) {
		graphics->drawTriangle(x2, y2, x3, y3, x1, y1, RED);
		graphics->fillTriangle(x2, y2, x3, y3, x1, y1, RED);
	} else {
		graphics->drawTriangle(x2, y2, x3, y3, x1, y1, WHITE);
		graphics->fillTriangle(x2, y2, x3, y3, x1, y1, WHITE);
	}

};	

void endGame() {
	
	graphics->fillScreen(RED);
	graphics->setTextSize(5);
	graphics->setTextColor(BLACK);
	graphics->setCursor(100,120);
	graphics->printf("GAME OVER");
	graphics->setTextSize(4);

};
	



void draw(void)
{
	if (lives > 0) {
  graphics->fillScreen(background);
	draw_sidebar(score,elapsed_time,lives);
	drawmissiles(shots);
	drawrocks(asteroids);
	drawship(player);
	score++;
	}
	else 
		endGame();

	//add pause print
	
	swap_DBuffer();
}
