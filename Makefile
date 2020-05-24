all: Ramsey Schur

Ramsey: Ramsey.c
	gcc Ramsey.c -O2 -o Ramsey

Schur: Schur.c
	gcc Schur.c -O2 -o Schur

clean:
	rm Ramsey Schur
