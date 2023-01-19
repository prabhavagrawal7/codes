import pyautogui as py
py.sleep(4)
while True: 
    py.press("enter")
    py.sleep(3)
    py.press("#")
    py.sleep(0.5)
    py.press("enter")
    py.sleep(0.5)
    py.hotkey("command", "w")
    for _ in range(4): py.press("tab")