#!/bin/bash
GENOME_REF=$1
K=$2 # 31
M=$3 # 13

./sshash/build/build out/$GENOME_REF/compacted.fa $K $M --check --bench -o out/$GENOME_REF/sshash.index
./sshash/build/query out/$GENOME_REF/sshash.index out/$GENOME_REF/filtered-queries.fa --multiline