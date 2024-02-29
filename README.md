# IOTPrac

**Ledblink using raspberry pie**
```
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(18, GPIO.OUT)

print("LED on")
GPIO.output(18, GPIO.HIGH)
time.sleep(1)

print("LED off")
GPIO.output(18, GPIO.LOW)
```
**Stepper Motor Python Program for Raspberry Pi**
```
import RPi.GPIO as GPIO
from time import sleep
import sys

#assign GPIO pins for motor
motor_channel = (17,20,21,22)  
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
#for defining more than 1 GPIO channel as input/output use
GPIO.setup(motor_channel, GPIO.OUT)

motor_direction = input('select motor direction a=anticlockwise, c=clockwise: ')
while True:
    try:
        if(motor_direction == 'c'):
            print('motor running clockwise\n')
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.LOW,GPIO.LOW,GPIO.HIGH))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.HIGH,GPIO.LOW,GPIO.LOW))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.HIGH,GPIO.HIGH,GPIO.LOW))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.LOW,GPIO.HIGH,GPIO.HIGH))
            sleep(0.01)

        elif(motor_direction == 'a'):
            print('motor running anti-clockwise\n')
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.LOW,GPIO.LOW,GPIO.HIGH))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.LOW,GPIO.HIGH,GPIO.HIGH))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.LOW,GPIO.HIGH,GPIO.HIGH,GPIO.LOW))
            sleep(0.01)
            GPIO.output(motor_channel, (GPIO.HIGH,GPIO.HIGH,GPIO.LOW,GPIO.LOW))
            sleep(0.01)

            
    #press ctrl+c for keyboard interrupt
    except KeyboardInterrupt:
        #query for setting motor direction or exit
        motor_direction = input('select motor direction a=anticlockwise, c=clockwise or q=exit: ')
        #check for exit
        if(motor_direction == 'q'):
            print('motor stopped')
            sys.exit(0)
```

**8x8 Grid file 1**

```
#!/usr/bin/env python
import RPi.GPIO as GPIO
import time
import tables
#SDI   = 17
#RCLK  = 18
#SRCLK = 27

SDI   = 25
RCLK  = 27
SRCLK = 24
 
per_line = [0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe]


#per_line = [0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f]

def print_msg():
    print('Program is running...')
    print('Please press Ctrl+C to end the program...')

def setup():
    GPIO.setmode(GPIO.BCM)    # Number GPIOs by its BCM location
    GPIO.setup(SDI, GPIO.OUT)
    GPIO.setup(RCLK, GPIO.OUT)
    GPIO.setup(SRCLK, GPIO.OUT)
    GPIO.output(SDI, GPIO.LOW)
    GPIO.output(RCLK, GPIO.LOW)
    GPIO.output(SRCLK, GPIO.LOW)

# Shift the data to 74HC595
def hc595_in(dat):
  for bit in range(0, 8):
    GPIO.output(SDI,(1 & (dat >> bit)))
    GPIO.output(SRCLK, GPIO.HIGH)
    time.sleep(0.000001)
    GPIO.output(SRCLK, GPIO.LOW)

def hc595_out():
    GPIO.output(RCLK, GPIO.HIGH)
    time.sleep(0.000001)
    GPIO.output(RCLK, GPIO.LOW)

def flash(table):
  for i in range(8):
    hc595_in(per_line[i])
    hc595_in(table[i])
    hc595_out()
# Clean up last line
    hc595_in(per_line[7])
    hc595_in(0x00)
    hc595_out()

def show(table, second):
    start = time.time()
    while True:
          flash(table)
          finish = time.time()
          if finish - start > second:
              break

def main():
    charactors = 'AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz1234567890!?,.<>'
    word = 'Microbyte'
    while True:
            for table in word:
                table = table.upper()
                show(tables.charactors[table],1)
                time.sleep(1)
                show(tables.picture['creeper'],1)
                time.sleep(1)
                show(tables.picture['smile'],1)
                time.sleep(1)
            for charactor in charactors:
                print("Chractor: %s", charactor)
                show(tables.charactors[charactor],1)
                time.sleep(1)

def destroy():
    GPIO.cleanup()

if _name_ == '_main_':
    setup()
    try:
        main()
    except KeyboardInterrupt:
        destroy()
```
**8x8 Grid File no 2 tables.py**
```
charactors = {
    "A" : [
    0b00000000,
    0b00011000,
    0b00100100,
    0b00100100,
    0b00111100,
    0b00100100,
    0b00000000,
    0b00000000,
    ],
    "a" : [
    0b00000000,
    0b00000000,
    0b00011100,
    0b00100100,
    0b00100100,
    0b00011100,
    0b00000000,
    0b00000000,
    ]
}
```
