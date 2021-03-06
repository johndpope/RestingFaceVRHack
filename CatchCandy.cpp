//
//  CatchCandy.cpp
//  mySketch
//
//  Created by Yuping on 10/19/14.
//
//

#include "CatchCandy.h"

int CatchCandy::count = 0;

CatchCandy::CatchCandy(int w, int h) {
    width = w;
    height = h;
    pos.x = rand()%w;
    pos.y = 0;
    pos.z = 0;
    rotate = 0;
}

void CatchCandy::update(float tdelta, vec3 p1, vec3 p2, bool openMouth)  // everytime candy disappear on the buttom of the screen of catch by mouth, it starts fall from the top again
{
    int speed = 50.0;
    pos.x += rand()%2;
    pos.y += speed*tdelta;
    pos.z = p1.z - 5.0;
//    rotate += 10.0*tdelta;
    // if fall off the screen
    if(pos.y > height) { pos.y = 0; }
    // if catch by the mouth
    if(pos.x > p1.x && pos.x < p2.x && (abs(pos.y - p1.y)<10) && openMouth) {
        pos.y = 0;
//        CatchCandy::count += 1;
    }
        
}