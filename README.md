Description of repo layout (how is your repo organized, what lives in each folder?).
How was your testing done, which scripts (or notebooks etc.) are responsible for your testing?
What is the provenance of the data you used for testing — either pointers to scripts to download this data or detailed lists of the exact files you used and where they came from.
Versions of the relevant software that you used in your project.


# Hierarchical-FM-index-compacted-de-Bruijn
We implemented the hierarchical FM-index, the traditional FM-Index and SSHash over the compacted de Bruijn graph and compared each of them. We tested our data using different kmer lengths and different reference strings to build the de Bruign Graph.

# Repo layout 
In the 


Here is a visual representation of our technical approach:


![Screen Shot 2022-05-04 at 2 55 09 PM](https://user-images.githubusercontent.com/43825734/166806155-3dc58aee-8e80-41dc-a1b2-aaaebc6998c9.png)

We first passed the reference string into cuttlefish, took the unitig outputs from cuttlefish,  and passed them into [concate_cdbg_output.py](https://github.com/PJeBeK/hierarchical-FM-index-compacted-de-Bruijn/blob/main/concate_cdbg_output.py) to concatenate them together. We passed the concatenated string into FM-Index, HISAT-2 to build the FM-Index or hierarchical index. Then we ran the queries. For FM-Index, we first ran the queries in fmcount, and if the query count was 0 we removed it from the query list using [remove_0_count.py](https://github.com/PJeBeK/hierarchical-FM-index-compacted-de-Bruijn/blob/main/remove_0_count.py) before running the parsed queries through fmlocate. 

# Requirements

For running all module in this project you need to have gcc and python3.\
Also, you need to download the cuttlefish, FM-Index, HISAT2 and SSHash projects from the [Libraries](#libraries-used) section and put them in root directory of this project.

# Run codes

There are six scripts in the root directory of this project which run all the modules. We will introduce them step by step.
In these steps, we assume that there is a file named `ecoli.fa` in directory `data/` which is Escherichia coli reference genome.
You can replace `ecoli` with every name that your reference genome has. Just remember that it should be in the `data/`
subdirectory and its format should be `.fa`.\
First, you should run cuttlefish to generate a compacted version of reference genome:
        
    ./run_cuttlefish.sh ecoli 31

Then, you generate queries and run fmcount of FM-Index to filter queries without occurrences in unitigs:

    ./generate_queries.sh ecoli

Finally, you can build HISAT2 and SSHash indexes and run filtered queries on all three algorithms:

    ./run_fm-index.sh ecoli
    ./run_hisat2.sh ecoli
    ./run_sshash.sh ecoli 31 13

Also, you can run all above commands in only one command:

    ./run_all.sh ecoli 31 13


# Data used
Human genome and chromosomes:\
https://www.ncbi.nlm.nih.gov/genome/?term=txid9606

# Libraries used
Cuttlefish:\
https://bioconda.github.io/recipes/cuttlefish/README.html
https://github.com/COMBINE-lab/cuttlefish#usage
 
FM-Index:\
https://github.com/mpetri/FM-Index
 
Hierarchical FM-Index:\
https://github.com/DaehwanKimLab/hisat2
 
SSHash:\
https://github.com/jermp/sshash
