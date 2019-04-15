#include <iostream>
#include <cstdlib>
#include "Imagine/Graphics.h"
#include "Imagine/Images.h"
#include "geometry.h"

using namespace std;
using namespace Imagine;

int main(int argc, char* argv[])
{
    Image<byte> img;
    load(img,srcPath("cube.jpg"));
    openWindow(img.width(), img.height());
    display(img);
    IntPoint2 V1 = Find_V_point();
    cout<<V1<<endl;
    IntPoint2 V2 = Find_V_point();
    cout<<V2<<endl;
    drawLine(V1,V2,RED);
    IntLine VL(V1,V2);

    IntPoint2 Vh = Find_V_point();
    cout<<Vh<<endl;

    IntPoint2 X, Xp, I, C;
    double X_Xp_real;

    cout<<"Enter X"<<endl;
    getMouse(X);
    drawPoint(X, RED, 5);

    cout<<"Enter Xp"<<endl;
    getMouse(Xp);
    drawPoint(Xp, RED, 5);

    cout<<"Enter I"<<endl;
    getMouse(I);
    drawPoint(I, RED, 5);

    cout<<"Enter C"<<endl;
    getMouse(C);
    drawPoint(C, RED, 5);

    cout<<"Enter the distance X_Xp in the real 3D world"<<endl;
    cin>>X_Xp_real;

    cout<<"the distance C_I in the real 3D world is : "<<Hight3(Vh, X, Xp, I, C, X_Xp_real)<<endl;

    endGraphics();






    //cout<< <<endl;

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
