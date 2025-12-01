.PHONY: all dll build_product product build_unit_test unit build_func_test funcional clean

all: build_product build_unit_test build_func_test

dll:
	@g++ -shared -fPIC -o ./bin/libbib.so ./src/*.cpp

build_product: dll
	@g++ ./src/*.cpp ./bin/libbib.so -o ./bin/product

product:
	./bin/product

build_unit_test: dll
	@g++ ./test/unit/*.cpp ./bin/libbib.so -I./src -o ./bin/unit_tests

unit:
	./bin/unit_tests

build_func_test: dll
	@g++ ./test/funcional/*.cpp ./bin/libbib.so -I./src -o ./bin/funcional_tests

funcional: 
	./bin/funcional_tests

clean:
	@rm -f ./bin/*.o
	@rm -f ./bin/*.so
	@rm -f ./bin/unit_tests
	@rm -f ./bin/funcional_tests
	@rm -f ./bin/product
