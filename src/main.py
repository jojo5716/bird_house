#!/usr/bin/env python
# -*- coding: utf-8 -*-
# lsusb to check device name
# dmesg | grep "tty" to find port name

import serial
import time

IS_RUNNING = True
ARDUINO_PATH = '/dev/ttyACM0'
SERIAL_PORT = 9600

if __name__ == '__main__':
    print('Running. Press CTRL-C to exit.')
    with serial.Serial(ARDUINO_PATH, SERIAL_PORT, timeout=1) as arduino:
        time.sleep(0.1)  # wait for serial to open
        if arduino.isOpen():
            print("{} connected!".format(arduino.port))
            try:
                while IS_RUNNING:
                    arduino.setDTR(False)
                    time.sleep(1)
                    arduino.flushInput()
                    arduino.setDTR(True)

                    while arduino.inWaiting() == 0:
                        pass

                    if arduino.inWaiting() > 0:
                        try:
                            answer = arduino.readline()
                            decoded_bytes = answer.decode("utf-8")
                            if decoded_bytes:
                                print(decoded_bytes)
                        except Exception as e:
                            print(e)
            except KeyboardInterrupt:
                print("KeyboardInterrupt has been caught.")
