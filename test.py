# create very fast clicker using pyautogui which runs for 5 seconds

import pyautogui
import time

print("Starting in 3 seconds")
pyautogui.sleep(3)

print("Clicking")
start = time.time()
for i in range(0, 1000):
    pyautogui.click(interval=100); 
    
print("Done")