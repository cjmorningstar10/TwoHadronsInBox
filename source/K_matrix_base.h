#ifndef K_MATRIX_BASE_H
#define K_MATRIX_BASE_H

#include <map>


class KtildeMatrixBase
{

 public:

    virtual ~KtildeMatrixBase() {};

    virtual double calculate(uint Jtimestwo, 
                     uint Lp, uint Sptimestwo, uint chanp,
                     uint L, uint Stimestwo, uint chan,
                     double Ecm_over_mref) const = 0;

    virtual bool isZero(uint Jtimestwo, 
                uint Lp, uint Sptimestwo, uint chanp,
                uint L, uint Stimestwo, uint chan) const = 0;

};

#endif
