DLL:
	@g++ -shared -fPIC -o ./bin/bib.so ./src/*.cpp

BUILD_APP:
	g++ ./src/*.cpp -L./bin -lbib -o ./bin/app

APP:
	./bin/app

BUILD_UNIT_TEST:
	g++ ./test/unitario/*.cpp -L./bin -lbib -o ./bin/unit_teste

TEST:
	./bin/test

BUILD_FUNC_TEST:
	g++ ./test/funcional/*.cpp -L./bin -lbib -o ./bin/func_teste

RUN_FUNC_TEST:
	./bin/func_teste

CLEAN:
	rm -f ./bin/*.o
	rm -f ./bin/*.so
	rm -f ./bin/*_teste
	rm -f ./bin/app