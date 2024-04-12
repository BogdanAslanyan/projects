CC=g++
CFLAGS=-g -Wall -Werror -Wextra -std=c++17
BUILDDIR=build
SRCEXT=cpp
SOURCES=$(wildcard Model/*.$(SRCEXT))
OBJECTS=$(patsubst Model/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TEST_FLAGS=-lgtest -lgmock -pthread
GCOV= --coverage
INFO= coverage.info
LIB=s21_calc_oop.a
TEX_FILE=calc_doc
LATEX_COMPILER=latex
LATEX_FLAGS=-interaction=nonstopmode
VALGRIND_COMMAND=valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./test
		 
ifeq ($(shell uname -s), Linux)
PKG_CONFIG= $(shell pkg-config --libs check) -lcheck -lpthread -lrt -lm -lsubunit
else
PKG_CONFIG= $(shell pkg-config --libs --cflags check)
endif

all: clean $(LIB)

valgrind: create_tests
	$(VALGRIND_COMMAND)

create_tests: $(LIB)
	@$(CC) $(CFLAGS) tests/*.cpp $(LIB) -o test $(TEST_FLAGS)

tests: create_tests
	@./test

gcov_report: clean
	$(CC) $(CFLAGS) $(GCOV) tests/*.cpp Model/*.cpp -o gcov_report $(TEST_FLAGS) $(PKG_CONFIG)
	./gcov_report
	lcov -t "gcov_report" -o $(INFO) -c -d . --no-external #--ignore-errors inconsistent
	genhtml -o coverage $(INFO) #--ignore-errors inconsistent
	open coverage/index.html

debug: $(LIB) $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB) -o debug
	@./debug

coverage: tests
	@gcovr -r . --html --html-details -o coverage_report.html
	@open coverage_report.html

$(LIB): $(OBJECTS)
	@ar rc $(LIB) $(OBJECTS)
	@ranlib $(LIB)

$(BUILDDIR)/%.o: Model/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@$(CC) -c $(CFLAGS) $< -lstdc++ -o $@ 


build: clean $(LIB)
	@mkdir build-SmartCalc-Desktop
	@cd ./build-SmartCalc-Desktop/ && qmake ../View/ && make

install: build uninstall
	@mkdir -p ./output
	@cp -rf  build-SmartCalc-Desktop/ ./output
	make clean

uninstall: 
	rm -rf ./output

dist:
	@mkdir -p ./output
	mkdir -p SmartCalc_v2.0/src
	cp -rf Makefile \
	Model/ \
	Controller/ \
	View/ SmartCalc_v2.0/src/
	tar cvzf SmartCalc_v2.0.tgz SmartCalc_v2.0/
	mv SmartCalc_v2.0.tgz ./output
	rm -rf SmartCalc_v2.0/

dvi: $(TEX_FILE).dvi
	
$(TEX_FILE).dvi: $(TEX_FILE).tex
	$(LATEX_COMPILER) $(LATEX_FLAGS) $(TEX_FILE).tex

calc.dvi: calc.texi
	$(TEXI2DVI) ./calc.texi

clean:
	@rm -rf $(OBJECTS) \
	$(LIB) \
	debug \
	test \
	$(BUILDDIR) \
	*.gc* \
	*.html \
	*.css \
	*.a \
	gcov_report \
	report *test coverage *.o *.gcda *.gcno *.info *.dSYM *.txt \
	*.gz *.aux *.log *.dvi *.toc *.out *.pdf \
	build*

rebuild: clean all

.PHONY: all tests clean debug build install uninstall

