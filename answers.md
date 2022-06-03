* Add the plots to your report and explain them (describe what you see)  
  - The following figure shows the steering error and steering output. There are four parts of the timeline where the error becomes extremely large, these happened when the vehicle was avoiding a car in front of it and had to change its path. The oscillation also influences the error curve will require tweaking of the parameters.  
![](./screenshots/Figure_1.png)  
  - The following figure show continuous osciallation in error throttle which will not provide smooth experience requires further adjust parameters.  
![](./screenshots/Figure_2.png)  
* What is the effect of the PID according to the plots, how each part of the PID affects the control command?    
  - We need PID controller doesn't overshoot and minimizes the error in a short range of time. PID controller can minimize the mistake between expect and actual speed / yaw angle of the vehicle by producing control output.  Within this project the PID parameters were adjust to keep the drive smooth.  P is a proportional controller which producing control output proportional to the current difference between ideal and actual value of the state variable. I is a integral controller helps to reduce time to minimizing the error using the sum of the previous errors multiplied by constant parameter and remove the bias when P controller is no longer able to reduce the error. D is a derivative  controller for ease of the error rate to reduce the overshooting. 
     
* How would you design a way to automatically tune the PID parameters?
  - Implementing twiddle algorithm to optimize a set of  parameters which was covered in PID control Parameter Optimization lesson. By offering initial values for the PID parameters and probing intervals we can run the PID controller and analyze the control output and tweaking the parameters up and down by examining the outcome, calculates the new quality marker and replaces the parameters only if the result is better.

* PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?  

* (Optional) What would you do to improve the PID controller?   
  - PID controller should be fine-tuned by attempting different scenarios with higher speeds and dividing a few ranges of speed that would utilize diverse parameters.
