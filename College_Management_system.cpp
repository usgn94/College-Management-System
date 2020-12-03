#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
#include<string.h>
#include<sstream>
#include <boost/algorithm/string.hpp>
using namespace std;
struct CseStudents{
   string RollNo;
   string StudentName;
}a[100];
struct Courses{
   string CourseID;
   string CourseName;
}b[10];
struct Grades{
  string RollNo;
  string CourseID;
  string Grade;
}c[1000];

int count1,count2,count3;

void show_CseStudents(){
  for(int i=0;i<count1;i++){
          cout<<a[i].RollNo<<"\t\t"<<a[i].StudentName;
          cout<<'\n';
        }
        cout<<count1<<"\n";
}
void Show_courses(){
  for(int i=0;i<count2;i++){
          cout<<b[i].CourseID<<"\t\t"<<b[i].CourseName;
          cout<<'\n';
        }
}
void show_grades(){
   for(int i=0;i<count3;i++){
          cout<<c[i].RollNo<<"\t\t"<<c[i].CourseID<<"\t\t"<<c[i].Grade;
          cout<<'\n';
        }
}

void Merge_cse(int p, int q,int r,string columnname)
{

    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    CseStudents L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=a[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=a[q+j+1];
    }
    i=0,j=0;
    if(columnname == "RollNo"){
       for(k=p;i<n1&&j<n2;k++)
      {
         if(L[i].RollNo<R[j].RollNo)
          {
            a[k]=L[i++];
          }
        else
          {
            a[k]=R[j++];
          }
      }
    }
    else if(columnname == "StudentName"){
      for(k=p;i<n1&&j<n2;k++)
      {
         if(L[i].StudentName < R[j].StudentName)
          {
            a[k]=L[i++];
          }
        else
          {
            a[k]=R[j++];
          }
      }
    }
    else{
      cout<<"PLEASE GIVE VALID INPUT..!!\n";
      return;
    }
    while(i<n1)
    {
        a[k++]=L[i++];
    }
    while(j<n2)
    {
        a[k++]=R[j++];
    }
}
void MergeSort_Csestudents(int p,int r,string columnname)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort_Csestudents(p,q,columnname);
        MergeSort_Csestudents(q+1,r,columnname);
        Merge_cse(p,q,r,columnname);
    }
}
void Merge_course(int p, int q,int r,string columnname)
{

    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    Courses L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=b[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=b[q+j+1];
    }
    i=0,j=0;
    if(columnname == "CourseID"){
       for(k=p;i<n1&&j<n2;k++)
      {
         if(L[i].CourseID<R[j].CourseID)
          {
            b[k]=L[i++];
          }
        else
          {
            b[k]=R[j++];
          }
      }
    }
    else if(columnname == "CourseName"){
      for(k=p;i<n1&&j<n2;k++)
      {
         if(L[i].CourseName < R[j].CourseName)
          {
            b[k]=L[i++];
          }
        else
          {
            b[k]=R[j++];
          }
      }
    }
    else{
      cout<<"PLEASE GIVE VALID INPUT..!!\n";
      return;
    }
    while(i<n1)
    {
        b[k++]=L[i++];
    }
    while(j<n2)
    {
        b[k++]=R[j++];
    }
}
void MergeSort_Courses(int p,int r,string columnname)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort_Courses(p,q,columnname);
        MergeSort_Courses(q+1,r,columnname);
        Merge_course(p,q,r,columnname);
    }
}
void Merge_grade(int p, int q,int r,string columnname)
{

    int n1,n2,i,j,k;
    n1=q-p+1;
    n2=r-q;
    Grades L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=c[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=c[q+j+1];
    }
    i=0,j=0;
    if(columnname == "RollNo"){
       for(k=p;i<n1&&j<n2;k++)
      {
         if(L[i].RollNo<R[j].RollNo)
          {
            c[k]=L[i++];
          }
        else
          {
            c[k]=R[j++];
          }
      }
    }
    else if(columnname == "CourseID"){
      for(k=p;i<n1&&j<n2;k++)
      {
         if(L[i].CourseID < R[j].CourseID)
          {
            c[k]=L[i++];
          }
        else
          {
            c[k]=R[j++];
          }
      }
    }
    else if(columnname == "Grade"){
      for(k=p;i<n1&&j<n2;k++)
      {
         if(L[i].Grade < R[j].Grade)
          {
            c[k]=L[i++];
          }
        else
          {
            c[k]=R[j++];
          }
      }
    }
    else{
       cout<<"PLEASE ENTER A VALID COMMAND...!!\n";
       return;
    }
    while(i<n1)
    {
        c[k++]=L[i++];
    }
    while(j<n2)
    {
        c[k++]=R[j++];
    }
}
void MergeSort_grades(int p,int r,string columnname)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort_grades(p,q,columnname);
        MergeSort_grades(q+1,r,columnname);
        Merge_grade(p,q,r,columnname);
    }
}

