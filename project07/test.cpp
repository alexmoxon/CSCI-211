int main() {
    const int MAX = 100;
    Video *my_array_1[MAX] = {0}; //Memory allocated on Stack && pointers to NULL
    Video **my_array_2 = (Video**)malloc(MAX * sizeof(video*)); //On Heap, Unintialized pointers
    int idx; //^ deallocated by calling the free function
    for (idx = 0; idx < MAX; idx++) { //line 7: *(my_array_1 + idx) = new Video();
        my_array_1[idx] = new Video(); //Dyanmic allocation on Heap, w/ the delete operator
        my_array_2[idx] = &Video(); //Static allocation, memory stored on stack
    }
    idx = 0; //Constructor called 200 times, Desctuctor called 100 times
    if(my_array_1[idx++] != NULL || my_array_1[idx++] != NULL) {
        cout << "my_array_1 element " << idx << "is NOT NULL!" << endl;
    }//Program writes nothing to stdout
    else {//Program writes: my_array_1 element 2 is NULL! to stderr
        cerr << "my_array_1 element " << idx << " is NULL!" << endl;
    }
    return 0; //my_array_1[10]->print();
}