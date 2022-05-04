# Hierarchical-FM-index-compacted-de-Bruijn
We implemented the hierarchical FM-index, the traditional FM-Index and SSHash over the compacted de Bruijn graph and compared each of them. We tested our data using different kmer lengths and different reference strings to build the de Bruign Graph.

Here is a visual representation of our technical approach:


![Screen Shot 2022-05-04 at 2 55 09 PM](https://user-images.githubusercontent.com/43825734/166806155-3dc58aee-8e80-41dc-a1b2-aaaebc6998c9.png)

We first passed the reference string into cuttlefish, took the unitig outputs from cuttlefish,  and passed them into concate_cdbg_output.py to concatenate them together. Then, we passed the concatenated string into FM-Index, HISAT-2 to build the FM-Index or hierarchical index. Then we ran the queries. For FM-Index, we first ran the queries in fmcount, and if the query count was 0 we removed it from the query list using [remove_0_count.py](https://github.com/PJeBeK/hierarchical-FM-index-compacted-de-Bruijn/blob/main/remove_0_count.py). 

# Libraries used:
Cuttlefish:
https://bioconda.github.io/recipes/cuttlefish/README.html
https://github.com/COMBINE-lab/cuttlefish#usage
 
FM-Index:
https://github.com/mpetri/FM-Index
 
Hierarchical FM-Index: 
https://github.com/DaehwanKimLab/hisat2
 
SSHash: 
https://github.com/jermp/sshash
