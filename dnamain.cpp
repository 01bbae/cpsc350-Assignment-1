#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(int charc, char** charv){
  string usrinput = "";
  while(usrinput!="exit"){

    //checks if command line params are correct
    if(charc!=2){
      cout << "Invalid Command Line Inputs" << endl;
      break;
    }
    string infile = charv[1];
    ifstream ifs;

    ifs.open(infile);

    //checks if a given file exists
    if(!ifs){
      cout << "Given file does not exist" << endl;
      break;
    }

    int linecount=0;
    double mean=0.0;
    double variance=0.0;
    string dna="";
    string buffer="";
    while(ifs >> buffer){
      //cout << buffer << endl;
      toupper(buffer);
      dna+=buffer;

      linecount++;
    }
    ifs.clear();

    DNAString* d;


    while(ifs >> buffer){

    }
    //cout << dna << endl;
    mean=(double) dna.size()/linecount;
    //variance= mean
    cout << "sum: " << dna.size() << endl;
    cout << "mean: " << mean << endl;

    int countA=0;
    int countT=0;
    int countC=0;
    int countG=0;

    for(int i=0; i<dna.size();++i){
      toupper(dna[i]);
      if(dna[i]=='A'){
        countA++;
      }else if(dna[i]=='C'){
        countC++;
      }else if(dna[i]=='T'){
        countT++;
      }else if(dna[i]=='G'){
        countG++;
      }
    }

    //cout << dna.size() << endl;
    // double meanA=(double)countA/dna.size();
    // double meanT=(double)countT/dna.size();
    // double meanC=(double)countC/dna.size();
    // double meanG=(double)countG/dna.size();

    // cout << "meanA: " << meanA << endl;
    // cout << "meanT: " << meanT << endl;
    // cout << "meanC: " << meanC << endl;
    // cout << "meanG: " << meanG << endl;



    cout << "Continue?" << endl;
    cin >> usrinput;

    ifs.close();
  }
  return 0;
}
