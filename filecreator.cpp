#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int main(int argc, char const *argv[]) {
  ofstream ofs;
  ofs.open("data.txt");
  for(int i=0;i<10;++i){
    string s="";
    for(int j=0;j<rand()%10+1;++j){
      int random = rand()%8;
      if(random==0){
        s+="A";
      }else if(random==1){
        s+="T";
      }else if(random==2){
        s+="C";
      }else if(random==3){
        s+="G";
      }else if(random==4){
        s+="a";
      }else if(random==5){
        s+="t";
      }else if(random==6){
        s+="c";
      }else if(random==7){
        s+="g";
      }
    }
    ofs << s << endl;
  }
  ofs.close();
  return 0;
}
