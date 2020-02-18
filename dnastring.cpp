#include "dnastring.h"

using namespace std;

double DNAString::mean;
double DNAString::stdev;
double DNAString::varianceSum;
int DNAString::linecount;
int DNAString::sum;
double DNAString::probAA;
double DNAString::probAC;
double DNAString::probAG;
double DNAString::probAT;
double DNAString::probCA;
double DNAString::probCC;
double DNAString::probCG;
double DNAString::probCT;
double DNAString::probGA;
double DNAString::probGC;
double DNAString::probGG;
double DNAString::probGT;
double DNAString::probTA;
double DNAString::probTC;
double DNAString::probTG;
double DNAString::probTT;
int DNAString::numA;
int DNAString::numC;
int DNAString::numG;
int DNAString::numT;

DNAString::DNAString(string s, int sum, int linecount){
  this->s=s;
  length=s.size();
  DNAString::sum=sum;
  DNAString::linecount=linecount;
  mean = (double) sum/linecount;
}

DNAString::~DNAString(){
  cout << "object deleted" << endl;
}

//function methods

double DNAString::calculateTotalVariance(){
  return varianceSum/linecount;
}

double DNAString::calculateLineVariance(){
  return pow(length-mean,2);
}

//add line variance to total static variance
void DNAString::addVarianceSum(double variance){
  varianceSum+=variance;
}

double DNAString::calculateStdev(){

  return sqrt(calculateTotalVariance());
}

void DNAString::getLetters(){
  int count=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='A'){
      numA++;
    }else if(s[i]=='T'){
      numT++;
    }else if(s[i]=='G'){
      numG++;
    }else if(s[i]=='C'){
      numC++;
    }
  }
}

double DNAString::probA(){
  return (double)numA/sum;
}

double DNAString::probC(){
  return (double)numC/sum;
}

double DNAString::probG(){
  return (double)numG/sum;
}

double DNAString::probT(){
  return (double)numT/sum;
}

void DNAString::addBigrams(){
  for(int i=1;i<s.size();i+=2){
    if(s.substr(i-1,2)=="AA"){
      probAA++;
    }else if(s.substr(i-1,2)=="AC"){
      probAC++;
    }else if(s.substr(i-1,2)=="AG"){
      probAG++;
    }else if(s.substr(i-1,2)=="AT"){
      probAT++;
    }else if(s.substr(i-1,2)=="CA"){
      probCA++;
    }else if(s.substr(i-1,2)=="CC"){
      probCC++;
    }else if(s.substr(i-1,2)=="CG"){
      probCG++;
    }else if(s.substr(i-1,2)=="CT"){
      probCT++;
    }else if(s.substr(i-1,2)=="GA"){
      probGA++;
    }else if(s.substr(i-1,2)=="GC"){
      probGC++;
    }else if(s.substr(i-1,2)=="GT"){
      probGT++;
    }else if(s.substr(i-1,2)=="GG"){
      probGG++;
    }else if(s.substr(i-1,2)=="TA"){
      probTA++;
    }else if(s.substr(i-1,2)=="TC"){
      probTC++;
    }else if(s.substr(i-1,2)=="TG"){
      probTG++;
    }else if(s.substr(i-1,2)=="TT"){
      probTT++;
    }
  }
}


//getter methods

int DNAString::getLength(){
  return s.size();
}

double DNAString::getMean(){
  return mean;
}

string DNAString::getString(){
  return s;
}

double DNAString::getStdev(){
  return stdev;
}

int DNAString::getLineCount(){
  return linecount;
}

double DNAString::getVarianceSum(){
  return varianceSum;
}

void DNAString::calculateBiagrams(){
  probAA/=sum;
  probAC/=sum;
  probAG/=sum;
  probAT/=sum;
  probCA/=sum;
  probCC/=sum;
  probCG/=sum;
  probCT/=sum;
  probGA/=sum;
  probGC/=sum;
  probGG/=sum;
  probGT/=sum;
  probTA/=sum;
  probTC/=sum;
  probTG/=sum;
  probTT/=sum;
}

//setter methods

void DNAString::setMean(double mean){
  DNAString::mean=mean;
}

void DNAString::setStdev(double stdev){
  DNAString::stdev=stdev;
}

void DNAString::setLineCount(int linecount){
  DNAString::linecount=linecount;
}

void DNAString::setNum(int num){
  DNAString::numA=num;
  DNAString::numT=num;
  DNAString::numC=num;
  DNAString::numG=num;
}

void DNAString::setBigram(int num){
  DNAString::probAA = num;
  DNAString::probAC = num;
  DNAString::probAG = num;
  DNAString::probAT = num;
  DNAString::probCA = num;
  DNAString::probCC = num;
  DNAString::probCG = num;
  DNAString::probCT = num;
  DNAString::probGA = num;
  DNAString::probGC = num;
  DNAString::probGG = num;
  DNAString::probGT = num;
  DNAString::probTA = num;
  DNAString::probTC = num;
  DNAString::probTG = num;
  DNAString::probTT = num;
}

void DNAString::setVarianceSum(double varianceSum){
  DNAString::varianceSum=varianceSum;
}

void DNAString::setString(string s){
  this->s=s;
}

void DNAString::setLength(int length){
  this->length=length;
}
