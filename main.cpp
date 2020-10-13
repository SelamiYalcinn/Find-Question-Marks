#include <iostream>
#include <string>
#define asize(a) (sizeof(a)/sizeof(*a))
#define range   10//You have to change number of sum
#define numEl   3//This is question marks number
#define cstSize 100//sizeof Ar member
using namespace std;

static const string nums="0123456789";//const nums Array

struct Ar//For location and number of num
{
  int m_arLoc[cstSize]{};
  int m_arNum[cstSize]{};
  int m_sizeAr{};
};

bool NumberOfQ(string str)//Calculate number of question marks is ok?
{
  int cnt{};
  auto idx=str.find("?",0);
  while(idx!=string::npos)
  {
    ++cnt;
    idx=str.find("?",idx+1);
  }
  if(cnt==numEl)
    return true;

  return false;
}

bool TwoThem(Ar cx,string str)//Div to array 
{
  int len{},min{},i{};
  string tmp{};
  for(int i=0;i<cx.m_sizeAr-1;++i)
  {
    len=cx.m_arNum[i]+cx.m_arNum[i+1];
    if(len==range)
    {
      min=abs(cx.m_arLoc[i]-cx.m_arLoc[i+1]);
      tmp=str.substr(cx.m_arLoc[i]+1,min-1);
      if(NumberOfQ(tmp))
        return true;
    }

  }
  return false;
}

string Find(string str)
{
  Ar cx;
  int cnt{};
  for(int j=0;j<str.size();++j)
  {
    for(int i=0;i<nums.size();++i)
    {
      if(str[j]==nums[i])
      {
        cx.m_arLoc[cnt]=j;
        cx.m_arNum[cnt]=static_cast<int>(nums[i]-48);
        ++cnt;
      }
    }
  }
  cx.m_sizeAr=cnt;
  
  bool stat=TwoThem(cx,str);

  if(stat)
    str="true";
  else
    str="false";

  return str;

}

int main(void) { 
   
  
  cout << "input your text: <<;
  string getStr{};
  getline(cin,getStr);
  cout<<Find(getStr);
  return 0;
    
}
