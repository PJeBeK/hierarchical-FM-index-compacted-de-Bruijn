#!/bin/bash
GENOME_REF=$1
K=$2 # 31

mkdir out/$GENOME_REF
cuttlefish build -s data/$GENOME_REF.fa -k $K -t 4 -o out/$GENOME_REF/compacted -f 0
python3 src/concate_cdbg_output.py < out/$GENOME_REF/compacted.fa > out/$GENOME_REF/concatenated