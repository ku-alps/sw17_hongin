#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> a;
    int b[100000];
    
    cin >> n;
    
    int temp;
    for (int i = 0 ; i < n ; i++){
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0 ; i < n ; i++)
        cin >> b[i];
    int target;
    for (target = 0; target < n - 2; target++){
        
//        for (int i = 0 ; i < a.size(); i++)
//            cout << a[i] << "\t" ;
//        cout << endl;
        
        int index;
        for (index = 0 ; index < a.size() ; index++)
            if (a[index] == b[target]) break;
        
        //cout << "Index : " << index <<endl ;
        if (index == a.size()+1) { cout << "Impossible" << endl; return 0; }
        
        a.erase(a.begin() + index);
        
        if (index % 2 == 1) {
            temp = a[1];
            a[1] = a[0];
            a[0] = temp;
        }
    }
    if (b[target]==a[0])
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
	return 0;
}
