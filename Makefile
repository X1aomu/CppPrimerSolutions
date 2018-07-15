DIRS = common 01 02 03 04 05 06 07 08 09 10 12

all:
	cd common && make
	cd 01 && make
	cd 02 && make
	cd 03 && make
	cd 04 && make
	cd 05 && make
	cd 06 && make
	cd 07 && make
	cd 08 && make
	cd 09 && make
	cd 10 && make
	cd 12 && make

clean:
	rm -f *\~ .*.un\~
	cd common && make clean
	cd 01 && make clean
	cd 02 && make clean
	cd 03 && make clean
	cd 04 && make clean
	cd 05 && make clean
	cd 06 && make clean
	cd 07 && make clean
	cd 08 && make clean
	cd 09 && make clean
	cd 10 && make clean
	cd 12 && make clean

clobber:
	cd common && make clobber
	cd 01 && make clobber
	cd 02 && make clobber
	cd 03 && make clobber
	cd 04 && make clobber
	cd 05 && make clobber
	cd 06 && make clobber
	cd 07 && make clobber
	cd 08 && make clobber
	cd 09 && make clobber
	cd 10 && make clobber
	cd 12 && make clobber

