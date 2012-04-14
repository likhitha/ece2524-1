SRC := main.cpp iodat.cpp
OBJ := ${SRC:.cpp=.o}
LIBS := -lboost_program_options
CC := g++
CFLAGS := -Wall -g -std=c++0x

main: ${OBJ}
	${CC} ${CFLAGS} -o $@ ${LIBS} ${OBJ}

#generate dependancy files at the same time as object compilation
%.o : %.cpp
	${CC} ${CXX_FLAGS} -MD -o $@ -c $< 
	@cp $*.d $*.P; \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	 	  -e '/^$$/ d' -e 's/$$/ :/' < $*.P >> $*.d; \
	  rm -f $*.P

clean:
	-rm *.o *.d *~

archive:
<<<<<<< HEAD
	tar -cvf archive.tar ${SRC}
<<<<<<< HEAD
=======
	tar czf project.tar.gz Makefile *.h *.cpp
>>>>>>> upstream/master
=======
	tar -cvzf archive.tar.gz *.cpp *.h Makefile README	

>>>>>>> 36feb1a706f8eb4073da2b6ca595889092f2704c

