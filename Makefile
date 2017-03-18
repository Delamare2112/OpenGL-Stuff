all:
	for script in *.vs; do \
		cd Engine; \
		cp $$script $${script%.*}.dat; \
		dd if=/dev/zero bs=1 count=1 >> $${script%.*}.dat; \
		objcopy --input binary -O elf64-x86-64 -B i386:x86-64 $${script%.*}.dat $${script%.*}.o; \
		rm $${script%.*}.dat; \
		cd ..; \
	done
	clang++ -c -std=c++1z ./Engine/*.cpp *.cpp
	clang++ -lGLEW -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -o program *.o

clean:
	rm *.o *.dat program
