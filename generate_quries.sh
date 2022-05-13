#!/bin/bash
GENOME_REF=$1

python generate_queries.py < out/$GENOME_REF/compacted.fa > out/$GENOME_REF/queries

./FM-Index/fmbuild out/$GENOME_REF/concatenated out/$GENOME_REF/index.fm
./FM-Index/fmcount -i out/$GENOME_REF/index.fm out/$GENOME_REF/queries > out/$GENOME_REF/queries-count
python3 src/remove_0_count.py < out/$GENOME_REF/queries-count > out/$GENOME_REF/filtered-queries
