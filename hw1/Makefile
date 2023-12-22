
compile: list1 tree1 tree2 tree3

CFLAGS = -Wall -g -std=c99

list1: hw1/list1.c hw1/dlist.o
	gcc $(CFLAGS) hw1/list1.c hw1/dlist.o -o hw1/list1

tree1: hw1/stack.o hw1/tree.o hw1/tree1.c hw1/fifo.o
	gcc $(CFLAGS) hw1/tree1.c hw1/dlist.o hw1/tree.o hw1/stack.o hw1/fifo.o -o hw1/tree1

tree2: hw1/stack.o hw1/tree.o hw1/tree2.c hw1/fifo.o
	gcc $(CFLAGS) hw1/tree2.c hw1/dlist.o hw1/tree.o hw1/stack.o hw1/fifo.o -o hw1/tree2

tree3: hw1/stack.o hw1/tree.o hw1/tree3.c hw1/fifo.o
	gcc $(CFLAGS) hw1/tree3.c hw1/dlist.o hw1/tree.o hw1/stack.o hw1/fifo.o -o hw1/tree3

tree.o: tree.c tree.h
	gcc $(CFLAGS) tree.c -c -o tree.o

dlist.o: dlist.c dlist.h
	gcc $(CFLAGS) dlist.c -c -o dlist.o

stack.o: dlist.o stack.c stack.h 
	gcc $(CFLAGS) stack.c -c -o stack.o
	
fifo.o: dlist.o fifo.c fifo.h 
	gcc $(CFLAGS) fifo.c -c -o fifo.o

clean:
	rm *.o tree1 tree2 tree3 tree4 tree5
	
run: l1 t1 t2 t3

l1: l1_a l1_b l1_c l1_d l1_e

t1: t1_a t1_b t1_c t1_d 

t2: t2_a t2_b t2_c t2_d t2_e

t3: t3_a t3_b t3_c

l1_a:
	./hw1/list1 < tests/list1_a.in > tests/list1.out
	diff -urN tests/list1_a.std tests/list1.out

l1_b:
	./hw1/list1 < tests/list1_b.in > tests/list1.out
	diff -urN tests/list1_b.std tests/list1.out

l1_c:
	./hw1/list1 < tests/list1_c.in > tests/list1.out
	diff -urN tests/list1_c.std tests/list1.out

l1_d:
	./hw1/list1 < tests/list1_d.in > tests/list1.out
	diff -urN tests/list1_d.std tests/list1.out

l1_e:
	./hw1/list1 < tests/list1_e.in > tests/list1.out
	diff -urN tests/list1_e.std tests/list1.out
	
t1_a:
	./hw1/tree1 < tests/post_order_14.in > tests/t1.out
	diff -urN tests/level_order_14.std tests/t1.out
	
t1_b:
	./hw1/tree1 < tests/post_order_35.in > tests/t1.out
	diff -urN tests/level_order_35.std tests/t1.out
	
t1_c:
	./hw1/tree1 < tests/post_order_147.in > tests/t1.out
	diff -urN tests/level_order_147.std tests/t1.out

t1_d:
	./hw1/tree1 < tests/post_order_500.in > tests/t1.out
	diff -urN tests/level_order_500.std tests/t1.out
	
t2_a:
	./hw1/tree2 < tests/level_order_complete_27_bst.in > tests/t2.out
	diff -urN tests/bst.txt tests/t2.out
	
t2_b:
	./hw1/tree2 < tests/level_order_complete_27_bt.in > tests/t2.out
	diff -urN tests/bt.txt tests/t2.out
	
t2_c:
	./hw1/tree2 < tests/level_order_complete_255_bst.in > tests/t2.out
	diff -urN tests/bst.txt tests/t2.out

t2_d:
	./hw1/tree2 < tests/level_order_complete_255_bt1.in > tests/t2.out
	diff -urN tests/bt.txt tests/t2.out

t2_e:
	./hw1/tree2 < tests/level_order_complete_255_bt2.in > tests/t2.out
	diff -urN tests/bt.txt tests/t2.out

t3_a:
	./hw1/tree3 < tests/tree3_a.in > tests/t3.out
	diff -urN tests/tree3_a.std tests/t3.out
	
t3_b:
	./hw1/tree3 < tests/tree3_b.in > tests/t3.out
	diff -urN tests/tree3_b.std tests/t3.out

t3_c:
	./hw1/tree3 < tests/tree3_c.in > tests/t3.out
	diff -urN tests/tree3_c.std tests/t3.out
	
	
