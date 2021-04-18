Radon: main.cpp
	g++ main.cpp `wx-config --cxxflags --libs` -o Radon

.PHONY: test clean

test: Radon
	./Radon

clean:
	rm -f Radon