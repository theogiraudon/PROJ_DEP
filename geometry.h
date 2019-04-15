#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Imagine/Graphics.h"
#include "Imagine/Images.h"
#include <Imagine/LinAlg.h>
using namespace Imagine;
using namespace std;

class IntPlane{
private:
    IntPoint2 p1,p2,p3;
public:
    IntPlane();
    IntPlane(IntPoint2 P1, IntPoint2 P2, IntPoint2 P3){
        p1 = P1;
        p2 = P2;
        p3 = P3;
    }

    IntPoint2 getP1(){return p1;}
    IntPoint2 getP2(){return p2;}
    IntPoint2 getP3(){return p3;}

    void setP1(IntPoint2 p){p1 = p;}
    void setP2(IntPoint2 p){p2 = p;}
    void setP3(IntPoint2 p){p3 = p;}

};

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
        IntPoint2 V2 = L.getP2() - L.getP1();
        if(abs(V1.x()*V2.y() - V1.y()*V2.x()) < e ){
            IntPoint2 V3 = L.getP2() - p1;
            if(abs(V1.x()*V3.y() - V1.y()*V3.x()) < e)
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

            Vector<double> Y(2);
            Y[0] = V3.x();
            Y[1] = V3.y();

            Matrix< double > M = Matrix<double>(2,2);
            M(0,0) = V1.x();
            M(0,1) = - V2.x();
            M(1,0) = V1.y();
            M(1,1) = - V2.y();
            Vector<double> X = linSolve(M,Y);
            return p1 + int(X[0])*(p1-p2);
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
    drawPoint(P1, RED, 5);
    getMouse(P2);
    drawPoint(P2, RED, 5);
    IntLine L1 = IntLine(P1,P2);
    drawLine(P1, P2, GREEN, 2);
    cout<<"To select the second line... Press with the mouse 2 points in this line"<<endl;
    getMouse(P3);
    drawPoint(P3, RED, 5);
    getMouse(P4);
    drawPoint(P4, RED, 5);
    IntLine L2 = IntLine(P3,P4);
    drawLine(P3, P4, GREEN, 2);

    IntPoint2 V = L1.Intersection(L2);
    return V;
}

double d(IntPoint2 P1, IntPoint2 P2){
    return sqrt((P2-P1).x()*(P2-P1).x() + (P2-P1).y()*(P2-P1).y());
}

double Hight3(IntPoint2 Vh, IntPoint2 X, IntPoint2 Xp, IntPoint2 I, IntPoint2 C, double X_Xp_real){
    // on doit avoir l'ordre Xp.y<X.y  Xp.x = X.x et I.x=C.x et C.y<I.y et C.x=X.x in the real 3D world
    double q = (d(X,Xp) * d(Xp,Vh)) / (d(Xp,C)*d(X,Vh));
    return X_Xp_real/(q-1); // returns XpC == CI reel
}

double Hight_advanced(IntLine VL, IntPoint2 Vh, IntPoint2 X, IntPoint2 Xp, IntPoint2 I, IntPoint2 C, double X_Xp_real){
    // on doit avoir l'ordre Xp.y<X.y  Xp.x = X.x et I.x=C.x et C.y<I.y et (C.x=X.x)
    // X et I on la meme z dans le monde reel

    // on calcul le vanishing point intermediaire
    IntPoint2 Vi = VL.Intersection(IntLine(X,I));

    // On calcul le point Cp image de C dans XXp
    IntPoint2 Cp = IntLine(Vi,C).Intersection(IntLine(X,Xp));

    return Hight3(Vh, X, Xp, X, Cp, X_Xp_real); //return CI reel

}


#endif // GEOMETRY_H
