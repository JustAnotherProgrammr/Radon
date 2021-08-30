import sys
import os

if sys.platform.startswith("darwin"):
	print("Detected OS: OSX\n")
	print("Radon currently doesn't support MacOS. Sorry! ¯\_(ツ)_/¯")
elif sys.platform.startswith("win32"):
	os.system("cmake -DRA_DEBUG=OFF .")
	os.system("cmake --build . --target Radon")
elif sys.platform.startswith("linux"):	
	os.system("mkdir build")
	os.chdir("build")
	os.system("cmake -DRA_DEBUG=OFF $(pwd)/..")
	os.system("cmake --build $(pwd) --target Radon")
