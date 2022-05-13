all:
	g++ -std=c++11 -I /usr/local/include -L /usr/local/lib src/rank_select_fm-index.cpp -lsdsl -ldivsufsort -ldivsufsort64 -o out/rank-select-fm-index-binary
	g++ -std=c++11 -I /usr/local/include -L /usr/local/lib src/rank_select_hisat2.cpp -lsdsl -ldivsufsort -ldivsufsort64 -o out/rank-select-hisat2-binary