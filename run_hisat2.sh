#!/bin/bash
GENOME_REF=$1

mkdir out/$GENOME_REF/hisat2

python3 src/make_file_fasta.py < out/$GENOME_REF/concatenated > out/$GENOME_REF/concatenated.fa
python3 hisat2-2.2.1/hisat2-build out/$GENOME_REF/concatenated.fa out/$GENOME_REF/hisat2/index

python3 src/make_file_fasta.py < out/$GENOME_REF/filtered-queries > out/$GENOME_REF/filtered-queries.fa
perl hisat2-2.2.1/hisat2 -f -x out/$GENOME_REF/hisat2/index -U out/$GENOME_REF/filtered-queries.fa -S out/$GENOME_REF/hisat2.out --no-spliced-alignment -t

./out/rank-select-hisat2-binary out/$GENOME_REF/bit_vector out/$GENOME_REF/hisat2.out > out/$GENOME_REF/hisat2-final.out
