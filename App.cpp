#include <iostream>
#include <cassert>

#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedMultiMap.h"
#include "SMMIterator.h"

typedef int TKey;
typedef int TValue;
//bool relationt(TKey cheie1, TKey cheie2) {
//    if (cheie1 <= cheie2) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}

int main(){
//
//    SortedMultiMap smm = SortedMultiMap(relationt);
//    assert(smm.size() == 0);
//    cout << "1" << endl;
//    assert(smm.isEmpty());
//    cout << "2" << endl;
//    smm.add(1,2);
//    cout << "3" << endl;
//    smm.add(1,3);
//    //smm.show();
//    cout << "4" << endl;
//    assert(smm.size() == 2);
//    cout << "5" << endl;
//    assert(!smm.isEmpty());
//    cout << "6" << endl;
//    vector<TValue> v= smm.search(1);
//    assert(v.size()==2);
//    cout << "7" << endl;
//    //smm.show();
//    v= smm.search(3);
//    assert(v.size()==0);
//    cout << "8" << endl;
//    SMMIterator it = smm.iterator();
//    it.first();
//    while (it.valid()){
//        TElem e = it.getCurrent();
//        it.next();
//    }
//    cout << "9" << endl;
//    assert(smm.remove(1, 2) == true);
//    assert(smm.remove(1, 3) == true);
//    assert(smm.remove(2, 1) == false);
//    assert(smm.isEmpty());
//    cout << "10" << endl;

   testAll();
   cout << "Finished ShortTest" << endl;
   testAllExtended();

    std::cout<<"Finished SMM Tests!"<<std::endl;
	system("pause");
}
