#include "stdio.h"
#include "stdlib.h"
#include <fstream> 
#include <iostream> 
#include "math.h"
#include "string.h"
#include "time.h"
#include <cmath>
#include <iomanip>

using namespace std;

double rand_uniform ( long rand_int ) {
  return double(rand_int) / (double)RAND_MAX;
}

int iseed = time(0);

int main ( int argc, char** argv ) {

  double radius = 0.5;
  double radius_2 = pow(radius,2);

  double x_1 = 0;
  double x_2 = 0;
  double x_3 = 0;
  
  double pnumber = 100000;
  
  double counters_o = 0;
  double counters_i = 0;
  double counters_t = 0;

  double ratio = 0;
  double boxsize = pow(2*radius,3);
  double volume = 0;
  double pi_a = 0;

  double x_1_2 = 0;
  double x_2_2 = 0;
  double x_3_2 = 0;

  std::remove( "pn_and_pi.txt");
  ofstream pn_and_pi;

  for ( int i = 0; i < (pnumber+1); i++ ) {
    x_1 = rand_uniform (rand()) / 2;
    x_2 = rand_uniform (rand()) / 2;
    x_3 = rand_uniform (rand()) / 2;

    x_1_2 = pow(x_1,2);
    x_2_2 = pow(x_2,2);
    x_3_2 = pow(x_3,2);

    if ( (x_1_2 + x_2_2 + x_3_2) <= radius_2) {
      counters_i += 1;
      counters_t += 1;
    }
    
    if ( (x_1_2 + x_2_2 + x_3_2) > radius_2) {
      counters_o +=1;
      counters_t +=1;
    }

    ratio = counters_i / counters_t;
    volume = ratio * boxsize;
    pi_a = (3 * volume ) / ( 4 * pow(radius,3));
   
    pn_and_pi.open ( "pn_and_pi.txt", ios::app);
    pn_and_pi << std::setprecision(15) << i << "\t" << pi_a << endl;
    pn_and_pi.close();
  }
  cout << pnumber << "\t" << volume << "\t" << pi_a << endl;

  return 0;
}
