#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//local files
#include "PreProcess.cpp"
#include "PorterStemmer.cpp"
#include "CosineSimilarity.cpp"
#include "SentenceRank.cpp"
#include "Output.cpp"
#include "ReadData.cpp"
#include "SaveState.cpp"
#include "RemoveStopWords.cpp"

int main(int argc, char** argv){
	//read, write addresses
	string input_address = argv[1];
	string output_address = argv[2];
	
	//read input file
	vector<string> v = input(input_address);

	//copy of the original file
	vector<string> file_copy = v;
	
	//pre-processing
	preProcess(v);
	
	//remove stop words
	removeStopWords(v);
	saveState(v, "swordsremoved.txt");
	
	//stemming
	PorterStemmer();
	v = input("porter_output.txt");

	//adjacency matrix calculation using cosine similarity
	vector<vector<double> > L = SentenceSimilarity(v);
	
	//number of sentences in output
	int T = ceil(sqrt(v.size()));
	// cout<<T<<endl<<endl;
	
	//final indices
	vector<unsigned int> final_indices = RankSentences(L, v.size(), T);
	
	//extract final indices form original file and save them
	output(file_copy, final_indices, output_address);

	return 0;
}