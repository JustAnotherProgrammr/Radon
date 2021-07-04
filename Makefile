# define application root directory
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

# set non-optional compiler flags here
CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic-errors

# set non-optional preprocessor flags here
# eg. project specific include directories
CPPFLAGS += `$(ROOT_DIR)/dep/wxWidgets/gtk-build/wx-config --cxxflags --libs std, richtext`


# find cpp files in subdirectories
APPSOURCE := $(shell find . -name 'App.cpp')
MAINSOURCE := $(shell find . -name 'Main.cpp')

OUTPUT := Radon

# Everything depends on the output
all: Radon

Radon: App.o Main.o
	$(CXX) App.o Main.o $(CXXFLAGS) $(CPPFLAGS) -o $(OUTPUT)

App.o: $(APPSOURCE)
	$(CXX) -c $(APPSOURCE) $(CXXFLAGS) $(CPPFLAGS)

Main.o: $(MAINSOURCE)
	$(CXX) -c $(MAINSOURCE) $(CXXFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OUTPUT)