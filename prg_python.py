import serial
import subprocess as sp
from pynput.keyboard import Key , Controller
import webbrowser as web
keyboard = Controller()
ser = serial.Serial("COM3", timeout=1)
while 1 :
    commande = str(ser.readline())
    if commande == "b'OLoL\\r\\n'":
        sp.Popen(["start","LeagueClient.exe"],cwd="C://Riot Games//League of Legends ",shell=True)
    if commande == "b'CLoL\\r\\n'" :
        sp.Popen(["taskkill","/im","LeagueClient.exe","/f"],shell = True)   
    
    if commande == "b'OSpot\\r\\n'":
        sp.Popen(["start","spotify:"],shell=True)
    if commande == "b'CSpot\\r\\n'":
        sp.Popen(["taskkill","/im","Spotify.exe"],shell=True)
    
    if commande == "b'OSteam\\r\\n'":
        sp.Popen(["start","steam.exe"],cwd="F://Steam",shell=True)
    if commande == "b'CSteam\\r\\n'":
        sp.Popen(["taskkill","/im","steam.exe","/f"])

    if commande == "b'OEpic\\r\\n'":
        sp.Popen(["start","EpicGamesLauncher.exe"],cwd="F://Epic Games//Launcher//Portal//Binaries//Win32",shell=True)
    if commande == "b'CEpic\\r\\n'":
        sp.Popen(["taskkill","/im","EpicGamesLauncher.exe","/f"])
    
    if commande == "b'ODisc\\r\\n'":
        sp.Popen(["start","Discord.exe"],cwd="C://Users//remX//AppData//Local//Discord//app-0.0.309",shell=True)
    if commande == "b'CDisc\\r\\n'":
        sp.Popen(["taskkill","/im","discord.exe","/f"],shell=True)
    if commande == "b'Mic\\r\\n'":
        keyboard.press(Key.ctrl)
        keyboard.press(Key.shift)
        keyboard.press("m")
        keyboard.release("m")
        keyboard.release(Key.shift)
        keyboard.release(Key.ctrl)
    if commande == "b'Cas\\r\\n'" :
        keyboard.press(Key.ctrl)
        keyboard.press(Key.shift)
        keyboard.press("d")
        keyboard.release("d")
        keyboard.release(Key.shift)
        keyboard.release(Key.ctrl)
    
    if commande == "b'OOBS\\r\\n'":
        sp.Popen (["start","obs64.exe"],cwd="C://Program Files//obs-studio//bin//64bit",shell=True)
    if commande == "b'COBS\\r\\n'":
        sp.Popen (["taskkill","/im","obs64.exe"],shell=True)
    if commande == "b'Stre\\r\\n'am":
        keyboard.press(Key.pause)
        keyboard.release(Key.pause)
    if commande == "b'rec\\r\\n'":
        keyboard.press(Key.scroll_lock)
        keyboard.release(Key.scroll_lock)

    if commande == "b'GLE\\r\\n'":
        web.open ("https://www.google.fr/")
    if commande == "b'YTB\\r\\n'":
        web.open ("https://www.youtube.com/")
    if commande == "b'eDir\\r\\n'":
        web.open ("https://www.ecoledirecte.com/Eleves/1197/Notes")
    if commande == "b'AZ\\r\\n'":
        web.open ("https://www.amazon.fr/")

    if commande == "b'OCalc\\r\\n'":
        sp.Popen(["start","calc.exe"],cwd="C://Windows//System32",shell=True)
    if commande == "b'CCalc\\r\\n'":
        sp.Popen(["taskkill","/im","calc.exe"])
