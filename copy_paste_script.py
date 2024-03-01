import pyautogui
import time

# Wait for a moment to switch to the text editor
time.sleep(1); 

# Code to be typed
code = """
For students at Chemawa, garage rock remained just as accessible (to perform and to attend) as it had been in the home communities from which they hailed. Garage bands had already formed in villages before the students knew they were coming to Chemawa, and when students who had played together arrived at school in Oregon, forming a modified version of their village band was natural. By remaining a constant activity even when the students' living environments had been radically altered, the garage band became an instrument of stability, tempering homesickness and facilitating social bonds - both new and old - between students.
"""

# Split the code into lines
code = code.replace("    ", "")
lines = code.split("\n")

# Iterate through each line and type it
for line in lines:
    pyautogui.write(line)
    pyautogui.press("enter")

# You can adjust the sleep time between lines if needed
# time.sleep(1)
