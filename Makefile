all:
	for script in *.vs; do \
		cp $$script $${script%.*}.dat; \
		dd if=/dev/zero bs=1 count=1 >> $${script%.*}.dat; \ # make our vs strings null terminated
		objcopy --input binary -O elf64-x86-64 -B i386:x86-64 $${script%.*}.dat $${script%.*}.o; \
	done
	clang++ -c -std=c++1z *.cpp
	clang++ -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -o program *.o

clean:
	rm *.o *.dat program