int binarySearch(int l, int r, string filename,string columnname,string value)
{
    if(r >= l){
        if (filename == "csestudents") {
        int mid = l + (r - l) / 2;
        if(columnname == "RollNo"){
            if (a[mid].RollNo == value)
            return mid;
            else if (a[mid].RollNo > value)
            return binarySearch( l, mid - 1, filename,columnname,value);
            else
            return binarySearch( mid + 1, r, filename,columnname,value);
        }
        else if(columnname == "StudentName"){
            if (a[mid].StudentName == value)
            return mid;
            else if (a[mid].StudentName > value)
            return binarySearch(l, mid - 1, filename,columnname,value);
            else
            return binarySearch( mid + 1, r, filename,columnname,value);
        }
        else{
       cout<<"PLEASE ENTER A VALID COMMAND...!!\n";
       return -1;
    }
      }

      if (filename == "courses") {
        int mid = l + (r - l) / 2;
        if(columnname == "CourseID"){
            if (b[mid].CourseID == value)
            return mid;
            else if (b[mid].CourseID > value)
            return binarySearch(l, mid - 1, filename,columnname,value);
            else
            return binarySearch(mid + 1, r, filename,columnname,value);
        }
        else if(columnname == "CourseName"){
            if (b[mid].CourseName == value)
            return mid;
            else if (b[mid].CourseName > value)
            return binarySearch( l, mid - 1, filename,columnname,value);
            else
            return binarySearch( mid + 1, r, filename,columnname,value);
        }
        else{
         cout<<"PLEASE ENTER A VALID COMMAND...!!\n";
          return -1;
        }
      }


    }

    return -1;
}
void removeSpaces(string &str)
{
    int n = str.length();
    int i = 0, j = -1;


    bool spaceFound = false;

    while (++j < n && str[j] == ' ');

    while (j < n)
    {
        if (str[j] != ' ')
        {
            str[i++] = str[j++];

            spaceFound = false;
        }
        else if (str[j++] == ' ')
        {

            if (!spaceFound)
            {
                str[i++] = ' ';
                spaceFound = true;
            }
        }
    }

    if (i <= 1)
        str.erase(str.begin() + i, str.end());
    else
        str.erase(str.begin() + i, str.end());
}

void show_file( string query){

   if(query == "csestudents")
        show_CseStudents();

   else if(query == "courses")
        Show_courses();
   else if(query == "grades")
         show_grades();
   else
      cout<<"Enter a Valid filename\n";

}
void show_file_sortedby(string filename , string columnname){

   if(filename == "csestudents"){
      MergeSort_Csestudents(1,count1-1,columnname);
      show_CseStudents();
   }
   else if(filename == "courses"){
       MergeSort_Courses(1,count2-1,columnname);
       Show_courses();
    }
    else if(filename == "grades")
    {
      MergeSort_grades(1,count3-1,columnname);
      show_grades();
    }
    else{
      cout<<"Enter a Valid filename\n";
    }

}
void show_file_with_columnname(string filename,string columnname,string value){
  int r ;
  int n;
  if(filename == "csestudents"){
    r = count1-1;
    MergeSort_Csestudents(1,count1-1,columnname);
    n = binarySearch(1,r,filename,columnname,value);
    //cout<<n<<endl;
    if(n <0){
      cout<<"THE INFO YOUR SEARCHING WITH GIVEN NAME IS NOT FOUND..!!\n";
      return;
    }
    cout<<a[0].RollNo<<"\t\t"<<a[0].StudentName<<endl;
    cout<<a[n].RollNo<<"\t\t"<<a[n].StudentName<<endl;
  }
  else if(filename == "courses"){
    r = count2-1;
    MergeSort_Courses(1,count2-1,columnname);
    n = binarySearch(1,r,filename,columnname,value);
    if(n <0){
      cout<<"THE INFO YOUR SEARCHING WITH GIVEN NAME IS NOT FOUND..!!\n";
      return;
    }
    cout<<b[0].CourseID<<"\t\t"<<b[0].CourseName<<endl;
    cout<<b[n].CourseID<<"\t\t"<<b[n].CourseName<<endl;
  }
  else{
    cout<<c[0].RollNo<<"\t\t"<<c[0].CourseID<<"\t\t"<<c[0].Grade<<"\n";
    //cout<<value<<" "<<columnname;
    bool found = false;
    if(columnname == "RollNo"){
      for(int i=1;i<count3;i++){
      if(c[i].RollNo == value){
       cout<<c[i].RollNo<<"\t\t";
       cout<<c[i].CourseID<<"\t\t";
       cout<<c[i].Grade<<"\n";
       found = true;
     }
   }
    }

    else if(columnname == "CourseID"){
      for(int i=1;i<count3;i++){
      if(c[i].CourseID == value){
       cout<<c[i].RollNo<<"\t\t";
       cout<<c[i].CourseID<<"\t\t";
       cout<<c[i].Grade<<"\n";
        found = true;
     }
   }
    }

    else if(columnname == "Grade"){
      for(int i=1;i<count3;i++){
      if(c[i].Grade == value){
       cout<<c[i].RollNo<<"\t\t";
       cout<<c[i].CourseID<<"\t\t";
       cout<<c[i].Grade<<"\n";
        found = true;
     }
   }
    }
    if(found == false){
      cout<<"THE INFO YOUR SEARCHING WITH GIVEN NAME IS NOT FOUND..!!\n";
    }
  }

}
void show_info_of_courseID(string ID){
   MergeSort_Csestudents(1,count1-1,"RollNo");
   cout<<"RollNo"<<"\t\t"<<"StudentName"<<"\t\t"<<"Grade"<<endl;
   int n;
   for(int i=1;i<count3;i++){
     if(c[i].CourseID == ID){
      n = binarySearch(1,count1-1,"csestudents","RollNo",c[i].RollNo);
      if(n>=0){
       cout<<c[i].RollNo<<"\t\t";
       cout<<a[n].StudentName<<"\t\t";
       cout<<c[i].Grade<<endl;
      }
     }
   }
}

