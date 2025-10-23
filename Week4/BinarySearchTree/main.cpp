#include "DefBST.h"

int main() {
    BST t;

    t.put(25);
    t.put(40);
    t.put(5);
    t.put(15);
    t.put(20);
    t.put(30);
    t.put(10);
    t.put(35);

    cout << "Preorder: ";
    t.preorder();
    cout << endl;

    cout << "Postorder: ";
    t.postorder();
    cout << endl;

    cout << "Inorder: ";
    t.inorder();
    cout << endl;

    return 0;
}
