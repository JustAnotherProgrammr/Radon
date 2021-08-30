import sys
import os

# if we are on MacOS
if sys.platform.startswith("darwin"):
	print("Detected OS: OSX\n")
	print("Radon currently doesn't support MacOS. Sorry! ¯\_(ツ)_/¯")
# if we are on Windows
elif sys.platform.startswith("win32"):
	print("Detected OS: Windows\n")
	os.system("git submodule update --init --recursive")
	os.chdir("vendor")
	os.system("mkdir wxWidgets-build")	
	os.chdir("wxWidgets")
	os.system("cmake . -DCMAKE_INSTALL_PREFIX=../wxWidgets-build -DwxBUILD_SHARED=OFF -DwxUSE_PRIVATE_FONTS=ON")
	os.system("cmake --build . --target install")
	print("Setup Radon for Windows")
# if we are on Linux
elif sys.platform.startswith("linux"):
	print("Detected OS: Linux\n")
	os.system("git submodule update --init --recursive")
	os.chdir("vendor")
	os.system("mkdir wxWidgets-build")	
	os.chdir("wxWidgets")
	os.system("cmake . -DCMAKE_INSTALL_PREFIX=../wxWidgets-build -DwxBUILD_SHARED=OFF -DwxUSE_PRIVATE_FONTS=ON")
	os.system("cmake --build . --target install")
	print("Setup Radon for Linux")
