import sys
import subprocess

if sys.platform.startswith("darwin"):
	print("Detected OS: OSX\n")
	subprocess.Popen("echo Radon Doesn't Support MacOS, Sorry :(", shell=True)
elif sys.platform.startswith("win32"):
	print("Detected OS: Windows\n")
	subprocess.run("mkdir dep")
	subprocess.run("cd dep")
	subprocess.run("git clone --recurse-submodules https://github.com/wxWidgets/wxWidgets.git")
	subprocess.run("mkdir wxWidgets-build")
	subprocess.run("cd wxWidgets")
	subprocess.run("cmake . -DCMAKE_INSTALL_PREFIX=..\wxWidgets-build -DwxBUILD_SHARED=OFF -DwxUSE_PRIVATE_FONTS=ON")
	subprocess.run("cmake --build . --target install")
	subprocess.run("cd ..\..")
	subprocess.run("cmake -DRA_DEBUG=OFF .")
	subprocess.run("cmake --build . --target Radon")
elif sys.platform.startswith("linux"):
	print("Detected OS: Linux")