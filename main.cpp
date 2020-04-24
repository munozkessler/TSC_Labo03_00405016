//
//  main.cpp
//  TSC_Labo03_00405016
//
//  Created by Mario Muñoz on 4/24/20.
//  Copyright © 2020 Mario Muñoz. All rights reserved.
//

#include <iostream>
#include "math_tools.h"
#include "classes.h"
#include "tools.h"
#include "sel.h"
#include "display_tools.h"

int main(){
    
    vector<Matrix> localKs;
    vector<Vector> localBs;
    
    Matrix K;
    Vector b;
    Vector T;

    mesh m;
    leerMallayCondiciones(m);

    crearSistemasLocales(m,localKs,localBs);
    
    zeroes(K,m.getSize(NODES));
    zeroes(b,m.getSize(NODES));
    ensamblaje(m,localKs,localBs,K,b);
    
    applyNeumann(m,b);
    
    applyDirichlet(m,K,b);
    zeroes(T,b.size());
    calculate(K,b,T);

    cout << "La respuesta es: \n";
    showVector(T);

    return 0;
}
