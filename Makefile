DIRS = common 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19

all:
	cd common && make -j5
	-cd 01 && make -j5
	-cd 02 && make -j5
	-cd 03 && make -j5
	-cd 04 && make -j5
	-cd 05 && make -j5
	-cd 06 && make -j5
	-cd 07 && make -j5
	-cd 08 && make -j5
	-cd 09 && make -j5
	-cd 10 && make -j5
	-cd 11 && make -j5
	-cd 12 && make -j5
	-cd 13 && make -j5
	-cd 14 && make -j5
	-cd 15 && make -j5
	-cd 16 && make -j5
	-cd 17 && make -j5
	-cd 18 && make -j5
	-cd 19 && make -j5

clean:
	rm -f *\~ .*.un\~
	cd common && make -j5 clean
	-cd 01 && make -j5 clean
	-cd 02 && make -j5 clean
	-cd 03 && make -j5 clean
	-cd 04 && make -j5 clean
	-cd 05 && make -j5 clean
	-cd 06 && make -j5 clean
	-cd 07 && make -j5 clean
	-cd 08 && make -j5 clean
	-cd 09 && make -j5 clean
	-cd 10 && make -j5 clean
	-cd 11 && make -j5 clean
	-cd 12 && make -j5 clean
	-cd 13 && make -j5 clean
	-cd 14 && make -j5 clean
	-cd 15 && make -j5 clean
	-cd 16 && make -j5 clean
	-cd 17 && make -j5 clean
	-cd 18 && make -j5 clean
	-cd 19 && make -j5 clean

clobber:
	cd common && make -j5 clobber
	-cd 01 && make -j5 clobber
	-cd 02 && make -j5 clobber
	-cd 03 && make -j5 clobber
	-cd 04 && make -j5 clobber
	-cd 05 && make -j5 clobber
	-cd 06 && make -j5 clobber
	-cd 07 && make -j5 clobber
	-cd 08 && make -j5 clobber
	-cd 09 && make -j5 clobber
	-cd 10 && make -j5 clobber
	-cd 11 && make -j5 clobber
	-cd 12 && make -j5 clobber
	-cd 13 && make -j5 clobber
	-cd 14 && make -j5 clobber
	-cd 15 && make -j5 clobber
	-cd 16 && make -j5 clobber
	-cd 17 && make -j5 clobber
	-cd 18 && make -j5 clobber
	-cd 19 && make -j5 clobber

