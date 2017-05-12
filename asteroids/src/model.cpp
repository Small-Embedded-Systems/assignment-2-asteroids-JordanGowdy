/* Asteroids model */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "model.h"
#include "utils.h"
#include "asteroids.h"


//move player
ship move_ship(ship player, float Dt) {

	player.p.x = player.p.x + (player.v.x );
	player.p.y = player.p.y + (player.v.y );
	
	
	double x_acc = cos(radians(player.heading)) * (player.v.x * Dt);
	double y_acc = cos(radians(player.heading)) * (player.v.y * Dt);
	
	player.v.x = player.v.x + (x_acc * Dt);
	player.v.y = player.v.y + (y_acc * Dt);	
	
	//wrap arounds
	if(player.p.x > 480) {
			player.p.x = 0;
		}
		if(player.p.x < 0) {
			player.p.x = 480;	
		}
		if(player.p.y > 280) {
			player.p.y = 30;
		}
		if(player.p.y < 30) {
			player.p.y = 280;
	
		}
	
	return player;
	
} 

//iterative linked list for missles, update every tick
void move_missiles(missile *shots) {

	for( ; shots ; shots=shots->next ) {
		shots->p.x += sin(radians(shots->heading));
		shots->p.y += -cos(radians(shots->heading));
		}
}

//check linked list size is less than 7
int checkAsteroids(struct rock *asteroids) {
	int l = 0;
	for ( ; asteroids ; asteroids = asteroids->next, ++l){};
	return l;
	}


//prune function for missile linked list
struct missile *missilePrune(struct missile *shots) {
	if( shots ){
				struct missile *discard = shots;
				shots = shots->next;
				discard->next = NULL;
	}
	return shots;
}

//iterate through missiles and removes appropoiate missile
void *removeMissile(struct missile *shots) {
	shots = missilePrune(shots);
	for( ; shots ; shots=shots->next ) {
	shots->next = missilePrune( shots->next );
	}
	return shots;
}

//prune function for missile linked list
struct rock *asteroidPrune(struct rock *asteroids) {
	if( asteroids ){
		if(asteroids->hit) {
				struct rock *discard = asteroids;
				asteroids = asteroids->next;
				discard->next = NULL;
		}
	}
	return asteroids;
}
//iterate through asteroids and removes appropoiate bitmap
void *removeAsteroid(struct rock *asteroids) {
	asteroids = asteroidPrune(asteroids);
	for( ; asteroids ; asteroids=asteroids->next ) {
	asteroids->next = asteroidPrune( asteroids->next );
	}
	return asteroids;
}

//adds new asteroid on screen if space
rock* new_asteroids(rock *asteroids) {
		//7 on field bitmaps
    if (checkAsteroids(asteroids) < 7) {
		struct rock *genRock = (struct rock*) malloc(sizeof(struct rock));
		genRock->p.x = randrange(0,480); 
		genRock->p.y = randrange(30,300);
		genRock->heading = randrange(0,361);
		genRock->hit = false;
			int rockRange = randrange(0,100);
	  if (rockRange > 80) {
			genRock->type = 1;
			genRock->width = 15;
			genRock->height = 15;
		}
		
		else if  (rockRange > 50 && rockRange < 80) { 
			genRock->type = 2;
		  genRock->width = 20;
			genRock->height = 20;
		}
		
		else { 
			genRock->type = 3;
			genRock->width = 70;
			genRock->height = 70;
		}
	
		genRock->next = asteroids;
		return genRock;
		}
		else 
			return asteroids;
}

//iterates through asteroid list and updates 
void move_asteroids(rock *asteroids, float Dt) {

	for( ; asteroids ; asteroids=asteroids->next ) {
		if(asteroids->type == 1) {
			asteroids->p.x += sin(radians(asteroids->heading))*0.8f;//*Dt;
			asteroids->p.y += -cos(radians(asteroids->heading))*0.8f;//*Dt;
		}
		else if (asteroids->type == 2) {
			asteroids->p.x += sin(radians(asteroids->heading))*0.6f;//*Dt;
			asteroids->p.y += -cos(radians(asteroids->heading))*0.6f;//*Dt;
		}
		
		else if (asteroids->type == 3) {
			asteroids->p.x += sin(radians(asteroids->heading))*0.4f;//*Dt;
			asteroids->p.y += -cos(radians(asteroids->heading))*0.4f;//*Dt;
		}


		if(asteroids->p.x > 480) {
			asteroids->p.x = 0;
		}
		if(asteroids->p.x < 0) {
			asteroids->p.x = 480;	
		}
		if(asteroids->p.y > 280) {
			asteroids->p.y = 30;
		}
		if(asteroids->p.y < 30) {
			asteroids->p.y = 280;
		}
		
		
	}
}

//Ship collisions
bool testShipCollision(rock *asteroids) {
	
	for (; asteroids; asteroids = asteroids->next) {
		if ((player.p.x >= asteroids->p.x) &&
			(player.p.x <= (asteroids->p.x + asteroids->width))) {
				if ((player.p.y >= asteroids->p.y)  &&
					(player.p.y <= (asteroids->p.y + asteroids->height))) {
							return true;
				}
		}	
	}
	return false;
}


//missile and rock collision
void missiles_hit_rocks(missile *shots, rock *asteroids) {
	
	for ( ; shots ; shots=shots->next ) {
		
		for (; asteroids; asteroids = asteroids->next) {
		if ((shots->p.x >= asteroids->p.x) &&
				(shots->p.x <= (asteroids->p.x + asteroids->width)) 
		     && shots->p.y >= asteroids->p.y &&
					shots->p.y <= (asteroids->p.y + asteroids->height))
		{				
				shots->hit = true;
				asteroids->hit = true;				
	 }	
	}		
 }	 
}


//when user presses centre, creates new missile
void fire() {

	
		struct missile *genMissiles = (struct missile*) malloc(sizeof(struct missile));
		genMissiles->p.x = player.p.x + (cos(player.heading)); 
		genMissiles->p.y = player.p.y + (sin(player.heading)); 
		genMissiles->heading = player.heading + 90;
		genMissiles->hit = false;
		genMissiles->lifetime = 0;
		
		genMissiles->next = shots;
		shots = genMissiles;
	
	
}

//removes missiles as needed
void update_missile_list(struct missile *shots) {

	for (; shots ; shots = shots->next) {
		if (shots->lifetime > 200 || shots->hit) {
			removeMissile(shots);
		} 
		else {
		shots->lifetime++;;
		}
	}
}

//remove asteroids
void update_rock_list(struct rock *asteroids) {
	
	for (; asteroids ; asteroids = asteroids->next) {
				removeAsteroid(asteroids);
	}		
}


void physics(void)
{
		if (lives > 0) {
		player = move_ship(player, Dt);
		move_missiles(shots);
		asteroids = new_asteroids(asteroids);
		move_asteroids(asteroids,Dt);
		missiles_hit_rocks( shots, asteroids);
		update_missile_list(shots);
		update_rock_list(asteroids);
	
    if (testShipCollision(asteroids)) {
			
			if (player.resetTime <= 0) {
				  lives--;	
					player.resetTime = 100;
				
			}
		}
		else {
				  player.resetTime--;
				  score++;
			    }	
		}
}
