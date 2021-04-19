Radon: App.cpp
	g++ Main.cpp App.cpp `wx-config --cxxflags --libs` -o Radon

.PHONY: test clean

test: Radon
	./Radon

clean:
	rm -f Radon
