import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO
import time

pin = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(pin, GPIO.OUT)

p = GPIO.PWM(pin, 50)

p.start(7.5)

onAlready = 0
cntTimer = 0

def on_connect(client, userdata, rc):
	print("connected with result code " + str(rc))
	client.subscribe("ultra/0")
	client.subscribe("ultra/1")
	client.subscribe("ultra/2")
	client.subscribe("ultra/3")
	client.subscribe("ultra/4")
	client.subscribe("ultra/5")
	client.subscribe("ultra/6")
	client.subscribe("ultra/7")
	client.subscribe("ultra/8")
	#client.subscribe("recommand")
        
def on_message(client, userdata, msg):
	global onAlready
	global cntTimer

	print("Topic: " + msg.topic + " Message: " + str(msg.payload))
	if msg.topic in "ultra/0":
		cntTimer += 1
		if msg.payload == 'already' and onAlready is 0:
			print 'Hello'
			onAlready += 1

			p.ChangeDutyCycle(7.5)
			p.ChangeDutyCycle(12.5)
			time.sleep(2)
			p.ChangeDutyCycle(7.5)
		elif msg.payload == 'yet':
			onAlready = 0

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

# YOU NEED TO CHANGE THE IP ADDRESS OR HOST NAME
client.connect("localhost", 1883, 60)
#client.connect("localhost")

try:
	client.loop_forever()
except KeyboardInterrupt:
	print("Finished!")
	client.unsubscribe(["ultra/0, ultra/1", "ultra/2", "ultra/3", "ultra/4", "ultra/5", "ultra/6", "ultra/7", "ultra/8", "recommand"])
	client.disconnect()
	p.stop()
	GPIO.cleanup()
