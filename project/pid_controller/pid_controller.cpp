/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi,
               double output_lim_mini) {
  /**
   * Initialize PID coefficients (and errors, if needed)
   **/
  Kp = Kpi;
  Ki = Kii;
  Kd = Kdi;
  output_lim_max = output_lim_maxi;
  output_lim_min = output_lim_mini;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  delta_time = 0;
}

void PID::UpdateError(double cte, bool debugMode = false) {
  /**
   * Update PID errors based on cte.
   **/
  //sanity check to avoid division by zero
  if(delta_time>0){
    d_error = (cte - p_error)/delta_time;
  }else{
    d_error = 0.0;
  }
  p_error = cte;
  i_error += cte*delta_time;

  if(debugMode){
  // debugging error signals to monitor performance of the controller
  cout << "######## p_error #######:"<< p_error << endl;
  cout << "######## d_error #######:"<< d_error << endl;
  cout << "######## i_error #######:"<< i_error << endl;
  }
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   * The code should return a value in the interval [output_lim_mini,
   * output_lim_maxi]
   */
  double control;
//   control = -Kp * p_error - Kd * i_error - Ki * d_error;
  control = Kp * p_error + Ki * i_error + Kd * d_error;
  if (control < output_lim_min) {
    control = output_lim_min;
  }else if (control > output_lim_max){
    control = output_lim_max;
  }
return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
  /**
   * Update the delta time with new value
   */
  delta_time = new_delta_time;
  return delta_time;
}