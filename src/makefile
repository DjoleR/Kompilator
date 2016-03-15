program: parser.tab.o lex.yy.o izraz.o naredba.o funkcije.o
	g++ -Wall -o $@ $^
parser.tab.o: parser.tab.cpp
	g++ -Wall -c -o $@ $<
lex.yy.o: lex.yy.c parser.tab.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d $<
lex.yy.c: lexer.l
	flex $<
izraz.o: izraz.cpp izraz.hpp
	g++ -Wall -c -o $@ $<
naredba.o: naredba.cpp naredba.hpp
	g++ -Wall -c -o $@ $<
funkcije.o: funkcije.cpp funkcije.hpp
	g++ -Wall -c -o $@ $<

.PHONY: clean

clean:
	rm -f program *~ \#* *tab* *.o *.c
