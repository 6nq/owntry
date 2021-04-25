install:
	-g++ -std=c++20 -o MAIN page/main.cpp

.PHONY : clean
clean:
	-rm *.o
	-cd test
	-rm *.o
	-cd ..
	-cd moudle
	-rm *.o
