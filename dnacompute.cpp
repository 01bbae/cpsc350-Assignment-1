#include "dnastring.cpp"

using namespace std;


int main(int charc, char** charv){
  ifstream ifs;
  ofstream ofs("BJBae.out", ofstream::app);
  //header of output file
  ofs << "BJ Bae" << endl;
  ofs << "Student ID: 2344182" << endl;

  string usrinput = "";
  while(usrinput!="exit"){

    //checks if command line params are correct
    if(charc!=2){
      cout << "Invalid Command Line Inputs" << endl;
      break;
    }
    //takes input from command line argument and creates fstreams
    string infile = charv[1];

    ifs.open(infile);

    //checks if a given file exists
    if(!ifs){
      cout << "Given file does not exist" << endl;
      break;
    }

    int linecount=0;
    int sum=0;
    double mean=0.0;
    string dna="";
    string buffer="";

    //counts lines in the given file
    while(ifs >> buffer){
      linecount++;
      dna+=buffer;
      cout << buffer <<endl;
    }

    //set input file stream back to the beginning of the file
    ifs.clear();
    ifs.seekg(0, ios::beg);

    sum=dna.size();
    mean = (double) sum/linecount;

    ofs << endl;
    ofs << "Sum: " << sum << endl;
    ofs << "Mean: " << mean << endl;

    while(ifs >> buffer){
      //make all letters uppercase
      for(int i=0;i<buffer.size();++i){
        buffer[i]=toupper(buffer[i]);
      }
      //create an instance of a class for every line
      DNAString* d = new DNAString(buffer, sum, linecount);
      cout << d->getString() << endl;
      ofs <<"String: " << d->getString() << endl;
      d->addBigrams();
      d->getLetters();
      cout << "Line Variance: " << d->calculateLineVariance() << endl;
      ofs << "Line Variance: " << d->calculateLineVariance() << endl;
      d->addVarianceSum(d->calculateLineVariance());
      delete d;
    }
    ofs << "Variance: "<< DNAString::calculateTotalVariance() << endl;
    DNAString::setStdev(DNAString::calculateStdev());
    DNAString::calculateBiagrams();
    ofs << "A: " << DNAString::probA() << endl;
    ofs << "C: " << DNAString::probC() << endl;
    ofs << "G: " << DNAString::probG() << endl;
    ofs << "T: " << DNAString::probT() << endl;
    ofs << "AA: " << DNAString::probAA << endl;
    ofs << "AC: " << DNAString::probAC << endl;
    ofs << "AG: " << DNAString::probAG << endl;
    ofs << "AT: " << DNAString::probAT << endl;
    ofs << "CA: " << DNAString::probCA << endl;
    ofs << "CC: " << DNAString::probCC << endl;
    ofs << "CG: " << DNAString::probCG << endl;
    ofs << "CT: " << DNAString::probCT << endl;
    ofs << "GA: " << DNAString::probGA << endl;
    ofs << "GC: " << DNAString::probGC << endl;
    ofs << "GG: " << DNAString::probGG << endl;
    ofs << "GT: " << DNAString::probGT << endl;
    ofs << "TA: " << DNAString::probTA << endl;
    ofs << "TC: " << DNAString::probTC << endl;
    ofs << "TG: " << DNAString::probTG << endl;
    ofs << "TT: " << DNAString::probTT << endl;
    cout << "Standard Deviation:" << DNAString::getStdev() << endl;
    ofs << "Standard Deviation:" << DNAString::getStdev() << endl;

    cout<< DNAString::probA()+DNAString::probC()+DNAString::probG()+DNAString::probT() <<endl;
    for(int i=0;i<1000;++i){
      double a = (double) rand()/ (RAND_MAX);
      double b = (double) rand()/ (RAND_MAX);
      double C=sqrt(-2*log(a))*cos(2*M_PI*b);
      double D =DNAString::getStdev()*C+mean;
      for(int j=0;j<D;++j){
        double r = rand() / double(RAND_MAX);
        if(r<=DNAString::probA()){
          ofs << "A";
        }else if(r>DNAString::probA()&&r <= DNAString::probA()+DNAString::probC()){
          ofs << "C";
        }else if(r>DNAString::probA()+DNAString::probC()&&r <= DNAString::probA()+DNAString::probC()+DNAString::probG()){
          ofs << "G";
        }else{
          ofs << "T";
        }
      }
    }
    DNAString::setVarianceSum(0.0);
    DNAString::setStdev(0.0);
    DNAString::setNum(0);
    DNAString::setBigram(0);

    cout << "Continue?" << endl;
    cin >> usrinput;

    ifs.close();
  }
  return 0;
}
