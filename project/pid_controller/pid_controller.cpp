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
  cte = 0.0;
  diff_cte = 0.0;
  int_cte = 0.0;
}

void PID::UpdateError(double current_cte) {
  /**
   * Update PID errors based on cte.
   **/
   double prev_cte =cte;
   diff_cte = (current_cte-prev_cte)/delta_time;
   int_cte += cte*delta_time;
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   * The code should return a value in the interval [output_lim_mini,
   * output_lim_maxi]
   */
  double control = -Kp * cte - Kd * diff_cte - Ki * int_cte;
  control = min(control, output_lim_max);
  control = max(control, output_lim_min);
  return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
  /**
   * Update the delta time with new value
   */
  delta_time = new_delta_time;
}