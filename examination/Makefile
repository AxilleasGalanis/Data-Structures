
build:
	gcc -Wall -g exam/exam.c exam/tree.c -o exam/exam
	
run: f_test h_test a_test 

f_test:
	./exam/exam < tests/f1.in > tests/f1.out
	diff -urN tests/f1.std tests/f1.out
	./exam/exam < tests/f2.in > tests/f2.out
	diff -urN tests/f2.std tests/f2.out
	./exam/exam < tests/f3.in > tests/f3.out
	diff -urN tests/f3.std tests/f3.out

h_test:
	./exam/exam < tests/h1.in > tests/h1.out
	diff -urN tests/h1.std tests/h1.out
	./exam/exam < tests/h2.in > tests/h2.out
	diff -urN tests/h2.std tests/h2.out
	./exam/exam < tests/h3.in > tests/h3.out
	diff -urN tests/h3.std tests/h3.out
	./exam/exam < tests/h4.in > tests/h4.out
	diff -urN tests/h4.std tests/h4.out
	./exam/exam < tests/h5.in > tests/h5.out
	diff -urN tests/h5.std tests/h5.out
	./exam/exam < tests/h6.in > tests/h6.out
	diff -urN tests/h6.std tests/h6.out

a_test:
	./exam/exam < tests/a1.in > tests/a1.out
	diff -urN tests/a1.std tests/a1.out
	./exam/exam < tests/a2.in > tests/a2.out
	diff -urN tests/a2.std tests/a2.out
	./exam/exam < tests/a3.in > tests/a3.out
	diff -urN tests/a3.std tests/a3.out
	./exam/exam < tests/a4.in > tests/a4.out
	diff -urN tests/a4.std tests/a4.out
	./exam/exam < tests/a5.in > tests/a5.out
	diff -urN tests/a5.std tests/a5.out
	./exam/exam < tests/a6.in > tests/a6.out
	diff -urN tests/a6.std tests/a6.out

clean: 
	-rm exam/exam tests/*.out
