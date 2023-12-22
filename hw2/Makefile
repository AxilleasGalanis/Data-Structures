
compile: sort1 tree1 tree2

CFLAGS = -Wall -g -std=c99

all: sort1

tree.o: hw2/tree.c hw2/tree.h
	gcc $(CFLAGS) hw2/tree.c -c -o hw2/tree.o
	
sort.o: hw2/sort.c hw2/sort.h
	gcc $(CFLAGS) hw2/sort.c -c
	
dlist.o: hw2/dlist.c hw2/dlist.h
	gcc $(CFLAGS) hw2/dlist.c -c
	
sort1: hw2/sort.o hw2/dlist.o hw2/sort1.c
	gcc $(CFLAGS) hw2/sort1.c hw2/sort.o hw2/dlist.o -o hw2/sort1 -lm
	
tree1:  hw2/dlist.o hw2/tree.o hw2/tree1.c 
	gcc $(CFLAGS) hw2/tree1.c hw2/dlist.o hw2/tree.o -o hw2/tree1
	
tree2:  hw2/dlist.o hw2/tree.o hw2/tree2.c
	gcc $(CFLAGS) hw2/tree2.c hw2/dlist.o hw2/tree.o -o hw2/tree2

run: run_sort run_tree1 run_tree2

run_sort: ins_sort sel_sort quick_sort merge_sort radix_msd radix_lsd

ins_sort:
	./hw2/sort1 1 < tests/cmp_10r.in > tests/ins_10r.out
	-diff -urN tests/ins_10r.std tests/ins_10r.out
	./hw2/sort1 1 < tests/cmp_35r.in > tests/ins_35r.out
	-diff -urN tests/ins_35r.std tests/ins_35r.out
	./hw2/sort1 1 < tests/cmp_50r.in > tests/ins_50r.out
	-diff -urN tests/ins_50r.std tests/ins_50r.out
	./hw2/sort1 1 < tests/cmp_100r.in > tests/ins_100r.out
	-diff -urN tests/ins_100r.std tests/ins_100r.out
	
sel_sort:
	./hw2/sort1 2 < tests/cmp_10r.in > tests/sel_10r.out
	-diff -urN tests/sel_10r.std tests/sel_10r.out
	./hw2/sort1 2 < tests/cmp_35r.in > tests/sel_35r.out
	-diff -urN tests/sel_35r.std tests/sel_35r.out
	./hw2/sort1 2 < tests/cmp_50r.in > tests/sel_50r.out
	-diff -urN tests/sel_50r.std tests/sel_50r.out
	./hw2/sort1 2 < tests/cmp_100r.in > tests/sel_100r.out
	-diff -urN tests/sel_100r.std tests/sel_100r.out

quick_sort:
	./hw2/sort1 3 < tests/cmp_10r.in > tests/quick_10r.out
	-diff -urN tests/quick_10r.std tests/quick_10r.out
	./hw2/sort1 3 < tests/cmp_35r.in > tests/quick_35r.out
	-diff -urN tests/quick_35r.std tests/quick_35r.out
	./hw2/sort1 3 < tests/cmp_50r.in > tests/quick_50r.out
	-diff -urN tests/quick_50r.std tests/quick_50r.out
	./hw2/sort1 3 < tests/cmp_100r.in > tests/quick_100r.out
	-diff -urN tests/quick_100r.std tests/quick_100r.out
	
merge_sort:
	./hw2/sort1 4 < tests/cmp_10r.in > tests/merge_10r.out
	-diff -urN tests/merge_10r.std tests/merge_10r.out
	./hw2/sort1 4 < tests/cmp_35r.in > tests/merge_35r.out
	-diff -urN tests/merge_35r.std tests/merge_35r.out
	./hw2/sort1 4 < tests/cmp_50r.in > tests/merge_50r.out
	-diff -urN tests/merge_50r.std tests/merge_50r.out
	./hw2/sort1 4 < tests/cmp_100r.in > tests/merge_100r.out
	-diff -urN tests/merge_100r.std tests/merge_100r.out
	
