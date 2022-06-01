#include <iostream>
#include "Sculptor.h"

int main(){

        //  DIRECAO X, Y, Z
    Sculptor XYZ(6, 6, 6);
    XYZ.setColor(1, 0, 0, 1);

    XYZ.putBox(0, 4, 0, 0, 0, 0);
    XYZ.putBox(0, 0, 0, 2, 0, 0);
    XYZ.putBox(0, 0, 0, 0, 0, 1);

    XYZ.writeOFF("XYZ_View.off");

        //  DRAGONFLY
    int i=0;
    Sculptor df(150, 60, 100);              // XYZ DIMENSION

    df.setColor(102, 51, 0, 1.0);           // BROWN
    df.putBox(0, 149, 0, 0, 0, 99);         // FLOOR
    df.cutEllipsoid(25, 0, 0, 20, 1, 35);   // CUT FLOOR1
    df.cutEllipsoid(75, 0, 0, 20, 1, 35);   // CUT FLOOR2
    df.cutEllipsoid(125, 0, 0, 20, 1, 35);  // CUT FLOOR3
    df.cutEllipsoid(25, 0, 99, 20, 1, 35);  // CUT FLOOR4
    df.cutEllipsoid(75, 0, 99, 20, 1, 35);  // CUT FLOOR5
    df.cutEllipsoid(125, 0, 99, 20, 1, 35); // CUT FLOOR6

    df.setColor(160, 160, 160, 1.0);        // GREY
    while(i<20){
        df.putVoxel(38, i, 50);             // STICK HOLDING THE BUG
                                            // PODE SER FEITO COM: df.putBox(38, 38, 0, 20, 50, 50);
        i++;
    }

    df.setColor(0, 204, 0, 1.0);            // LIGHT GREEN
    df.putSphere(20, 20, 50, 8);            // HEAD
    df.cutVoxel(12, 20, 50);                // HEAD FIX
    df.putSphere(18, 22, 45, 6);            // R EYE COLOR
    df.putSphere(18, 22, 55, 6);            // L EYE COLOR

    df.setColor(0, 153, 153, 0.3);          // TRANSPARENT CYAN
    df.putSphere(18, 22, 45, 7);            // R EYE
    df.putSphere(18, 22, 55, 7);            // L EYE
    df.cutVoxel(11, 22, 45);                // R EYE FIX1
    df.cutVoxel(18, 29, 45);                // R EYE FIX2
    df.cutVoxel(18, 22, 38);                // R EYE FIX3
    df.cutVoxel(11, 22, 55);                // L EYE FIX1
    df.cutVoxel(18, 29, 55);                // L EYE FIX2
    df.cutVoxel(18, 22, 62);                // L EYE FIX3

    df.setColor(255, 255, 102, 1.0);        // LIGHT YELLOW
    df.putEllipsoid(15, 15, 50, 10, 2, 8);  // MOUTH
    df.cutBox(5, 13, 13, 17, 48, 52);       // TEETH SEPARATION

    df.setColor(0, 204, 0, 1.0);            // LIGHT GREEN
    df.putEllipsoid(38, 20, 50, 20, 8, 8);  // BODY

    df.setColor(224, 224, 224, 0.3);        // TRANSPARENT WHITE
    df.putEllipsoid(31, 26, 30, 5, 1, 22);  // WING UR
    df.putEllipsoid(31, 26, 70, 5, 1, 22);  // WING UL
    df.putEllipsoid(45, 26, 30, 5, 1, 22);  // WING DR
    df.putEllipsoid(45, 26, 70, 5, 1, 22);  // WING DL

    df.setColor(32, 32, 32, 1.0);           // BLACK
    df.putBox(30, 32, 15, 18, 31, 46);      // LEG UR1
    df.putBox(30, 32, 10, 15, 31, 34);      // LEG UR2
    df.cutSphere(31, 10, 34, 2);            // LEG UR TOES
    df.putBox(30, 32, 15, 18, 54, 69);      // LEG UL1
    df.putBox(30, 32, 10, 15, 66, 69);      // LEG UL2
    df.cutSphere(31, 10, 66, 2);            // LEG UL TOES
    df.putBox(44, 46, 15, 18, 31, 46);      // LEG DR1
    df.putBox(44, 46, 10, 15, 31, 34);      // LEG DR2
    df.cutSphere(45, 10, 34, 2);            // LEG DR TOES
    df.putBox(44, 46, 15, 18, 54, 69);      // LEG DL1
    df.putBox(44, 46, 10, 15, 66, 69);      // LEG DL2
    df.cutSphere(45, 10, 66, 2);            // LEG DL TOES

    df.setColor(0, 204, 204, 1.0);          // CYAN
    df.putBox(48, 118, 18, 22, 48, 52);     // TAIL

    df.setColor(32, 32, 32, 1.0);           // BLACK
    df.putSphere(62, 20, 50, 3);            // TAIL GURTH 1
    df.putSphere(72, 20, 50, 3);            // TAIL GURTH 2
    df.putSphere(82, 20, 50, 3);            // TAIL GURTH 3
    df.putSphere(92, 20, 50, 3);            // TAIL GURTH 4
    df.putSphere(102, 20, 50, 3);           // TAIL GURTH 5
    df.putSphere(112, 20, 50, 3);           // TAIL GURTH 6

    df.setColor(160, 160, 160, 1.0);        // GREY
    df.putEllipsoid(118, 20, 50, 8, 2, 2);  // STINGER

    df.writeOFF("DragonFly.off");
}
