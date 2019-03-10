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
  "consumer_key"	: "WL2YJYOz6zBpipsJCeoJATsGX",
  "consumer_secret"	: "R0nxqaHK4UgC2xaYihTShQjZhgwpUUzstidXdagAIXltm93nXi",
  "access_token"	: "45705667-mibXZLkgiPjXCRPl9k5d6eHZW4cdepNJMSM65Gq4A",
  "access_token_secret" : "r7hTbjgMuQzWlFlpkUjjuMLhVXF1FqwocRnXYBiY7WRal"
}

# call Tweepy api method
api = get_api(cfg)

# Tweet String
tweet = "TEST  WILDFIRE LONGITUDE 76.901 LATITUDE 27.335 TIME"\
	" 0753 AUTOMATED MSG @mlhacks "

# Arduino Serial Port
port = '/dev/tty96B0' #port to talk to

# Twilio tokens
account_sid = "AC4efcf7c4ba2cbf310deb4aeb5abdc52c"
auth_token = "ce488af9a112086ca5d50f25dc0477b9"

# Twilio object container
client = Client(account_sid, auth_token)

# Twilio make call method
def make_call():
    call = client.calls.create(
    to="+18506918654",
    from_="+18508188995",
    url="https://handler.twilio.com/twiml/EHc8ae7ec96e3818e744b75c584f5245ff"
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

    



    


