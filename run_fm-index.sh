#!/bin/bash
GENOME_REF=$1

./FM-Index/fmlocate -i out/$GENOME_REF/index.fm out/$GENOME_REF/filtered-queries -v > fm-index.out
