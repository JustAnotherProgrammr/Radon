import sys
import subprocess
import os

if sys.platform.startswith("darwin"):
	print("Detected OS: OSX\n")
	print("Radon currently doesn't support MacOS. Sorry! ¯\_(ツ)_/¯")
elif sys.platform.startswith("win32"):
	print("Detected OS: Windows\n")
	os.system("mkdir dep")
	os.chdir("dep")
	os.system("mkdir wxWidgets-build")	
	os.system("git clone --recurse-submodules https://github.com/wxWidgets/wxWidgets.git")
	os.chdir("wxWidgets")
	os.system("cmake . -DCMAKE_INSTALL_PREFIX=../wxWidgets-build -DwxBUILD_SHARED=OFF -DwxUSE_PRIVATE_FONTS=ON")
	os.system("cmake --build . --target install")
	os.chdir("../..")
	os.system("cmake -DRA_DEBUG=OFF .")
	os.system("cmake --build . --target Radon")
	print("Compiled Radon for Windows")
elif sys.platform.startswith("linux"):
	print("Detected OS: Linux\n")
	os.system("mkdir dep")
	os.chdir("dep")
	os.system("mkdir wxWidgets-build")	
	os.system("git clone --recurse-submodules https://github.com/wxWidgets/wxWidgets.git")
	os.chdir("wxWidgets")
	os.system("cmake . -DCMAKE_INSTALL_PREFIX=../wxWidgets-build -DwxBUILD_SHARED=OFF -DwxUSE_PRIVATE_FONTS=ON")
	os.system("cmake --build . --target install")
	os.chdir("../..")
	os.system("cmake -DRA_DEBUG=OFF .")
	os.system("cmake --build . --target Radon")
	print("Compiled Radon for Windows")
