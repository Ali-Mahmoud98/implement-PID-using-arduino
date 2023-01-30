# imple-PID-using-arduino
This code implements a PID (proportional-integral-derivative) control algorithm to control the temperature of a system. 
The temperature is measured by reading the analog value from a sensor connected to pin A5, which is then converted to a temperature value. 
The setpoint temperature is 25.

The PID algorithm runs in the PID_Control() function, which calculates the control signal to be sent to the output pin 4, 
which is connected to a control element (e.g. a heating element). The control signal is a combination of three terms:

   - kp * error - proportional term, which depends on the current error between the setpoint and the measured temperature.
   - (ki/T) * totalError - integral term, which depends on the accumulated error over time.
   - (kd/T) * deltaError - derivative term, which depends on the rate of change of the error.

The control signal is updated every T milliseconds, as determined by the value of deltaTime. 
The millis() function returns the number of milliseconds since the Arduino board started running the current program. 
The analogWrite() function writes an analog value to the specified output pin.
