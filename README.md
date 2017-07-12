# Telemetry

Running the code:

1. Wire the transmitting and receiving setups as shown in the PCB or arduino digrams.
2. Run the transmission code to begin flashing the light.
3. Have the setup for the receiving end ready but do not run it. Take note of what serial port your receiver is connected to and go to the matlab script.
4. On the MATlab script, change the port you will be reading from (currently '/dev/cu.usbmodem1461') to whatever port you are connected to on the receiving end.
5. Run the arduino receiving script to begin the reception but do NOT open the serial monitor.
6. In Matlab, run the livePlotter script making sure you can also access the livePlot.m function.
7. Wait about a minute for the sensor to detect enough readings and plotting should begin.
