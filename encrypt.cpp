#include <iostream>
#include "encrypt.h"

double encrypt(double fTemperature){
        return( ((fTemperature - FREEZING_POINT_OF_WATER_F)*100) /
               (BOILING_POINT_OF_WATER_F - FREEZING_POINT_OF_WATER_F));
}
