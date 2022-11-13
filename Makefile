all:
	gcc rhelf.c -o rhelf -L./lib -lverify

clean:
	rm rhelf
