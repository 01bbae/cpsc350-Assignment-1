#include "dnastring.h"

using namespace std;

double DNAString::mean;
double DNAString::stdev;
double DNAString::varianceSum;
int DNAString::linecount;

DNAString::DNAString(string s, double mean, int linecount){
  this->s=s;
  this->mean=mean;
  this->linecount=linecount;
}

DNAString::~DNAString(){
  cout << "object deleted" << endl;
}

//function methods

double DNAString::calculateVariance(){
  return sqrt(getLength()-mean);
}

void DNAString::addVarianceSum(double variance){
  varianceSum+=variance;
}

double DNAString::calculateStdev(){
  return sqrt(calculateVariance());
}


int DNAString::numA(){
  int count=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='A'){
      count++;
    }
  }
  return count;
}

int DNAString::numT(){
  int count=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='T'){
      count++;
    }
  }
  return count;
}

int DNAString::numC(){
  int count=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='C'){
      count++;
    }
  }
  return count;
}

int DNAString::numG(){
  int count=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='G'){
      count++;
    }
  }
  return count;
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

int DNAString::getLinecount(){
  return linecount;
}

double DNAString::getVarianceSum(){
  return varianceSum;
}



//setter methods


void DNAString::setMean(double mean){
  this->mean=mean;
}

void DNAString::setStdev(double stdev){
  this->stdev=stdev;
}

void DNAString::setLineCount(int linecount){
  this->linecount=linecount;
}

void DNAString::setVarianceSum(double varianceSum){
  this->varianceSum=varianceSum;
}

void DNAString::setString(string s){
  this->s=s;
}

void DNAString::setLength(int length){
  this->length=length;
}
