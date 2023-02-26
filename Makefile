

makeall:
	cd Liten;\
		make
	cd test;\
		make;\
		./bin/test

cleanall:
	cd Liten;\
		make clean
	cd test;\
		make clean
