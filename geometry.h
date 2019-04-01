#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Imagine/Graphics.h"
#include "Imagine/Images.h"
#include <Imagine/LinAlg.h>
using namespace Imagine;



class IntLine{
private:
    IntPoint2 p1,p2;
public:
    IntLine();
    IntLine(IntPoint2 P1, IntPoint2 P2){
        p1 = P1;
        p2 = P2;
    }

    IntPoint2 getP1(){return p1;}
    IntPoint2 getP2(){return p2;}
    void setP1(IntPoint2 p){p1 = p;}
    void setP2(IntPoint2 p){p2 = p;}
    int Intersects(IntLine L, double e = 0.00001){
        // return 0 if strict parallel, 1 if there is a one point intersection, 2 if the same line
        IntPoint2 V1 = p2-p1;
        IntPoint2 V2 = L.getP2() - L.getP2();
        if(abs(V1.x()/V2.x() - V1.y()/V2.y()) < e ){
            IntPoint2 V3 = L.getP2() - p1;
            if(abs(V1.x()/V3.x() - V1.y()/V3.y()) < e)
                return 2;
            else
                return 0;
        }
        else{
            return 1;
        }
    }
    IntPoint2 Intersection(IntLine L){
        if(Intersects(L)==1){

            IntPoint2 V1 = p1 - p2;
            IntPoint2 V2 = L.p1 - L.p2;
            IntPoint2 V3 = L.p1 - p1;

            Vector<int> Y(2);
            Y(0) = V3.x();
            Y(1) = V3.y();

            Matrix< int > M = Matrix<int>(2,2);
            M(0,0) = V1.x();
            M(0,1) = - V2.x();
            M(1,0) = V1.y();
            M(1,1) = - V2.y();
            Vector<double> X = linSolve(M,Y);
            return p1 + int(X(0))*(p1-p2);
        }
        else{
            return IntPoint2(0, 0);
        }
    }
};

IntPoint2 Find_V_point(){
    // assuming that the photo is displayed in a window
    IntPoint2 P1,P2,P3,P4;

    cout<<"Select 2 parallel lines"<<endl;
    cout<<"To select the first line... Press with the mouse 2 points in this line"<<endl;
    getMouse(P1);
    getMouse(P2);
    IntLine L1 = IntLine(P1,P2);
    cout<<"To select the second line... Press with the mouse 2 points in this line"<<endl;
    getMouse(P3);
    getMouse(P4);
    IntLine L1 = IntLine(P1,P2);

    IntPoint2 V = L1.Intersection(L2);
    return V;
}

double d(IntPoint2 P1, IntPoint2 P2){
    return sqrt((P2-P1).x()*(P2-P1).x() + (P2-P1).y()*(P2-P1).y());
}

double Hight3(Intpoint2 Vh, Intpoint2 X, Intpoint2 Xp, Intpoint2 I, IntPoint2 C, double X_Xp_real){
    // on doit avoir l'ordre Xp.y<X.y  Xp.x = X.x et I.x=C.x et C.y<I.y
    double q = (d(X,Xp) * d(Xp,Vh)) / (d(Xp,C)*d(X,Vh));
    return X_Xp_real/(q-1); // returns XpC
}


#endif // GEOMETRY_H
