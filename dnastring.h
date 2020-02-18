#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class DNAString{
public:
  DNAString(string s, int sum, int linecount);
  ~DNAString();

  //variables
  static double probAA;
  static double probAC;
  static double probAG;
  static double probAT;
  static double probCA;
  static double probCC;
  static double probCG;
  static double probCT;
  static double probGA;
  static double probGC;
  static double probGG;
  static double probGT;
  static double probTA;
  static double probTC;
  static double probTG;
  static double probTT;
  //function methods
  double static calculateTotalVariance();
  double calculateLineVariance();
  void addVarianceSum(double variance);
  double static calculateStdev();
  void getLetters();
  double static probA();
  double static probC();
  double static probG();
  double static probT();
  //include biagram prob
  void addBigrams();

  //getter methods
  int getLength();
  double static getMean();
  string getString();
  double static getStdev();
  int static getLineCount();
  double getVarianceSum();
  void static calculateBiagrams();

  //setter methods
  void static setMean(double mean);
  void static setStdev(double stdev);
  void static setLineCount(int linecount);
  void static setVarianceSum(double varianceSum);
  void setString(string s);
  void setLength(int length);
  void static setNum(int num);
  void static setBigram(int num);

private:
  string s;
  int length;

  //static variables
  static int sum;
  static double mean;
  static double stdev;
  static double varianceSum;
  static int linecount;
  static int numA;
  static int numC;
  static int numG;
  static int numT;
};
