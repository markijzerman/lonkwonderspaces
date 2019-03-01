import serial

arduino = serial.Serial("/dev/ttyUSB0",timeout=1,baudrate=115200)

while True:
        reading = str(arduino.readline().decode("utf-8"))
        print(reading)
