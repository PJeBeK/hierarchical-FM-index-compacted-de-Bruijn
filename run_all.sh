#!/bin/bash
GENOME_REF=$1
K=$2 # 31
M=$3 # 13

echo "Running Cuttlefish"
./run_cuttlefish.sh $GENOME_REF $K
echo "Genrating queries and building FM-Index to filter quries"
./generate_quries.sh $GENOME_REF
echo "####################################################################"
echo "Running FM-Index"
./run_fm-index.sh $GENOME_REF
echo "####################################################################"
echo "Running HISAT2"
./run_hisat2.sh $GENOME_REF
echo "####################################################################"
echo "Running SShash"
./run_sshash.sh  $GENOME_REF $K $M
