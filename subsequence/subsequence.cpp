#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>


void subseq() {

   std::map<int, int> numbers;
   int alphabet = 0;
   int count = 0;
   int all_numbers = 0;
   std::ifstream in("data.txt", std::ifstream::in);

   for (int i = 1; i <= 26; ++i)
      alphabet ^= i;
   
  while (!in.eof() && alphabet != 0)
   {
      int x;
      in >> x;
      
      if (all_numbers == 0) {
         ++all_numbers;
         if (x<26)
            count = -1;
      }

      else {
         if (numbers.find(x) != numbers.cend())
         {
            numbers[x]++;
            count++;
         }
         else
         {
            numbers[x] = 1;
            count++;
            alphabet ^= x;
         }
      }
      
      
   }
   in.close();

   if (numbers.size() < 26)
      count = -1;

   if (count < 0)
      std::cout << "NONE";
   else 
      std::cout << count << std::endl;

   bool repetitions = false;
   all_numbers = 0;
   int repetitions_count = count;
   std::ifstream fin("data.txt", std::ifstream::in);
   while (!fin.eof() && repetitions == false)
   {
      int x;
      fin >> x;

      if (all_numbers == 0) {
         ++all_numbers;
      }
      else {
         if (numbers.find(x) != numbers.cend())
         {
           if (numbers[x] > 1) {
               numbers[x]--;
               repetitions_count--;
           }
           else{
              repetitions = true;
           }
            
         }
      }
   }
   in.close();
   std::cout << repetitions_count;
}

int main()
{
   subseq();   
}
