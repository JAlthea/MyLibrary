using namespace std;

template <typename T>
void prints(initializer_list<T> e) {
    //vector<bool> => imple
    for (auto & o : e) {
        cout << o << ' ';
    }
    cout << '\n';
}

