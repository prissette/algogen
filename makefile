test_individu : test_individu.cpp individu.h individu.o
	g++ -o test_individu test_individu.cpp individu.o

individu.o : individu.h individu.cpp
	g++ -c individu.cpp



