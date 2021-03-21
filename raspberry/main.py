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
    with serial.Serial(ARDUINO_PATH, SERIAL_PORT, timeout=1) as arduino:
        time.sleep(0.1)  # wait for serial to open
        if arduino.isOpen():
            print("{} connected!".format(arduino.port))
            try:
                while IS_RUNNING:

                    if arduino.inWaiting() > 0:
                        try:
                            data_received = arduino.readline()
                            print(data_received)
                        except Exception as e:
                            print(e)
            except KeyboardInterrupt:
                print("KeyboardInterrupt has been caught.")
