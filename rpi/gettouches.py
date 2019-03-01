import serial
import argparse
from binascii import unhexlify
from pythonosc import osc_message_builder
from pythonosc import udp_client

arduino = serial.Serial("/dev/ttyUSB0",timeout=1,baudrate=115200)

# OSC parser stuff
parser = argparse.ArgumentParser()
parser.add_argument("--ip", default="localhost")
parser.add_argument("--port", type=int, default=5454)
args = parser.parse_args()

client = udp_client.SimpleUDPClient(args.ip, args.port)


while True:
        if arduino.read():
                reading = str(arduino.readline().decode("utf-8"))
                print(reading)
                client.send_message("/arduino", reading)
