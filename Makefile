launch:
	gcc shell.c -lreadline -o shell && ./shell

install:
	sudo apt-get install libreadline-dev

compile:
	gcc cat.c -o cat
	gcc date.c -o date
	gcc ls.c -o ls
	gcc mkdir.c -o mkdir
	gcc rm.c -o rm

clean: 
	rm -f shell
deep-clean:
	rm -f cat
	rm -f date
	rm -f ls
	rm -f mkdir
	rm -f rm
	make clean
	
