OPTIONS=-O2

all : tp3 testdh

tp3 : tp3.cpp agenda.o coordonnees.o dateheure.o
	g++ ${OPTIONS} -o tp3 tp3.cpp agenda.o coordonnees.o dateheure.o
	
coordonnees.o : coordonnees.cpp coordonnees.h
	g++ ${OPTIONS} -c -o coordonnees.o coordonnees.cpp

dateheure.o : dateheure.cpp dateheure.h
	g++ ${OPTIONS} -c -o dateheure.o dateheure.cpp

agenda.o : agenda.cpp agenda.h coordonnees.h dateheure.h arbreavl.h
	g++ ${OPTIONS} -c -o agenda.o agenda.cpp

testdh : testdh.cpp dateheure.o
	g++ $(OPTIONS) -o testdh testdh.cpp dateheure.o

clean:
	rm -rf tp3 testdh *~ *.o *.gch

