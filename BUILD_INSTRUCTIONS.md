# BUILD INSTRUCTIONS

# Windows:

Download and install Microsoft Visual Studio, Git and CMake.

In the Visual Studio installer, select 'C++ Desktop Development' as well as Linux Development'. Install these two modules.

Open 'Git Bash' from the Start Menu. Run the commands:

cd Desktop

git clone https://github.com/JustAnotherProgrammr/Radon.git

cd Radon

mkdir dep

cd dep

git clone --recurse-submodules https://github.com/wxWidgets/wxWidgets.git

mkdir wxWidgets-build

cd wxWidgets

cmake $(pwd) -DCMAKE_INSTALL_PREFIX=$(pwd)/../wxWidgets-build -DwxBUILD_SHARED=OFF -DwxUSE_PRIVATE_FONTS=ON

cmake --build . --target install

cd ../..

cmake -DRA_DEBUG=OFF $(pwd)

cmake --build $(pwd) --target Radon

The executable should now be in the Debug directory
