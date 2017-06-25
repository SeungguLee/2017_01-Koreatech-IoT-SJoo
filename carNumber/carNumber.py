import RPi.GPIO as gpio
import time
import paho.mqtt.client as mqtt

cn1 = 21
cn2 = 20
cn3 = 16
cn4 = 12
cn5 = 25
cn6 = 24
cn7 = 23
cn8 = 18

gpio.setwarnings(False)
gpio.setmode(gpio.BCM)
gpio.setup(cn1, gpio.IN, gpio.PUD_UP)
gpio.setup(cn2, gpio.IN, gpio.PUD_UP)
gpio.setup(cn3, gpio.IN, gpio.PUD_UP)
gpio.setup(cn4, gpio.IN, gpio.PUD_UP)
gpio.setup(cn5, gpio.IN, gpio.PUD_UP)
gpio.setup(cn6, gpio.IN, gpio.PUD_UP)
gpio.setup(cn7, gpio.IN, gpio.PUD_UP)
gpio.setup(cn8, gpio.IN, gpio.PUD_UP)

def on_connect(client, userdata, flag, rc):
	print "Connected with result code " + str(rc)

def on_publish(client, userdata, mid):
	msg_id = mid
	print "Message published"

mqttc = mqtt.Client()
mqttc.connect("192.168.0.24", 1883, 60)

mqttc.loop_start()

try:
	while True:
		if gpio.input(cn1) == 0:
			mqttc.publish("car_1", 1)
			time.sleep(1)
		elif gpio.input(cn2) == 0:
			mqttc.publish("car_2", 2)
			time.sleep(1)
		elif gpio.input(cn3) == 0:
			mqttc.publish("car_3", 3)
			time.sleep(1)
		elif gpio.input(cn4) == 0:
			mqttc.publish("car_4", 4)
			time.sleep(1)
		elif gpio.input(cn5) == 0:
			mqttc.publish("car_5", 5)
			time.sleep(1)
		elif gpio.input(cn6) == 0:
			mqttc.publish("car_6", 6)
			time.sleep(1)
		elif gpio.input(cn7) == 0:
			mqttc.publish("car_7", 7)
			time.sleep(1)
		elif gpio.input(cn8) == 0:
			mqttc.publish("car_8", 8)
			time.sleep(1)

except KeyboardInterrupt:
	gpio.cleanup()
	mqttc.loop_stop()
	mqttc.disconnect()
