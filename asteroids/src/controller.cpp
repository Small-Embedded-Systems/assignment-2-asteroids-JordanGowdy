/* Controller */

/* C libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/* hardware platform libraries */
#include <mbed.h>
#include <MMA7455.h>


/* asteroids */
#include "model.h"
#include "asteroids.h"

/* Joystick 5-way switch
*/
enum position { left,down,right,up,centre };
DigitalIn joystick[] = {P5_0, P5_1, P5_4, P5_2, P5_3};

MMA7455 acc(P0_27, P0_28);
bool accInit(MMA7455& acc); //prototype of init routine
int32_t accVal[3];

bool initialisedAcc = false;

float readBoardAngle() {								//READ ANGLE
	acc.read(accVal[0], accVal[1], accVal[2]);
	if (abs(accVal[0]) < 10 ) {
		return 0; }
	else {
		if (accVal[0] < 0) {
			return -10;
		} else return 10;
	}
}



void controls(void)
{
	
	if (!initialisedAcc) {
		accInit(acc);
		initialisedAcc = true;
	}
	
 if (joystick[right].read() == 0) {
		player.v.x = -0.7;
 }
 if (joystick[left].read() == 0) {
		player.v.x = 0.7;
 }
  if (joystick[up].read() == 0) {
		player.v.y = -0.7;
 }
 if (joystick[down].read() == 0) {
		player.v.y = 0.7;
 }
 
 
 if (joystick[centre].read() == 0) {
		if (lives > 0) {
			fire();		
		}
 }
 player.heading += readBoardAngle();

}



bool accInit(MMA7455& acc) {
  bool result = true;
  if (!acc.setMode(MMA7455::ModeMeasurement)) {

    result = false;
  }
  if (!acc.calibrate()) {
  
    result = false;
  }
 
  return result;
}




