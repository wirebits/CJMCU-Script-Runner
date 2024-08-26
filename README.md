![CJMCU-removebg-preview](https://github.com/user-attachments/assets/c25ea15f-b204-4ddd-92b3-7bbd16d117ba)

# CJMCU-Script-Runner
Arduino script for CJMCU BadUSB to read keystrokes from an SD card and inject them.

# This project is only working on CJMCU BadUSB!

# What is CJMCU BadUSB?
It is a USB Rubber Ducky with SD card support to store large and complex scripts.

# Credits
- The mnemoics used in this tool is heavily inspired by [Hak5](https://github.com/hak5) Ducky Script.
- The main inspiration of this project is from [Seytonic](https://github.com/Seytonic).

# OS Support
- Windows 10

# Setup of Arduino IDE
1. Download Arduino IDE from [here](https://www.arduino.cc/en/software).
2. Simply install it.
3. Done! All required libraries are pre-installed in Arduino IDE.

# Setup of SD Card
## Use a SD card of atleast 8GB or above.
1. Put the SD card into a card reader. 
2. Connect to the PC/Laptop.
3. Open CMD as Administrator.
4. Type `diskpart` and hit `Enter`.
5. Type `select disk X` where `X` is the disk number and hit `Enter`.
6. Type `clean` and hit `Enter`.
7. Type `create partition primary` and hit `Enter`.
8. Type `format fs=FAT32` and hit `Enter`.
9. After sometime, the SD card is successfully formatted as FAT32 and ready to use!

# Mnemonic Table
| Mnemonics | Description | Example  |
|-----------|-------------|----------|
| WAIT      | It add time in the code.<br>Time is in milliseconds.<br>1000 ms = 1 second. | WAIT 1000 |
| TYPE      | It add text want to type in the code. | TYPE Hello World! |

# Install and Run
1. Download or Clone the Repository.
2. Open the folder.
3. Open the `CJMCU-Script-Runner.ino` in Arduino IDE.
4. Select the board `Arduino Leonardo`.
5. Select the correct port number of that board.
6. Simply upload the code in the board.
7. When uploaded successfully, the red led flashes.
8. Type your script in a `.txt` file and save the file with name `script` in the SD card.
9. Put the SD card in the CJMCU BadUSB.
10. Connect the CJMCU BadUSB to the PC/Laptop.
11. Done!
- The script starts running.

# Reset the board
- It has a button to reset the board.
- But if the button is broken, then short the `RST` and `GND` pins.

![ResetCJMCU-removebg-preview](https://github.com/user-attachments/assets/c394dbd1-9a56-461c-97ff-a69174245cc5)

# Before Coding...
Start your code with `WAIT` so that board get time to initiate.

# Examples
## Open notepad and type Hello World!

```
WAIT 1000
GUI R
WAIT 1000
TYPE notepad
WAIT 1000
ENTER
WAIT 1000
TYPE Hello World!
```
## Open CMD as Administrator Mode

```
WAIT 1000
GUI R
WAIT 1000
TYPE cmd
WAIT 1000
CTRL SHIFT ENTER
WAIT 1300
ALT Y
```
## Create A New Folder
```
WAIT 1000
CTRL SHIFT N
WAIT 1200
TYPE hello
WAIT 1100
ENTER
```
