# import headers
import RPi.GPIO as gpio
import paho.mqtt.client as mqtt
import time

trig_pin = 10
echo_pin = 9

# gpio settings
gpio.setwarnings(False)

gpio.setmode(gpio.BCM)
gpio.setup(trig_pin, gpio.OUT)
gpio.setup(echo_pin, gpio.IN)

# if state is connected, this method called
def on_connect(client, userdata, flags, rc):
	print("Connected with result code " + str(rc))

# if message published, this method called
def on_publish(client, userdata, mid):
	msg_id = mid
	print("message published")

# define mqttc as mqtt.Client
mqttc = mqtt.Client()

# connect instance value as user defined method
mqttc.on_connect = on_connect
mqttc.on_publish = on_publish

# connect client
mqttc.connect("localhost")

# loop start
mqttc.loop_start()

# try
try:
	# infinite loop
	while True:
		# trig pin initialize as False 
		gpio.output(trig_pin, False)
		time.sleep(0.5)

		# using ultrasonic sensor 
		gpio.output(trig_pin, True)
		time.sleep(0.00001)
		gpio.output(trig_pin, False)

		while gpio.input(echo_pin) == 0:
			pulse_start = time.time()

		while gpio.input(echo_pin) == 1:
			pulse_end = time.time()

		pulse_duration = pulse_end - pulse_start
		
		# calculate distance
		distance = pulse_duration * 17000
		distance = round(distance, 2)

		# print distance
		print "ParkingLot_3_Distance : ", distance, "cm"

		if distance <= 3:
			(result, m_id) = mqttc.publish("ultra/3", "already")
		else:
			(result, m_id) = mqttc.publish("ultra/3", "yet")
                                        
		time.sleep(3)

# exception handling process
except KeyboardInterrupt as e:
	gpio.cleanup()  
	# mqttc loop stop and disconnect
	mqttc.loop_stop()
	mqttc.disconnect()
