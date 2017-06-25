import serial
import time
import paho.mqtt.client as mqtt
import threading

ser1 = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
ser2 = serial.Serial('/dev/ttyACM1', 9600, timeout=1)

isArdu_1_Busy = 0
isArdu_2_Busy = 0

def on_connect(client, userdata, rc):
	print "connected with result code " + str(rc)
	#client.subscribe("car_1")
	#client.subscribe("car_2")
        #client.subscribe("car_3")
        #client.subscribe("car_4")
        #client.subscribe("car_5")
        #client.subscribe("car_6")
        #client.subscribe("car_7")
        #client.subscribe("car_8")
	client.subscribe("recommand")

def on_message(client, userdata, msg):
	print "Topic : " + msg.topic + " Message : " + msg.payload
	
	global isArdu_1_Busy
	global isArdu_2_Busy

	if isArdu_1_Busy == 0:
		isArdu_1_Busy = 1

		if msg.payload == '1':
			t = threading.Thread(target=route_on_1, args=('1'))
			t.start()
		elif msg.payload == '2':
			#ser.write('2')
                        t = threading.Thread(target=route_on_1, args=('2'))
                        t.start()	
		elif msg.payload == '3':
			#ser.write('3')
                        t = threading.Thread(target=route_on_1, args=('3'))
                        t.start()		
		elif msg.payload == '4':
			#ser.write('4')
                        t = threading.Thread(target=route_on_1, args=('4'))
                        t.start()
		elif msg.payload == '5':
			#ser.write('5')
                        t = threading.Thread(target=route_on_1, args=('5'))
                        t.start()
		elif msg.payload == '6':
			#ser.write('6')
                        t = threading.Thread(target=route_on_1, args=('6'))
                        t.start()
		elif msg.payload == '7':
			#ser.write('7')
                        t = threading.Thread(target=route_on_1, args=('7'))
                        t.start()
		elif msg.payload == '8':
			#ser.write('8')
                        t = threading.Thread(target=route_on_1, args=('8'))
                        t.start()
	elif isArdu_2_Busy == 0:
                isArdu_2_Busy = 1

                if msg.payload == '1':
                        t = threading.Thread(target=route_on_2, args=('1'))
                        t.start()
                elif msg.payload == '2':
                        #ser.write('2')
                        t = threading.Thread(target=route_on_2, args=('2'))
                        t.start()
                elif msg.payload == '3':
                        #ser.write('3')
                        t = threading.Thread(target=route_on_2, args=('3'))
                        t.start()
                elif msg.payload == '4':
                        #ser.write('4')
                        t = threading.Thread(target=route_on_2, args=('4'))
                        t.start()
                elif msg.payload == '5':
                        #ser.write('5')
                        t = threading.Thread(target=route_on_2, args=('5'))
                        t.start()
                elif msg.payload == '6':
                        #ser.write('6')
                        t = threading.Thread(target=route_on_2, args=('6'))
                        t.start()
                elif msg.payload == '7':
                        #ser.write('7')
                        t = threading.Thread(target=route_on_2, args=('7'))
                        t.start()
                elif msg.payload == '8':
                        #ser.write('8')
                        t = threading.Thread(target=route_on_2, args=('8'))
                        t.start()
	else:
		print "Wait a Moment!"

def route_on_1(route):
	global isArdu_1_Busy
	global ser1

	ser1.write(route)
	time.sleep(10)
	isArdu_1_Busy = 0
	ser1.write('0')

def route_on_2(route):
	global isArdu_2_Busy
	global ser2

	ser2.write(route)
	time.sleep(10)
	isArdu_2_Busy = 0
	ser2.write('0')

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("192.168.0.24", 1883)

try:
	client.loop_forever()

except KeyboardInterrupt:
	ser1.write('0')
	ser2.write('0')

	ser1.close()
	ser2.close()
	client.unsubscribe(["car_1", "car_2", "car_3", "car_4", "car_5", "car_6", "car_7", "car_8"])
	client.disconnect()
