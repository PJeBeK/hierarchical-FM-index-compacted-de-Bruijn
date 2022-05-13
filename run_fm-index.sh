#!/bin/bash
GENOME_REF=$1

./FM-Index/fmlocate -i out/$GENOME_REF/index.fm out/$GENOME_REF/filtered-queries -v > out/$GENOME_REF/fm-index.out

./out/rank-select-fm-index-binary out/$GENOME_REF/bit_vector out/$GENOME_REF/fm-index.out > out/$GENOME_REF/fm-index-final.out
