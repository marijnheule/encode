all: ErdosDiscrepancy PythagoreanTriples Ramsey Schur grid-color php atmostone maxclique Green

ErdosDiscrepancy: ErdosDiscrepancy.c
	gcc ErdosDiscrepancy.c -O2 -o ErdosDiscrepancy

PythagoreanTriples: PythagoreanTriples.c
	gcc PythagoreanTriples.c -lm -O2 -o PythagoreanTriples

Ramsey: Ramsey.c
	gcc Ramsey.c -O2 -o Ramsey

Schur: Schur.c
	gcc Schur.c -O2 -o Schur

grid-color: grid-color.c
	gcc grid-color.c -O2 -o grid-color

php: php.c
	gcc php.c -O2 -o php

atmostone: atmostone.c
	gcc atmostone.c -O2 -o atmostone

maxclique: maxclique.c
	gcc maxclique.c -O2 -o maxclique

Green: Green.c
	gcc Green.c -O2 -o Green

clean:
	rm ErdosDiscrepancy PythagoreanTriples Ramsey Schur grid-color php atmostone maxclique Green
