# Linux
Linux_operation and Linux_project 
git add XXX
git commit -m"XXXXXXX"
git remote add origin https://github.com/1599387893/Linux.git
git push -u origin master

#Makefile's rules:

src=$(wildcard ./*.c)  #--Get all name like '.c' file-name in src ,on this catalogs
main:$(src)
	gcc %^ -o $@
	gcc -o $@ $^

obj=$(patsubst %.c , %.o , $(src))  #--replace all name like '.c' file to '.o' , on the src 
main:$(obj)
	gcc $^ -o $@
%.o:%.c
	gcc -c $^ -o $@

