SOURCE_FILES := train.c queue.c stack.c utils.c
HEADERS := queue.h stack.h utils.h train.h

build: main.c ${SOURCE_FILES} ${HEADERS}
	gcc -o tema1 main.c ${SOURCE_FILES} ${HEADERS}
run: build
	./tema1
clean:
	rm -rf tema1 tema1.in tema1.out 
check:
	./checker.sh