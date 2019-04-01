#include <iostream>
#include <cstdlib>
#include "Imagine/Graphics.h"
#include "Imagine/Images.h"
#include "geometry.h"

using namespace std;
using namespace Imagine;

int main(int argc, char* argv[])
{
    IntPoint2 P1(0,0);
    IntLine L1(IntPoint2(1,2), IntPoint2(1,1));
    IntLine L2(IntPoint2(0,0), IntPoint2(1,2));
    cout<< L1.Intersection(L2)<<endl;

//    srand (time(NULL));

//    Image<byte> I;
//    if(! load(I, argc>1? argv[1]: srcPath("houses.jpg"))) {
//        std::cout << "Echec de lecture d'image" << std::endl;
//        return 1;
//    }

//    openWindow(I.width(), I.height());
//    display(I);
//    bool flag(true);
//    int x0,y0;
//    int xn,yn;
//    getMouse(x0,y0);
//    fillCircle(x0,y0,4,RED);
//    while(getMouse(xn,yn)!=3)
//    {   int r = rand() % 256;
//        int b = rand() % 256;
//        int g = rand() % 256;
//        Color col(r,b,g);
//        fillCircle(xn,yn,4,RED);
//        drawLine(x0,y0,xn,yn,col,5);
//        getMouse(x0,y0);
//        fillCircle(x0,y0,4,RED);
//    }


//        endGraphics();


        return 0;
}
