import pyautogui
import random
n
b

def random_letter():
    return chr(random.randint(97, 122))

while(True):
    pyautogui.write(random_letter())
    pyautogui.hotkey('command', 'enter')