# Get Started with Atmega16
## 1. Windows Users
1. Goto the link download the folder 
[link](https://drive.google.com/open?id=0B-8pemzk325Dd1EyTUNSVkxLaUk)
2. Extract the files 
3. Install the software downloaded
4. Writing the code 
5. Open Programmers Notepad (WinAvr)
6. Write the code in C
7. Save your program file in a new folder with name `main.c`, (any name can be given to new folder) 
8. Now after putting your code in new folder copy and paste `MakeFile` along with `dep_creater.bat` file in the new folder
9. Open MakeFile using any editor and check `MCU name
MCU = atmega16 ` 
10. Open Programmer's Notepad again goto 
 Tools > Make all 
11. Open 
 progisp > Load flash > Select the file main.hex (which was created)

## 2. Linux users
1. Open Terminal
2. Copy paste
~~~
sudo apt-get install avr-libc binutils-avr gcc-avr avrdude
~~~
~~~
sudo gedit /etc/udev/rules.d/60-objdev.rules
~~~
3. Copy paste this  
 ~~~ 
SUBSYSTEM=="usb", ENV{DEVTYPE}=="usb_device", ATTRS{idVendor}=="16c0",ATTRS{idProduct}=="05dc", 
MODE="0666",SYMLINK+="USBasp"
~~~
~~~ 
sudo /etc/init.d/udev restart 
~~~
4. Connect programmer
~~~ 
cd /dev |grep USB
~~~
5. You should see a USBasp file
   Now get back to home
~~~ 
cd ~
~~~
   Only to know how it works in linux
6. Create a file named `a.c`
7. Then to compile
~~~
avr-gcc -mmcu=atmega16 -Os a.c
~~~
8. To convert to hex
~~~
avr-objcopy -j .text -j .data -O ihex a.out a.hex
~~~
9. To initiate microcontroller
~~~
sudo avrdude -c usbasp -p m8
~~~
10. To flash into microcontroller
~~~
sudo avrdude -c usbasp -p m16 -P USBasp -U flash:w:a.hex
~~~
11. The command for compiling and uploading 
* compile
* uploading
12. You need to chmod those using
~~~
chmod a+x compile
~~~
~~~
chmod a+x upload
~~~
13. To compile 
~~~
 ./upload filename
~~~
14. If filename is example.c your command is
~~~
 ./compile example
~~~
15. To upload
~~~
 ./upload mctype filename
~~~
This generates example.hex 

16. If your microcontroller is atmega16 and filename is example.c 
~~~
 ./ upload 16 example
~~~
This uploads example.hex to mc 
