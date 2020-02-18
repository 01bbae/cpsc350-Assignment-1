#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class DNAString{
public:
  DNAString(string s, int sum, int linecount);
  ~DNAString();

  //function methods
  double calculateTotalVariance();
  double calculateLineVariance();
  void addVarianceSum(double variance);
  double calculateStdev();
  double calculateMean();
  int numA();
  int numC();
  int numG();
  int numT();
  // double probA();
  // double probC();
  // double probG();
  // double probT();
  //include biagram prob


  //getter methods
  int getLength();
  double getMean();
  string getString();
  double getStdev();
  int getLinecount();
  double getVarianceSum();

  //setter methods
  void setMean(double mean);
  void setStdev(double stdev);
  void setLineCount(int linecount);
  void setVarianceSum(double varianceSum);
  void setString(string s);
  void setLength(int length);

private:
  string s;
  int length;

  //static variables
  static int sum;
  static double mean;
  static double stdev;
  static double varianceSum;
  static int linecount;
};
