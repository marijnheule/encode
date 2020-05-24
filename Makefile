all: ErdosDiscrepancy PythagoreanTriples Ramsey Schur

ErdosDiscrepancy: ErdosDiscrepancy.c
	gcc ErdosDiscrepancy.c -O2 -o ErdosDiscrepancy

PythagoreanTriples: PythagoreanTriples.c
	gcc PythagoreanTriples.c -O2 -o PythagoreanTriples

Ramsey: Ramsey.c
	gcc Ramsey.c -O2 -o Ramsey

Schur: Schur.c
	gcc Schur.c -O2 -o Schur

clean:
	rm ErdosDiscrepancy PythagoreanTriples Ramsey Schur
