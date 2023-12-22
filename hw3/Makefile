
compile: tree1 tree2 htable1

CFLAGS = -Wall -g -std=c99

tree.o: hw3/tree.c hw3/tree.h
	gcc $(CFLAGS) hw3/tree.c -c -o hw3/tree.o

htable.o: hw3/htable.c hw3/htable.h
	gcc $(CFLAGS) hw3/htable.c -c
	
hbtree.o: hw3/hbtree.c hw3/hbtree.h
	gcc $(CFLAGS) hw3/hbtree.c -c
	
tree1:  hw3/hbtree.o hw3/tree1.c hw3/hbtree.h
	gcc $(CFLAGS) hw3/tree1.c hw3/hbtree.o -o hw3/tree1 -lm
	
tree2:  hw3/tree.o hw3/tree2.c
	gcc $(CFLAGS) hw3/tree2.c hw3/tree.o -o hw3/tree2 -lm
	
htable1: hw3/htable.o hw3/htable1.c
	gcc $(CFLAGS) hw3/htable1.c hw3/htable.o -o hw3/htable1

run: run_tree1 run_tree2 run_htable1

run_tree1:
	./hw3/tree1 < tests/tests/tree1_a.in > tests/tests/tree1_a.out
	diff -urN tests/tests/tree1_a.std tests/tests/tree1_a.out
	./hw3/tree1 < tests/tests/tree1_b.in > tests/tests/tree1_b.out
	diff -urN tests/tests/tree1_b.std tests/tests/tree1_b.out
	./hw3/tree1 < tests/tests/tree1_c.in > tests/tests/tree1_c.out
	diff -urN tests/tests/tree1_c.std tests/tests/tree1_c.out
	./hw3/tree1 < tests/tests/tree1_d.in > tests/tests/tree1_d.out
	diff -urN tests/tests/tree1_d.std tests/tests/tree1_d.out
	./hw3/tree1 < tests/tests/tree1_e.in > tests/tests/tree1_e.out
	diff -urN tests/tests/tree1_e.std tests/tests/tree1_e.out

run_tree2:
	./hw3/tree2 < tests/tests/tree2_a.in > tests/tests/tree2_a.out
	python3 check_tree2.py tests/tests/tree2_a.in tests/tests/tree2_a.std tests/tests/tree2_a.out
	./hw3/tree2 < tests/tests/tree2_b.in > tests/tests/tree2_b.out
	python3 check_tree2.py tests/tests/tree2_b.in tests/tests/tree2_b.std tests/tests/tree2_b.out
	./hw3/tree2 < tests/tests/tree2_c.in > tests/tests/tree2_c.out
	python3 check_tree2.py tests/tests/tree2_c.in tests/tests/tree2_c.std tests/tests/tree2_c.out
	./hw3/tree2 < tests/tests/tree2_d.in > tests/tests/tree2_d.out
	python3 check_tree2.py tests/tests/tree2_d.in tests/tests/tree2_d.std tests/tests/tree2_d.out
	./hw3/tree2 < tests/tests/tree2_e.in > tests/tests/tree2_e.out
	python3 check_tree2.py tests/tests/tree2_e.in tests/tests/tree2_e.std tests/tests/tree2_e.out

run_htable1:
	./hw3/htable1 < tests/tests/htable1_a.in > tests/tests/htable1_a.out
	diff -urN tests/tests/htable1_a.std tests/tests/htable1_a.out
	./hw3/htable1 < tests/tests/htable1_b.in > tests/tests/htable1_b.out
	diff -urN tests/tests/htable1_b.std tests/tests/htable1_b.out
	./hw3/htable1 < tests/tests/htable1_c.in > tests/tests/htable1_c.out
	diff -urN tests/tests/htable1_c.std tests/tests/htable1_c.out
	./hw3/htable1 < tests/tests/htable1_d.in > tests/tests/htable1_d.out
	diff -urN tests/tests/htable1_d.std tests/tests/htable1_d.out
	./hw3/htable1 < tests/tests/htable1_e.in > tests/tests/htable1_e.out
	diff -urN tests/tests/htable1_e.std tests/tests/htable1_e.out
	
clean:
	-rm *.o tree1 tree2 htable1
	-rm tests/*.out
	-rm -rf dot/
	-mkdir dot
	-mkdir dot/hbtree/
	-mkdir dot/tree2/