radix_msd:
	./hw2/sort1 5 2 < tests/radix_10.in > tests/msd_2_10.out
	-diff -urN tests/msd_2_10.std tests/msd_2_10.out
	./hw2/sort1 5 2 < tests/radix_35.in > tests/msd_2_35.out
	-diff -urN tests/msd_2_35.std tests/msd_2_35.out
	./hw2/sort1 5 2 < tests/radix_50.in > tests/msd_2_50.out
	-diff -urN tests/msd_2_50.std tests/msd_2_50.out
	./hw2/sort1 5 2 < tests/radix_100.in > tests/msd_2_100.out
	-diff -urN tests/msd_2_100.std tests/msd_2_100.out
	./hw2/sort1 5 4 < tests/radix_10.in > tests/msd_4_10.out
	-diff -urN tests/msd_4_10.std tests/msd_4_10.out
	./hw2/sort1 5 4 < tests/radix_35.in > tests/msd_4_35.out
	-diff -urN tests/msd_4_35.std tests/msd_4_35.out
	./hw2/sort1 5 4 < tests/radix_50.in > tests/msd_4_50.out
	-diff -urN tests/msd_4_50.std tests/msd_4_50.out
	./hw2/sort1 5 4 < tests/radix_100.in > tests/msd_4_100.out
	-diff -urN tests/msd_4_100.std tests/msd_4_100.out
	./hw2/sort1 5 8 < tests/radix_100.in > tests/msd_8_100.out
	-diff -urN tests/msd_8_100.std tests/msd_8_100.out
	
radix_lsd:
	./hw2/sort1 6 2 < tests/radix_10.in > tests/lsd_2_10.out
	-diff -urN tests/lsd_2_10.std tests/lsd_2_10.out
	./hw2/sort1 6 2 < tests/radix_35.in > tests/lsd_2_35.out
	-diff -urN tests/lsd_2_35.std tests/lsd_2_35.out
	./hw2/sort1 6 2 < tests/radix_50.in > tests/lsd_2_50.out
	-diff -urN tests/lsd_2_50.std tests/lsd_2_50.out
	./hw2/sort1 6 2 < tests/radix_100.in > tests/lsd_2_100.out
	-diff -urN tests/lsd_2_100.std tests/lsd_2_100.out
	./hw2/sort1 6 4 < tests/radix_10.in > tests/lsd_4_10.out
	-diff -urN tests/lsd_4_10.std tests/lsd_4_10.out
	./hw2/sort1 6 4 < tests/radix_35.in > tests/lsd_4_35.out
	-diff -urN tests/lsd_4_35.std tests/lsd_4_35.out
	./hw2/sort1 6 4 < tests/radix_50.in > tests/lsd_4_50.out
	-diff -urN tests/lsd_4_50.std tests/lsd_4_50.out
	./vsort1 6 4 < tests/radix_100.in > tests/lsd_4_100.out
	-diff -urN tests/lsd_4_100.std tests/lsd_4_100.out
	./hw2/sort1 6 8 < tests/radix_100.in > tests/lsd_8_100.out
	-diff -urN tests/lsd_8_100.std tests/lsd_8_100.out

run_tree1:
	./hw2/tree1 < tests/tree1_a.in > tests/tree1_a.out
	-diff -urN tests/tree1_a.std tests/tree1_a.out
	./hw2/tree1 < tests/tree1_b.in > tests/tree1_b.out
	-diff -urN tests/tree1_b.std tests/tree1_b.out
	./hw2/tree1 < tests/tree1_c.in > tests/tree1_c.out
	-diff -urN tests/tree1_c.std tests/tree1_c.out
	
run_tree2:
	./hw2/tree2 < tests/tree2_a.in > tests/tree2_a.out
	python3 tree2_check.py tests/tree2_a.out
	./hw2/tree2 < tests/tree2_b.in > tests/tree2_b.out
	python3 tree2_check.py tests/tree2_b.out
	./hw2/tree2 < tests/tree2_c.in > tests/tree2_c.out
	python3 tree2_check.py tests/tree2_c.out
	./hw2/tree2 < tests/tree2_d.in > tests/tree2_d.out
	python3 tree2_check.py tests/tree2_d.out
	./hw2/tree2 < tests/tree2_e.in > tests/tree2_e.out
	python3 tree2_check.py tests/tree2_e.out
	

clean:
	-rm *.o sort1 tree1 tree2 tests/*.out
