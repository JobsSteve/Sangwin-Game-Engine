/**
 * @todo Create ArrayLists for pointers and 2D pointers.
 * 
 * @mainpage C++ Sangwin Game Engine Documentation
 *
 * @section into Introduction
 *
 * This is a C++ version of the Sangwin Engine.
 *
 * @defgroup sgLights Scenegraph.Lights
 *
 * 
 */

#include "CollisionEvent.h"
#include "GetNode.h"
#include "Vec3.h"
#include "Vec2.h"
#include "OBJLoader.h"
#include "OBJLexicalAnalyser.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    char* data = new char[55];
    data[0] = '#';
    data[1] = ' ';
    data[2] = '\n';
    data[3] = 'v';
    data[4] = ' ';
    data[5] = 'v';
    data[6] = 'q';
    data[7] = ' ';
    data[8] = 'v';
    data[9] = 't';
    data[10] = ' ';
    data[11] = 'v';
    data[12] = 't';
    data[13] = 'q';
    data[14] = ' ';
    data[15] = 'v';
    data[16] = 'n';
    data[17] = ' ';
    data[18] = 'v';
    data[19] = 'n';
    data[20] = 'q';
    data[21] = ' ';
    data[22] = 'f';
    data[23] = ' ';
    data[24] = 'f';
    data[25] = 'q';
    data[26] = ' ';
    data[27] = 'g';
    data[28] = ' ';
    data[29] = 'g';
    data[30] = 'q';
    data[31] = ' ';
    data[32] = 'u';
    data[33] = 's';
    data[34] = 'e';
    data[35] = 'm';
    data[36] = 't';
    data[37] = 'l';
    data[38] = ' ';
    data[39] = '1';
    data[40] = '/';
    data[41] = '2';
    data[42] = ' ';
    data[43] = '1';
    data[44] = '/';
    data[45] = '2';
    data[46] = '/';
    data[47] = '3';
    data[48] = ' ';
    data[49] = '1';
    data[50] = '/';
    data[51] = '/';
    data[52] = '3';
    data[53] = ' ';
    data[54] = 'c';

    OBJLexicalAnalyser* o(new OBJLexicalAnalyser(data));

    int count = 0;
    while(o->getPos() < 55) {
        //if(count == 12) {
        //    cout << o->getNextTokenOBJ().toFloat() + 0.1f << "\n";
        //}
        //else {
            cout << o->getNextTokenOBJ().data << "\n";
        //}
        count++;
    }

//    SPtr<Vec3> v(new Vec3());
//    cout << !v << "\n";
//    char t = '8';
//    int n = t - '0';
//
//    cout << n+4;
}
