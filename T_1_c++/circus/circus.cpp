///////////////////////////////////////////////////////////////////////////////////////////
//
//       Author : Abdul Mateen
//       Email : abdul.mateen59@yahoo.com
//       Todo : -> Done -> Done -> Done -> Done -> Done
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <typeinfo>
#include <iterator>
#include "animals.h"
using namespace std;


void lexicographical(vector<animals*> objectlist){
   vector<animals*>::iterator itr1, itr2, itrB, itrE ;
   itrB = objectlist.begin();
   itrE = objectlist.end();

   for (itr1 = itrB ; itr1 < itrE; ++itr1)
      for (itr2 = itrB ; itr2 < itrE; ++itr2){
         bool result = lexicographical_compare((*itr1)->name.begin(), (*itr1)->name.end(), (*itr2)->name.begin(), (*itr2)->name.end());
            if (result == true)
               iter_swap(*itr1, *itr2);
      }

   for(itr1 = itrB ; itr1!=itrE ; ++itr1)
      cout<<(*itr1)->name << "  ";
}

void ageSort(vector<animals*> objectlist){
   vector<animals*>::iterator itr1, itr2, itrB, itrE ;
   itrB = objectlist.begin();
   itrE = objectlist.end();

   for (itr1 = itrB ; itr1 < itrE; ++itr1)
      for(itr2 = itrB ; itr2 < itrE ; ++itr2){
            if((*itr1)->age < (*itr2)->age ){
               swap(*itr1, *itr2);
            }
         }
   for(itr1 = itrB ; itr1!=itrE ; ++itr1)
      cout<<(*itr1)->name << "  ";
}

bool mySort(animals *a, animals *b){
   if(a->get_rideable() == b->get_rideable() && a->get_strips() == b->get_strips())
      return true;
   else if(a->get_rideable() != b->get_rideable() && a->get_strips() == b->get_strips())
      return true;
   else if(a->get_rideable() == b->get_rideable() && a->get_strips() != b->get_strips())
      return true;
   else if(a->get_rideable() != b->get_rideable() && a->get_strips() != b->get_strips())
      return true;
   EXIT_FAILURE;
}


bool mySort1(animals *a, animals *b){
   if(a->get_rideable() == b->get_rideable() && a->get_strips() != b->get_strips())
      return true;
   else if(a->get_rideable() != b->get_rideable() && a->get_strips() == b->get_strips())
      return true;
   else if(a->get_rideable() == b->get_rideable() && a->get_strips() == b->get_strips())
      return true;
   else if(a->get_rideable() != b->get_rideable() && a->get_strips() != b->get_strips())
      return true;
   EXIT_FAILURE;
}


int main(){
   vector<animals*> objectlist;
   //list<animals*> objectlist;

   objectlist.push_back(new horse(true, "Hanni" , 7));
   objectlist.push_back(new horse(true, "Holger" , 3));
   objectlist.push_back(new horse(true, "Hennes" , 2));
   objectlist.push_back(new horse(true, "Hans" , 11));
   objectlist.push_back(new zebra(true, "Alex" , 3));
   objectlist.push_back(new zebra(true, "Anke" , 8));
   objectlist.push_back(new zebra(true, "Ann" , 5));
   objectlist.push_back(new zebroid(true, true ,"Otto" , 2));
   objectlist.push_back(new zebroid(true, true ,"Olga" , 2));

   cout<<"Stage 1 : ";
   lexicographical(objectlist);
   cout<<endl<<"Stage 2 : ";
   ageSort(objectlist);
   cout<<endl<<"Stage 3 : " ;
   
   sort(objectlist.begin() , objectlist.begin() + objectlist.size() , mySort);                                              //could also be possible with overloading Operator
   for(unsigned int i = 0 ; i < objectlist.size() ; i++){
        cout<<objectlist.at(i) -> get_name() <<"  ";
   }

   cout<<endl<<"Stage 4 : ";

   sort(objectlist.begin() , objectlist.begin() + objectlist.size(), mySort1);
   for(unsigned int i = 0 ; i < objectlist.size() ; i++){
        cout<<objectlist.at(i) -> get_name() <<"  " ;
   }
   cout<<endl;
   return 0;
}