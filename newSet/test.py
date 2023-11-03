# retrieve user rank from codeforces and if change, create a notification

import json
import os
import platform
import subprocess
import sys
import time

import requests
from win10toast import ToastNotifier


# get user rank from codeforces
def get_rank(handle):
    url = "http://codeforces.com/api/user.info?handles=" + handle
    response = requests.get(url)
    data = json.loads(response.text)
    return data['result'][0]['rank']

# get user rank from codeforces


def get_rating(handle):
    url = "http://codeforces.com/api/user.info?handles=" + handle
    response = requests.get(url)
    data = json.loads(response.text)
    return data['result'][0]['rating']


current = get_rating('istiaque190515')
while (True):
    time.sleep(5)
    temp = get_rating('istiaque190515')
    print("current situation:")
    print(str(temp)+' '+str(current))
    if (temp != current):
        toaster = ToastNotifier()
        toaster.show_toast("HELLO",
                           "Your rank has been changed, it is now "+temp+"",
                           icon_path=None,
                           duration=10)
        current = temp
        while toaster.notification_active():
            time.sleep(0.1)
