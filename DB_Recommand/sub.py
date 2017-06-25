import sqlite3
import paho.mqtt.client as mqtt
conn = sqlite3.connect("iot")
cur = conn.cursor()
sql_select_alltables = "select name FROM sqlite_master WHERE type = 'table'";
cnt_place = [0,0,0,0,0,0,0,0,0]
flag_place = [0,0,0,0,0,0,0,0,0]
compare_place = [[0,0,0,0,0,0,0], [2,3,4,5,6,7,8] , [1,4,3,6,5,8,7] ,
                 [1,4,5,2,6,7,8], [2,3,6,1,5,7,8] , [3,6,7,4,8,1,2] ,
                 [4,5,8,3,7,2,1], [5,8,6,3,4,1,2] , [6,7,5,4,3,2,1]]
compare_place_for_new = [8,7,6,5,4,3,2,1]
currcar = "car_1"



def on_connect(client,userdata,flags, rc):
    print("Connected with result code " + str(rc))
    #car number subscribe
    client.subscribe("car_1")
    client.subscribe("car_2")
    client.subscribe("car_3")
    client.subscribe("car_4")
    client.subscribe("car_5")
    client.subscribe("car_6")
    client.subscribe("car_7")
    client.subscribe("car_8")
    #ultra subscribe
    client.subscribe("ultra/#")
    

def on_message(client, userdata, msg):
    global cnt_place
    global flag_place
    global cur
    global compare_place
    global compare_place_for_new
    global sql_select_alltables
    global currcar
    
    if msg.topic == "ultra/0":
        return
    
    client_2 = mqtt.Client()
    client_2.connect("192.168.0.24", 1883)
    print msg.topic + " : "+msg.payload
    print flag_place
    if msg.topic == "ultra/1":
        if msg.payload == "already":
            if flag_place[1] == 0:
                print "currcar : " + currcar
                cur.execute("insert into " +currcar + "(place) values(1)");
                conn.commit()
                print "insert 1 ok"
            flag_place[1] = 1
        else:
            flag_place[1] = 0
        return
    if msg.topic == "ultra/2":
        if msg.payload == "already":
            if flag_place[2] == 0:
                print "currcar : " + currcar
                cur.execute("insert into " +currcar + "(place) values(2)");
                conn.commit()
                print "insert 2 ok"
            flag_place[2] = 1
        else:
            flag_place[2] = 0
        return
    if msg.topic == "ultra/3":
        if msg.payload == "already":
            if flag_place[3] == 0:
                print "currcar : " + currcar
                cur.execute("insert into " +currcar + "(place) values(3)");
                conn.commit()
                print "insert 3 ok"
            flag_place[3] = 1
        else:
            flag_place[3] = 0
        return
    if msg.topic == "ultra/4":
        if msg.payload == "already":
            if flag_place[4] == 0:
                print "currcar : " + currcar
                cur.execute("insert into " +currcar + "(place) values(4)");
                conn.commit()
                print "insert 4 ok"
            flag_place[4] = 1
        else:
            flag_place[4] = 0
        return
    if msg.topic == "ultra/5":
        if msg.payload == "already":
            if flag_place[5] == 0:
                print "currcar : " + currcar
                cur.execute("insert into " +currcar + "(place) values(5)");
                conn.commit()
                print "insert 5 ok"
            flag_place[5] = 1
        else:
            flag_place[5] = 0
        return
    if msg.topic == "ultra/6":
        if msg.payload == "already":
            if flag_place[6] == 0:
                print "currcar : " + currcar
                cur.execute("insert into " +currcar + "(place) values(6)");
                conn.commit()
                print "insert 6 ok"
            flag_place[6] = 1
        else:
            flag_place[6] = 0
        return
    if msg.topic == "ultra/7":
        if msg.payload == "already":
            if flag_place[7] == 0:
                print "currcar : " + currcar
                cur.execute("insert into " +currcar + "(place) values(7)");
                conn.commit()
                print "insert 7 ok"
            flag_place[7] = 1
        else:
            flag_place[7] = 0
        return
    if msg.topic == "ultra/8":
        if msg.payload == "already":
            if flag_place[8] == 0:
                print "currcar : " + currcar
                cur.execute("insert into " +currcar + "(place) values(8)");
                conn.commit()
                print "insert 8 ok"
            flag_place[8] = 1
        else:
            flag_place[8] = 0
        return

    currcar = msg.topic
    print "currcar : " +currcar
            
    cur.execute(sql_select_alltables)
    rows = cur.fetchall()
    # compare topic and table name
    for row in rows:
        cnt_place = [0,0,0,0,0,0,0,0,0]
        # old car
        if msg.topic == row[0]:
            sql_select_topic = "select * from '"+row[0]+"'";
            cur.execute(sql_select_topic)
            rows = cur.fetchall()
            for row in rows:
                if row[0] == 1:
                    cnt_place[row[0]] +=1
                if row[0] == 2:
                    cnt_place[row[0]] +=1
                if row[0] == 3:
                    cnt_place[row[0]] +=1
                if row[0] == 4:
                    cnt_place[row[0]] +=1
                if row[0] == 5:
                    cnt_place[row[0]] +=1
                if row[0] == 6:
                    cnt_place[row[0]] +=1
                if row[0] == 7:
                    cnt_place[row[0]] +=1
                if row[0] == 8:
                    cnt_place[row[0]] +=1
            #calculate max cnt
            place_max = max(cnt_place)
            index = 0 #max index
            for place in cnt_place:
                if place_max == cnt_place[index]:
                    break
                index +=1
            print "index : " +str(index)
            if flag_place[index] == 1 :#not empty
                for i in compare_place[index]:
                    if flag_place[compare_place[index][i]] == 0:
                        print str(i)
                        index = compare_place[index][i]
                        break
                    
            #publish index
            client_2.publish("recommand" , index)
            print "recommand1" + " : " + str(index)
            return
    # new car
    #create table for new car
    sql_create_table = "create table '"+msg.topic + "' (place integer);";
    cur.execute(sql_create_table)
    recommand = 0
    index_2 = 0
    for i in compare_place_for_new:
        if flag_place[compare_place_for_new[index_2]] == 0: #empty
            recommand = compare_place_for_new[index_2]
            client_2.publish("recommand" , recommand)
            print "recommand2" + " : " + str(recommand)
            break
        index_2 +=1
            
        
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("192.168.0.24", 1883)

try:
    client.loop_forever()
except KeyboardInterrupt:
    print("Finished!")
    cur.execute("drop table car_1;");
    conn.commit();
    cur.execute("drop table car_2;");
    conn.commit();
    cur.execute("drop table car_3;");
    conn.commit();
    cur.execute("drop table car_4;");
    conn.commit();
    cur.execute("drop table car_5;");
    conn.commit();
    cur.execute("drop table car_6;");
    conn.commit();
    cur.execute("drop table car_7;");
    conn.commit();
    cur.execute("drop table car_8;");
    conn.commit();
    
    client.loop_stop()
    client.unsubscribe(["car_1" ,"car_2" ,"car_3" ,"car_4" ,"car_5" ,"car_6" ,"car_7" ,"car_8" , "ultra/#"])
    client.disconnect()
    
    
    
