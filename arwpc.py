import serial
import syslog
import time
import os
from twilio.rest import Client

#Fuck you
#
port = '/dev/cu.usbmodem144301' #port to talk to

account_sid = "AC4efcf7c4ba2cbf310deb4aeb5abdc52c"
auth_token = "ce488af9a112086ca5d50f25dc0477b9"

client = Client(account_sid, auth_token)

def make_call():
    call = client.calls.create(
    to="+18506918654",
    from_="+18508188995",
    url="https://handler.twilio.com/twiml/EHc8ae7ec96e3818e744b75c584f5245ff"
    )

incomingData = serial.Serial(port, 9600, timeout=5)

time.sleep(2)

while(1):
    line = incomingData.readline()
    if (line):
        make_call()
        print("hi")
        break
    time.sleep(2)
    