vector<string> split_the_string(string str){
    string temp;
    vector<string> ans;
    int prev =-1;
    int N = str.size();
    for(int i=0;i<N;i++){

        if(str[i] == ' '){
            temp.assign(str,prev+1,i-prev-1);
            ans.push_back(temp);
            prev = i;
        }
        if(temp == "="){
          break;
        }
    }
    temp.assign(str,prev+1,N-prev-1);
    ans.push_back(temp);
    return ans;
}
int main()
{


ifstream file;
file.open("csestudents.txt");
if(file.is_open()){
  string line;
   for(int i=0;getline(file,line);i++)
   {
    stringstream ss(line);
    string a1,a2;
    getline(ss,a1,',');
    a[i].RollNo=(a1);
    getline(ss,a2,',');
    removeSpaces(a2);
    a[i].StudentName=(a2);
    count1++;

   }
}
file.close();

ifstream file1;
file1.open("courses.txt");
  if(file1.is_open()){
  string line;
   for(int i=0;getline(file1,line);i++)
   {
    stringstream ss(line);
    string b1,b2;
    getline(ss,b1,',');
    b[i].CourseID=(b1);
    getline(ss,b2,',');
    removeSpaces(b2);
    b[i].CourseName=(b2);
    count2++;

   }
}
file1.close();

ifstream file2;
file2.open("grades.txt");
  if(file2.is_open()){
  string line;
   for(int i=0;getline(file2,line);i++)
   {
    stringstream ss(line);
    string c1,c2,c3;
    getline(ss,c1,',');
    c[i].RollNo =(c1);
    getline(ss,c2,',');
    removeSpaces(c2);
    c[i].CourseID =(c2);
    getline(ss,c3,',');
    removeSpaces(c3);
     c[i].Grade = (c3);
    count3++;

   }
}
file2.close();


cout<<"Welcome to IIT Bhubaneswar!!"<<"\n\n";
while(1){
  string input;
  getline(cin,input);
  vector<string>query ;
  query = split_the_string(input);
  int n = query.size();
  if(n == 1){
  if(query[0]== "CLEAR"){
    system("clear");
  }
  if(query[0]=="QUIT"){
    cout<<"Thanks for visting our site...Keep visiting for latest updates..!"<<endl;
    return 0;
  }
}
else if(query[0] == "SHOW"){
  if(n==2){
    if(query[1] == "csestudents" || query[1] == "courses" || query[1]== "grades"){
      show_file(query[1]);
    }
    else{
      show_info_of_courseID(query[1]);
    }
  }

  if(n==4 && query[2] == "SORTBY"){
      show_file_sortedby(query[1] , query[3]);

  }
  if(n==6){
    show_file_with_columnname(query[1],query[3],query[5]);
  }

}
else{
  cout<<"PLEASE ENTER A VALID COMMAND!!"<<"\n";
}
}

return 0;

}
