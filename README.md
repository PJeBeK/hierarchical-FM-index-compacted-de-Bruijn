
# Hierarchical-FM-index-compacted-de-Bruijn
We implemented the hierarchical FM-index, the traditional FM-Index and SSHash over the compacted de Bruijn graph and compared each of them. We tested our data using different kmer lengths and different reference strings to build the de Bruijn Graph.

# Repo layout 
In the src directory, there is the helper code we wrote that takes the output from each library we used, transforms it if necessary, and passes it into the next library. These files are described in more detail in the [Technical Approach](#technical-approach) section. In the root directory there are scripts which can be used to run the project, described in more detail in the [Run the code](#run-the-code) section. The ecoli reference genome that we used for one of our reference strings is in the data folder, and the rest of the data that we used as our reference strings is linked in the [Data used](#data-used) section.

# Technical Approach
Here is a visual representation of our technical approach:


![Screen Shot 2022-05-04 at 2 55 09 PM](https://user-images.githubusercontent.com/43825734/166806155-3dc58aee-8e80-41dc-a1b2-aaaebc6998c9.png)

We first passed the reference string into cuttlefish, took the unitig outputs from cuttlefish,  and passed them into [concate_cdbg_output.py](https://github.com/PJeBeK/hierarchical-FM-index-compacted-de-Bruijn/blob/main/concate_cdbg_output.py) to concatenate them together. We passed the concatenated string into FM-Index to build the index. The hierarchical FM_index takes in a FASTA file to build the index, so we turned the concatenated string into one with [make_file_fasta.py](https://github.com/PJeBeK/hierarchical-FM-index-compacted-de-Bruijn/blob/main/src/make_file_fasta.py) and then built the index.   For SSHash we also passed in the FASTA file format of the concatenated string. To generate a list of queries we ran [generate_queries.py](https://github.com/PJeBeK/hierarchical-FM-index-compacted-de-Bruijn/blob/main/src/generate_queries.py) on the concatenated string. For FM-Index, we first ran the queries in fmcount, and if the query count was 0 we removed it from the query list using [remove_0_count.py](https://github.com/PJeBeK/hierarchical-FM-index-compacted-de-Bruijn/blob/main/remove_0_count.py) before running the parsed queries through fmlocate. For HISAT2 and SSHash there was only one query function that we ran. After getting the output from the FM-Index and HISAT2 we used rank and select code in file [FILEHERE] to get the unitig id and relative position of each query.

# Requirements

For running all module in this project you need to have gcc and python3.\
Also, you need to download the cuttlefish, FM-Index, HISAT2 and SSHash projects from the [Libraries](#libraries-used) section and put them in root directory of this project.

# Run the code

There are six scripts in the root directory of this project which run all the modules. We will introduce them step by step.
In these steps, we assume that there is a file named `ecoli.fa` in directory `data/` which is the Escherichia coli reference genome.
You can replace `ecoli` with every name that your reference genome has. Just remember that it should be in the `data/`
subdirectory and its format should be `.fa`.\
First, you should compile our c++ codes:

    make

Now, you should run cuttlefish to generate a compacted version of reference genome using the following command:
        
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
https://bioconda.github.io/recipes/cuttlefish/README.html \
https://github.com/COMBINE-lab/cuttlefish#usage
 
FM-Index:\
https://github.com/mpetri/FM-Index
 
Hierarchical FM-Index:\
https://github.com/DaehwanKimLab/hisat2
 
SSHash:\
https://daehwankimlab.github.io/hisat2/download/#version-hisat2-221 \
https://github.com/jermp/sshash
