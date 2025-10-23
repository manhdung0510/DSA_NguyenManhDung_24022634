#include <iostream>
#include "DefSymbolTable.h"

using namespace std;

int main(){
    SymbolTableLL st;

    st.put("apple", 10);
    st.put("banana", 20);
    st.put("apple", 99);

    cout << st.get("apple") << endl;
    cout << st.get("banana") << endl;
    cout << st.get("xyz") << endl;

    cout << "size: " << st.size() << endl;

    SymbolTableL s;

    s.put("A", 10);
    s.put("B", 20);
    s.put("C", 30);

    cout << s.get("A") << endl;
    cout << s.get("B") << endl;
    cout << s.get("X") << endl;

    cout << "size = " << s.size() << endl;

    return 0;
}

