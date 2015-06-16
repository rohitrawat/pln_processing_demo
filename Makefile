all: hello-c-world

%: %.c
	gcc -g $< -o $@

