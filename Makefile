

.PHONY : clean
clean:
	-rm *.o
	-cd test
	-rm *.o
	-cd ..
	-cd moudle
	-rm *.o
