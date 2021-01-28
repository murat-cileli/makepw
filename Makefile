all: makepw.c 
	gcc -g -Wall -o makepw makepw.c

install: makepw
	cp $< /usr/local/bin/makepw

uninstall:
	rm /usr/local/bin/makepw

clean: 
	$(RM) makepw