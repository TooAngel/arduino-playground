import serial
from serial.serialutil import SerialException
import json
import time
import logging

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s %(levelname)s %(module)s.%(funcName)s%(args)s %(lineno)d: %(message)s')

def connect():
    logging.debug('connect')
    while True:
        for device in ['/dev/ttyACM0', '/dev/ttyACM1']:
            try:
                ser = serial.Serial(device, 9600)
            except SerialException as e:
#                 logging.error('SerialException: {}'.format(e))
                continue
            except OSError as e:
#                 logging.error('OSError: {}'.format(e))
                continue
                
            logging.info('Device: {}'.format(device))
            return ser

def main():
    ser = connect()
    while True:
        host = 'https://sensors.cloudcontrolapp.com'
        try:
            data = ser.readline().strip()
        except SerialException as e:
            print e
            ser = connect()
            continue
        logging.debug(data)

if __name__ == '__main__':
    main()
