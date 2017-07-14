/* -------- ex_SCOC.c -> ex_SCOC.dll / ex_SCOC.so ------          */
/* compile in R with: system("gcc -shared -o scoc.dll ex_SCOC.c") */
/*                    or with system("R CMD SHLIB ex_SCOC.c")     */
    
/* Initialiser for parameter commons */
#include <R.h>

static double parms[1];
#define k parms[0]

static double forcs[1];
#define depo forcs[0]

 void scocpar(void (* odeparms)(int *, double *))
{
    int N=1;
    odeparms(&N, parms);
}

/* Initialiser for forcing commons */
 void scocforc(void (* odeforcs)(int *, double *))
{
    int N=1;
    odeforcs(&N, forcs);
}

/* Derivatives and  output variable */
void scocder (int *neq, double *t, double *y, double *ydot,
             double *out, int *ip)
{      
    if (ip[0] <2) error("nout should be at least 2");

      ydot[0] = -k*y[0] + depo;

      out[0]= k*y[0];
      out[1]= depo;
}                      

