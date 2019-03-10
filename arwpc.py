import serial
import syslog
import time
import os
from twilio.rest import Client
import tweepy

# Tweepy get_api method
def get_api(cfg):
    auth = tweepy.OAuthHandler(cfg['consumer_key'], cfg['consumer_secret'])
    auth.set_access_token(cfg['access_token'], cfg['access_token_secret'])
    return tweepy.API(auth)
# cfg container
cfg = {
  "consumer_key"	: "",
  "consumer_secret"	: "",
  "access_token"	: "",
  "access_token_secret" : ""
}

# call Tweepy api method
api = get_api(cfg)

# Tweet String
tweet = "TEST  WILDFIRE LONGITUDE 76.901 LATITUDE 27.335 TIME"\
	" 0753 AUTOMATED MSG @mlhacks "

# Arduino Serial Port
port = '/dev/tty96B0' #port to talk to

# Twilio tokens
account_sid = ""
auth_token = ""

# Twilio object container
client = Client(account_sid, auth_token)

# Twilio make call method
def make_call():
    call = client.calls.create(
    to="",
    from_="",
    url="https://handler.twilio.com"
    )

# Read in data from Arduino
incomingData = serial.Serial(port, 9600, timeout=5)

# Synchronicity
time.sleep(2)

while(1):
    line = incomingData.readline()
    if (line):
        make_call()
        status = api.update_status(status=tweet)
        print(line)
        continue
    time.sleep(2)

    



    


