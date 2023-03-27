# automate for bing search
import pyautogui as py
import time
import random

def randomchar():
    return chr(random.randint(65, 90))

py.sleep(5)
while(True):
    py.hotkey('command', 'enter')
    py.press(randomchar())
    
# while(True): p
C
y
r

    # py.click()b
    