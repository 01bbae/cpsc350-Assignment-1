#include "dnastring.cpp"

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
      dna+=buffer;
      // DNAString* d = new DNAString(buffer);
      // cout << d->getString() << endl;
      // cout << d->getLength() << endl;
      // delete d;
      linecount++;
    }
    ifs.clear();
    ifs.seekg(0, ios::beg);

    while(ifs >> buffer){
      //toupper(buffer);
      DNAString* d = new DNAString(buffer , mean, linecount);
      cout << d->getString() << endl;
      cout << d->getLength() << endl;
      cout << d->calculateVariance() << endl;
      delete d;
    }
    //cout << dna << endl;
    mean=(double) dna.size()/linecount;
    //variance= mean
    cout << "sum: " << dna.size() << endl;
    cout << "mean: " << mean << endl;


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
