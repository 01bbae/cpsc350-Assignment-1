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
    int sum=0;
    double mean=0.0;
    double variance=0.0;
    string dna="";
    string buffer="";
    while(ifs >> buffer){
      linecount++;
      dna+=buffer;
      cout << buffer <<endl;
    }
    //set input file stream back to the beginning of the file
    ifs.clear();
    ifs.seekg(0, ios::beg);

    int count=0;
    sum=dna.size();
    //make this unscuffed
    while(linecount>count){
      ifs >> buffer;
      for(int i=0;i<buffer.size();++i){
        buffer[i]=toupper(buffer[i]);
      }
      DNAString* d = new DNAString(buffer, sum, linecount);
      cout << d->getString() << endl;
      cout << "line variance: " << d->calculateLineVariance() << endl;
      d->addVarianceSum(d->calculateLineVariance());
      if(count==linecount-1){
        cout << "Stdev: " << d->calculateStdev() << endl;
      }
      count++;
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
