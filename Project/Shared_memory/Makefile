.PHONY:all
all:	p1 p2

p1:port1.c
	gcc -o $@ $^ -std=c++11
	
p2:port2.c
	gcc -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f p1 p2
