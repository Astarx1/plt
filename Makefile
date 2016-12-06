

HEADERS:=$(shell find src -type f -name '*.h')
DIA2CODE_DIR:=./dia2code

all: | clean dia2code configure build server

clean:
	@rm -rf bin build ${HEADERS}
	@rm -f $(shell grep -ls '// Generated by dia2code' main.h ${HEADERS})

distclean: clean
	@rm -rf ${DIA2CODE_DIR}/bin ${DIA2CODE_DIR}/build

dia2code: ${DIA2CODE_DIR}/bin/dia2code

${DIA2CODE_DIR}/bin/dia2code: 
	cd ${DIA2CODE_DIR} && ./build.sh

configure:
	@mkdir -p build 
	@cd build && cmake ..

fast:
	build

build:
	@make -s -j4 -C build

server:
	@make -s -j4 -C build server

run: build
	./bin/run

test:
	docker build -t plt-initial -f docker/plt-initial .
	docker build -t plt-build -f docker/plt-build .
	./docker/run_docker_x11.sh plt-build

start-kit: distclean
	@tar -czvf ../plt-start-kit.tar.gz CMakeLists.txt Makefile .gitignore dia2code src docker rapport res

.PHONY: configure build clean run test start-kit
